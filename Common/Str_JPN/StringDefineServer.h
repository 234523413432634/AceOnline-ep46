
// 2005-04-28 by cmkwon

#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_




///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "�-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre Server�I"
	#define STRERR_S_ATUMEXE_0003 "����������-ĂɎ��s���܂����B\r\n��-т��Ĳݽ�-ق��Ă��������B\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error:%s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "�޳��-�޻-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMEXE_0007 "�޳��-��̧�ق̃T�C�Y���s���ł��B"
	#define STRERR_S_ATUMEXE_0008 "������-�̧�ق��޳��-�ނł��܂���B"
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "̧�ق�������܂���B"
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "update completed"
	#define STRMSG_S_ATUMLAUNCHER_0001 "�-��-��I�����Ă��������B"
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "deleting files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "update completed(%s->%s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "���ş�ّI��"
	#define STRMSG_S_ATUMLAUNCHER_0007 "���s��-�g�I��"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading is canceled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "updating to v%s-%s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Getting File Information %s"
	#define STRMSG_S_ATUMLAUNCHER_0014 "VTCGuard updating"				// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����E
	#define STRMSG_S_ATUMLAUNCHER_0015 "VTCGuard update completed"		// 2012-02-09 by hskim, ��Ʈ�� X-Trap -> VTC ����� ����E
	
	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "�F�ػ-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0005 "�-��-�ڑ��Ɏ��s���܂����B"
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "�N���C�A���g���ēx�޳��-�ނ��Ă��������B\nURL: http://space.mgame.com/\n�ŐV��-�ޮ�:"
	#define STRERR_S_ATUMLAUNCHER_0009 "����������-ĂɎ��s���܂����B\r\n�N���C�A���g���Ĳݽ�-ق����Ă��������B\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "�S�Ă̻-��-���񊈐���Ԃł��B"
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s�����e�i���X���c"
	#define STRERR_S_ATUMLAUNCHER_0012 "�S�ẴT-�o�������e�i���X���ł��B���΂炭��ɐڑ����Ă��������B"
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from%s[%s]\r\n"
// 2006-08-24 by cmkwon, Change to STRMSG_060824_0000
//	#define STRERR_S_ATUMLAUNCHER_0014 "�Ԉ���Ă���ID�ł��A�߽�-�޴�-\n\n* ���݂���-�ý�?�A�J�E���g�����L���Ă���-��-�݂̂����O�C���ł��܂��B"
	#define STRERR_S_ATUMLAUNCHER_0015 "۸޲ݴ�-"
	#define STRERR_S_ATUMLAUNCHER_0016 "ID������"
	#define STRERR_S_ATUMLAUNCHER_0017 "�d�����O�C��"
	#define STRERR_S_ATUMLAUNCHER_0018 "�-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0019 "�-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0020 "�-�޽���ꎞ�I�ɒ��f���ꂢ�܂��B\n\n���΂炭��ɐڑ����Ă��������B"
	#define STRERR_S_ATUMLAUNCHER_0021 "���G���Ă��邽�߃��O�C���ł��܂���B\n\n���΂炭��ɐڑ����Ă��������B"

	
	#define STRERR_S_ATUMLAUNCHER_0022 "���̃A�J�E���g�̓u���b�N����Ă��܂��B\n����:%s\n\n�s���ȏꍇ�A����-���-�ɖ₢���킹�Ă��������B"
	#define STRERR_S_ATUMLAUNCHER_0023 "�ײ�����-�ޮ݂��قȂ�܂��B\n\n�N���C�A���g���ēx�޳��-�ނ��Ă��������B"
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR:%s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "�޳��-�޻-��-�ɐڑ��ł��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0026 "�޳��-��̧��(%s)�̃T�C�Y���s���ł��B"
	#define STRERR_S_ATUMLAUNCHER_0027 "�޳��-��̧�ق̃T�C�Y���s���ł��B"
	#define STRERR_S_ATUMLAUNCHER_0028 "������-�̧�ق��޳��-�ނł��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0029 "������-�̧�ق����݂��܂���B"
	#define STRERR_S_ATUMLAUNCHER_0030 "�-��-����ݽ���ł��B���΂炭��ɐڑ����Ă��������B"
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "̧�ق�������܂���B"
	#define STRERR_S_ATUMLAUNCHER_0034 "��-�g��������܂���B"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type:%s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �̸� û�ҳ⿡�� ����EǴ?���ӽð� ������ �������� ���Ͽ�, ����E�ð����� ���� ������ �Ұ����մϴ�.\n\n�ڼ��� ������ ���̽��¶��� ��̴���ͷ� ���ǹٶ��ϴ�."		// 2012-07-11 by hskim, ������E�˴ٿ�E
	#define STRMSG_S_ATUMLAUNCHER_0038 "������ �ٽ� ������ �ֽʽÿ�E\r\n\r\n������ ���������� �߻��Ǹ�E���̽��¶��� ��̴���ͷ� ���ǹٶ��ϴ�."		// 2012-07-11 by hskim, ������E�˴ٿ�E


	#define STRMSG_S_050506		"\'%s\'�l�͌��݃A�J�E���g�u���b�N����Ă��܂��B\n���R:%s\n����:%s?%s\n\n�s���ȏꍇ�́A����-���-�ɖ₢���킹�Ă��������B"
	#define STRMSG_S_050930		"�N���C�A���g���ēx�޳��-�ނ��Ă��������B\nURL:%s\n�ŐV��-�ޮ�"
// 2_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "�j"
//	#define STRMSG_S_SCADMINTOOL_0001 "��"
//	#define STRMSG_S_SCADMINTOOL_0002 "%d�N�A%d��"
//	#define STRMSG_S_SCADMINTOOL_0003 "�{���ɃA�J�E���g����ύX���܂����H "
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10))+'��'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) +'�擾�A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
//	#define STRMSG_S_SCADMINTOOL_0006 "''''+l.PeerCharacterName+'''��'+ CAST(l.ChangeCount AS VARCHAR(10))+'�n���A'+CAST(l.CurrentCount AS VARCHAR(10)) +'��'"
//	#define STRMSG_S_SCADMINTOOL_0007 "''''+l.PeerCharacterName+'''����'+CAST(l.ChangeCount AS VARCHAR(10))+'���炤�A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
//	#define STRMSG_S_SCADMINTOOL_0008 "CAST(l.ChangeCount AS VARCHAR(10))+'�̂Ă�A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10))+'�w���A�c��SPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10))+'�̔��A�c��SPI:'+CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0012 "''''+l.PeerCharacterName+'''��'+CAST(l.ChangeCount AS VARCHAR(10))+'�ǉ�����A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0013 "''''+l.PeerCharacterName+'''��'+CAST(l.ChangeCount AS VARCHAR(10))+'�폜����A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0014 "CAST(l.ChangeCount AS VARCHAR(10))+'�ǉ��A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0015 "CAST(l.ChangeCount AS VARCHAR(10))+'�a����A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0016 "CAST(l.ChangeCount AS VARCHAR(10))+'�����o���A'+CAST(l.CurrentCount AS VARCHAR(10))+'��'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'��-ю���\'+dbo.atum_GetHMSFromS(l.PlayTime)+\'�A��\'+dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10))+'->'+CAST(l.Param2 AS VARCHAR(10))+',��-ю���:'+dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15))+\'�����A��\'+CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "�Փ�"
//	#define STRMSG_S_SCADMINTOOL_0021 "�ݽ�-"
//	#define STRMSG_S_SCADMINTOOL_0022 "�M�A"
//	#define STRMSG_S_SCADMINTOOL_0023 "�����s��"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s�A�c���-��:%s"
	#define STRMSG_S_SCADMINTOOL_0025 "(�Ȃ�)"
//	#define STRMSG_S_SCADMINTOOL_0026 "��"
//	#define STRMSG_S_SCADMINTOOL_0027 "�Ȃ�"
//	#define STRMSG_S_SCADMINTOOL_0028 "�o�O�g�p�-��-"
	#define STRMSG_S_SCADMINTOOL_0029 "�A�J�E���g�u���b�N"
	#define STRMSG_S_SCADMINTOOL_0030 "������ۯ�"
//	#define STRMSG_S_SCADMINTOOL_0031 "�ڑ����O"
//	#define STRMSG_S_SCADMINTOOL_0032 "�-��-۸�"
//	#define STRMSG_S_SCADMINTOOL_0033 "����۸�"
	#define STRMSG_S_SCADMINTOOL_0034 "%s-%s�-��-"
	#define STRMSG_S_SCADMINTOOL_0035 "%s-%s�-��-�A%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "�A�J�E���g�u���b�N"
//	#define STRMSG_S_SCADMINTOOL_0037 "����"
//	#define STRMSG_S_SCADMINTOOL_0038 "�l"
	#define STRMSG_S_SCADMINTOOL_0039 "�A�J�E���g�u���b�N���������܂����H"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%d�b)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d�� %d�s"
	#define STRMSG_S_SCADMINTOOL_0042 "���̃A�J�E���g�̐ڑ���ؒf���ău���b�N���܂����H"
	#define STRMSG_S_SCADMINTOOL_0043 "%s����"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s%15s]���m�点:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "�-��-��:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s%15s]��M����ү�-��:%s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s%15s]��-�U-��:%4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s%15s]FieldServer state:%d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "�-��-�Ƃ̐ڑ����I�����܂����B\nSocket Name:%s\nIP:%s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "�Y���A�J�E���g����ǂݍ��߂܂���B"
	#define STRERR_S_SCADMINTOOL_0001 "�A�J�E���g���̕ύX�Ɏ��s���܂����B"
	#define STRERR_S_SCADMINTOOL_0002 "�߽�-�ނ���͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0003 "�߽�-�ނ��Ԉ���Ă��܂��B"
	#define STRERR_S_SCADMINTOOL_0004 "ID����͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server�����s���Ă��܂���B"
	#define STRERR_S_SCADMINTOOL_0006 "Can not connect to PreServer !!"
//	#define STRERR_S_SCADMINTOOL_0007 "�F�؂Ɏ��s���܂����B"			// 2006-04-11 by cmkwon, ?????
	#define STRERR_S_SCADMINTOOL_0008 "ERROR:�Y���v���g�R�������݂��܂���B"
	#define STRERR_S_SCADMINTOOL_0009 "ID����͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0010 "���R����͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0011 "�o���l�ݒ��-:Level%2d==>Exp(%.1I64f?%.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "�ő働�O���𒴉߂��܂����B\r\n\r\n�ő働�O���⌟���������C�����Ă��������B"
	#define STRERR_S_SCADMINTOOL_0013 "Database�ɐڑ��ł��܂���B"
	#define STRERR_S_SCADMINTOOL_0014 "�ڑ����s"
	#define STRERR_S_SCADMINTOOL_0015 "�ڑ�����"
	#define STRERR_S_SCADMINTOOL_0016 "������-Ē�"
	#define STRERR_S_SCADMINTOOL_0017 "���O�C������"
	#define STRERR_S_SCADMINTOOL_0018 "��׸�-�I��"
	#define STRERR_S_SCADMINTOOL_0019 "��-ђ�"
	#define STRERR_S_SCADMINTOOL_0020 "�s��"
	#define STRERR_S_SCADMINTOOL_0021 "Database%s(%s:%d)�ɐڑ��ł��܂���B"
	#define STRERR_S_SCADMINTOOL_0022 "���ђǉ����s"
	#define STRERR_S_SCADMINTOOL_0023 "�u���b�N�A�J�E���g��������܂���ł����B"
	#define STRERR_S_SCADMINTOOL_0024 "�C���̂��ߊY���A�J�E���g�̐ڑ���ؒf���A�A�J�E���g���u���b�N���Ă��������I"
	#define STRERR_S_SCADMINTOOL_0025 "SPI�͒ǉ��ł��܂���B"
	#define STRERR_S_SCADMINTOOL_0026 "�I���������т͊��ɑ��݂��Ă��܂��B�����C�����Ă��������B"
	#define STRERR_S_SCADMINTOOL_0027 "���ь�����-"
	#define STRERR_S_SCADMINTOOL_0028 "��׸�-�����L���Ă���SPI�͍폜�ł��܂���B"
	#define STRERR_S_SCADMINTOOL_0029 "���т��폜���܂����H"
	#define STRERR_S_SCADMINTOOL_0030 "���т̍폜�Ɏ��s���܂����B"
	#define STRERR_S_SCADMINTOOL_0031 "���т̏C���Ɏ��s���܂����B"
	#define STRERR_S_SCADMINTOOL_0032 "�A�J�E���g����͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0033 "�A�J�E���g�����݂��܂���B(�A�J�E���g�u���b�N�ݒ�͉�?)"
	#define STRERR_S_SCADMINTOOL_0034 "�A�J�E���g�܂��ͷ�׸�-�����݂��Ă��܂���B"
	#define STRERR_S_SCADMINTOOL_0035 "��׸�-���Ɖ��-�ł��B"
	#define STRERR_S_SCADMINTOOL_0036 "�Y����׸�-���݂��Ă��܂���B"
	#define STRERR_S_SCADMINTOOL_0037 "��׸�-������-Ĵ�-�ł��B"
	#define STRERR_S_SCADMINTOOL_0038 "��׸�-���̱�����-Ăɐ������܂����B"
	#define STRERR_S_SCADMINTOOL_0039 "���т�I�����Ă��������B"
	#define STRERR_S_SCADMINTOOL_0040 "���ь���I�����Ă��������B"
	#define STRERR_S_SCADMINTOOL_0041 "�Y�����т�5�ȉ��̂ݍ쐬�ł��܂��B"
	#define STRERR_S_SCADMINTOOL_0042 "ү�-�ނ���͂��Ă��������B"
	#define STRERR_S_SCADMINTOOL_0043 "���m�点�𑗐M�ł��܂���B"
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server�����s����Ă��܂���B"
	#define STRERR_S_SCADMINTOOL_0046 "Field Server�����s����Ă��܂���B"
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, ��Ʈ�� - ����� ŁE��Ʈ�� ��ɿ��� �翁EǴ� MSG
	#define STRERR_S_SCADMINTOOL_0048 "��Ʈ�ʿ� ������ ���� ������ �Դϴ�.\n������ ������ ��Ʈ�� �Ӽ�â���� ������ �����մϴ�."
	#define STRERR_S_SCADMINTOOL_0049 "��Ʈ�ʼӼ� ������� Log������ ���� �Ǿ����ϴ�.\r\n(��Ʈ�� �Ӽ� ������ �Ϸ��, Log�� ����E����.)"
	#define STRERR_S_SCADMINTOOL_0050 "��Ʈ�� ���� �ε��� ���� �Ǿ����ϴ�"
	#define STRERR_S_SCADMINTOOL_0051 "�������� ���� ������ ������ ���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0052 "������ ���� �������� ���̵�E�ɼ� ����E?���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0053 "��Ʈ�� ���� �������� ������ ���� �Ǿ����ϴ�."
	#define STRERR_S_SCADMINTOOL_0054 "��Ʈ�� ���� ������Ʈ�� ���� �Ǿ����ϴ�"
	#define STRERR_S_SCADMINTOOL_0055 "��Ʈ�ʷ��� ���� �ε��� ���еǾ����ϴ�"

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ��۵������߰�, ��æƮ���������ű��
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ��۵������߰�, ��æƮ���������ű��. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "�A�J�E���gID"
//	#define STRMSG_S_SCAT_COLNAME_0001 "����"
//	#define STRMSG_S_SCAT_COLNAME_0002 "�O��"
//	#define STRMSG_S_SCAT_COLNAME_0003 "�J�n��"
//	#define STRMSG_S_SCAT_COLNAME_0004 "�I����"
//	#define STRMSG_S_SCAT_COLNAME_0005 "������"
//	#define STRMSG_S_SCAT_COLNAME_0006 "�������R"
//	#define STRMSG_S_SCAT_COLNAME_0007 "����"
//	#define STRMSG_S_SCAT_COLNAME_0008 "۸�����"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "�-��-��"
//	#define STRMSG_S_SCAT_COLNAME_0011 "��׸�-�-�"
//	#define STRMSG_S_SCAT_COLNAME_0012 "�ʒu"
//	#define STRMSG_S_SCAT_COLNAME_0013 "���e"
//	#define STRMSG_S_SCAT_COLNAME_0014 "����"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "�ŗL�ԍ�"
//	#define STRMSG_S_SCAT_COLNAME_0017 "���O"
//	#define STRMSG_S_SCAT_COLNAME_0018 "���єԍ�"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "����"
//	#define STRMSG_S_SCAT_COLNAME_0022 "��"
//	#define STRMSG_S_SCAT_COLNAME_0023 "�ϋv�x"
//	#define STRMSG_S_SCAT_COLNAME_0024 "�쐬����"
	#define STRMSG_S_SCAT_COLNAME_0025 "������"
//	#define STRMSG_S_SCAT_COLNAME_0026 "�q��"
//	#define STRMSG_S_SCAT_COLNAME_0027 "�I-�N�V����"
//	#define STRMSG_S_SCAT_COLNAME_0028 "ϯ��"
//	#define STRMSG_S_SCAT_COLNAME_0029 "���W"
//	#define STRMSG_S_SCAT_COLNAME_0030 "����"
//	#define STRMSG_S_SCAT_COLNAME_0031 "�푰"
//	#define STRMSG_S_SCAT_COLNAME_0032 "����"
//	#define STRMSG_S_SCAT_COLNAME_0033 "���j�b�g���"
//	#define STRMSG_S_SCAT_COLNAME_0034 "���x��"
//	#define STRMSG_S_SCAT_COLNAME_0035 "�ō����x��"
//	#define STRMSG_S_SCAT_COLNAME_0036 "�o���l"
//	#define STRMSG_S_SCAT_COLNAME_0037 "���������o���l"
//	#define STRMSG_S_SCAT_COLNAME_0038 "�������z��-������"
//	#define STRMSG_S_SCAT_COLNAME_0039 "�U���p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0040 "�h��p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0041 "�R���p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0042 "���_�p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0043 "�V-���h�p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0044 "����p-�g"
//	#define STRMSG_S_SCAT_COLNAME_0045 "�������c"
//	#define STRMSG_S_SCAT_COLNAME_0046 "����"
//	#define STRMSG_S_SCAT_COLNAME_0047 "�g��"
//	#define STRMSG_S_SCAT_COLNAME_0048 "���ڑ�����"
//	#define STRMSG_S_SCAT_COLNAME_0049 "�쐬����"
//	#define STRMSG_S_SCAT_COLNAME_0050 "�ŏI�ڑ�����"
//	#define STRMSG_S_SCAT_COLNAME_0051 "���"
//	#define STRMSG_S_SCAT_COLNAME_0052 "�S��"
	#define STRMSG_S_SCAT_COLNAME_0053 "�-�������(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0054 "�o���J����(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0055 "�f���A�����X�g��(1-1?)" // 2005-08-01 by hblee : ????? -> ??���X�g? �ύX.
	#define STRMSG_S_SCAT_COLNAME_0056 "�L���m����(1-1?)"
	#define STRMSG_S_SCAT_COLNAME_0057 "���C�t����(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0058 "�K�g�����O��(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0059 "����-��(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Ͻ��ײ̗�(1-2?)"
	#define STRMSG_S_SCAT_COLNAME_0061 "���P�b�g��(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0062 "л�ٗ�(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0063 "�o���h����(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0064 "ϲݗ�(2-1?)"
	#define STRMSG_S_SCAT_COLNAME_0065 "�-��ޗ�(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0066 "���-��(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0067 "�߸�-��(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0068 "�f�R�C��(2-2?)"
	#define STRMSG_S_SCAT_COLNAME_0069 "�h���"
	#define STRMSG_S_SCAT_COLNAME_0070 "�⏕������"
	#define STRMSG_S_SCAT_COLNAME_0071 "��ٷ�-��"
	#define STRMSG_S_SCAT_COLNAME_0072 "������"
	#define STRMSG_S_SCAT_COLNAME_0073 "�-�ޗ�"
	#define STRMSG_S_SCAT_COLNAME_0074 "�����ė�"
	#define STRMSG_S_SCAT_COLNAME_0075 "�ݸ��"
	#define STRMSG_S_SCAT_COLNAME_0076 "�e�ۗ�"
	#define STRMSG_S_SCAT_COLNAME_0077 "Я��ݗp"
	#define STRMSG_S_SCAT_COLNAME_0078 "�-��-��"
	#define STRMSG_S_SCAT_COLNAME_0079 "���߭-�-��"
	#define STRMSG_S_SCAT_COLNAME_0080 "�ެ���ٶ-�ޗ�"
	#define STRMSG_S_SCAT_COLNAME_0081 "�����Ĕj��h�~��"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "��׽�-��"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "�-ٶ�ݗ�"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "�S�̱���"
//	#define STRMSG_S_SCAT_COLNAME_0082 "�S�̻-��-"
//	#define STRMSG_S_SCAT_COLNAME_0083 "�-��-��"
//	#define STRMSG_S_SCAT_COLNAME_0084 "�-��-���"
//	#define STRMSG_S_SCAT_COLNAME_0085 "�-��-IP�APort"
//	#define STRMSG_S_SCAT_COLNAME_0086 "�����-��-��"
//	#define STRMSG_S_SCAT_COLNAME_0087 "�-��-���"
//	#define STRMSG_S_SCAT_COLNAME_0088 "���-�߻-��-"
//	#define STRMSG_S_SCAT_COLNAME_0089 "̨-��޻-��-"
//	#define STRMSG_S_SCAT_COLNAME_0090 "�s��"
//	#define STRMSG_S_SCAT_COLNAME_0091 "���s���s"
//	#define STRMSG_S_SCAT_COLNAME_0092 "����"
//	#define STRMSG_S_SCAT_COLNAME_0093 "�񐳏�"
	#define STRMSG_S_SCAT_COLNAME_0094 "�^�c��"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10))+'��, Param1:'+CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////	
	
	
///////////////////////////////////////////////////////////////////////////////	
// 4	
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "���ߌꃊ�X�g\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "-----�o�b�N�A�b�v�����A�J�E���g���X�g ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "�A�J�E���g:\'%s\'�A�ݒ�PW:\'%s\'�A�Վ�PW:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "�A�J�E���g:\'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0004 "������-ėpVersion�������Ă���̫��ނ�I�����Ă�������"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "̧�ق̍쐬�ɐ������܂����B\r\n\r\nDB ���:%s(%d)�A%s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d-����)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d-�񊈐�)%3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "�T-�o�f-�^�̃���-�h�ɐ������܂����B"
//	#define STRMSG_S_SCMONITOR_0011 "�T-�r�X��Ԃ̔��f�ɐ������܂����B"
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d-����)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d-�񊈐�)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "�t��-�T-�o�T-�r�X����?���܂����B"
//	#define STRMSG_S_SCMONITOR_0017 "�t��-�T-�o�T-�r�X���J�n���܂����B"
//	#define STRMSG_S_SCMONITOR_0018 "̨-��޻-��-�����s����Ă��܂���B"
//	#define STRMSG_S_SCMONITOR_0019 "�{����Field Server���I�����܂����H"
//	#define STRMSG_S_SCMONITOR_0020 "������-���-�ޮ�ؽď��(�ő�1492 Bytes)\r\n\r\n��-�ޮ�ؽČ�[%3d]�A��-����� [%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "�{����Pre Server���I�����܂����H"
//	#define STRMSG_S_SCMONITOR_0022 "�{����IM Server���I�����܂����H"
//	#define STRMSG_S_SCMONITOR_0023 "�{����NPC Server���I�����܂����H"
//	#define STRMSG_S_SCMONITOR_0024 "%Y�N%m��%d��%H��%M��%S�b"
//	#define STRMSG_S_SCMONITOR_0025 "�C�x���g�Ȃ�(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "�I-�v���x-�^�o�ȃC�x���g(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "�C�x���g�s��(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "���̐�̐�ݒ莞��"
//	#define STRMSG_S_SCMONITOR_0029 "���̐�̐��?����"
//	#define STRMSG_S_SCMONITOR_0030 "��̗��c"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "==>���ߌꂪ�������܂����B\r\n"
//	#define STRERR_S_SCMONITOR_0001 "==>���ߌꂪ���s���܂����B\r\n"
//	#define STRERR_S_SCMONITOR_0002 "DB�ɐڑ��ł��܂���B"
//	#define STRERR_S_SCMONITOR_0003 "�Y��Version�����݂��Ă��܂���B"
//	#define STRERR_S_SCMONITOR_0004 "���k����̫��ޖ�����͂��Ă�������"
//	#define STRERR_S_SCMONITOR_0005 "�o�͂���̫��ޖ�����͂��Ă�������"
//	#define STRERR_S_SCMONITOR_0006 "�J�n��-�ޮ݂���͂��Ă��������B"
//	#define STRERR_S_SCMONITOR_0007 "�Ō����-�ޮ݂���͂��Ă��������B"
//	#define STRERR_S_SCMONITOR_0008 "������-ėpZip̧�ق��o�͂���̫��ނ�I�����Ă�������"
//	#define STRERR_S_SCMONITOR_0009 "̧�ق�A���ł��܂���"
//	#define STRERR_S_SCMONITOR_0010 "�-��-��I�����Ă��������I"
//	#define STRERR_S_SCMONITOR_0011 "DB�ɘA���ł��܂���"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type:%s(%#04x)in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "������-���-�ޮ�ؽĂ��������܂��B(��-�ޮ�ؽČ�[%3d]�A��-�����[%4dBytes])\r\n\r\n��-�ޮ�ؽĂ𐮗����Ȃ��Ă͂Ȃ�܂���B"
//	#define STRERR_S_SCMONITOR_0014 "�������ꂽ??�ł��B\r\n�Ǘ��-ق𗘗p���Ă��������B"
//	#define STRERR_S_SCMONITOR_0015 "�s�s��̐�ϯ�߂ł͂���܂���"
//	#define STRERR_S_SCMONITOR_0016 "EDIT����-ق��쐬�ł��܂���B"
//	#define STRERR_S_SCMONITOR_0017 "���ɑ��݂���̧�ق�o�^���܂����B"

// 4_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Log Server�ɐڑ����܂����B\r\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Log Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error]WndProc(),Can't connect to PreServer[%15s:%4d]Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Pre Server�ɐڑ����܂����B\r\n"
	#define STRMSG_S_F2PRECONNECT_0002 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY:%s(%#04x)\r\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Pre Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(),Can't connect to  IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "IM Server�ɐڑ����܂����B\r\n"
	#define STRMSG_S_F2IMCONNECT_0002 "IM Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "  T_ERROR %s(%#04X) received from%s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY:%s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries!%d\r\n"
	#define STRMSG_S_F2DBQUERY_0001 "�Y�����т����݂��Ă��܂���B"
	#define STRMSG_S_F2DBQUERY_0002 "'%s'�l�͏o�Ȑ\�����݂��������߁A�񑩂������т�"
	#define STRMSG_S_F2DBQUERY_0003 "�x�����܂��B�C���x���g�����m�F���Ă�������"
	#define STRMSG_S_F2DBQUERY_0004 "�X�L��%s(%d)���ǉ�����܂����B"
	#define STRMSG_S_F2DBQUERY_0005 "�Y�����т����݂��Ă��܂���B"
	#define STRMSG_S_F2DBQUERY_0006 "���эw���Ɏ��s���܂����B"

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "  �s�s��̐�J�n:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "		  �Q�����c:GuildUID(%4d) GuildName(%10s)GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "  �s�s��̐��ݽ�-����:%d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "		 ���-���-��==>GuildName(%10s)SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "  �s�s��̐�:%d(%10s)CityMapIndex(%d)QuestIndex(%d)OccGuildID(%d)OccGuildName(%s) OccGuildMasterUID(%d)��̐펞��(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "%d����\"%s\"�s�s��̐킪�J�n���܂��B"
	#define STRMSG_S_F2CITYWAR_0007 "%d����\"%s\"�s�s��̐킪�I�����܂��B"
	#define STRMSG_S_F2CITYWAR_0008 "�s�s��̐�(%s)�ݽ�-����:NPC���"
	#define STRMSG_S_F2CITYWAR_0009 "�s�s��̐�(%s)�ݽ�-����:%s���c���"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\"��\"%s\"���̂��܂����B"
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\"���c��\"%s\"���̂��܂����B"

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Я��݃�-�f�B���O���s"
	#define STRMSG_S_F2QUEST_0001 "Я��݂̃�-�f�B���O�Ɏ��s���܂����B\r\n"
//	#define STRMSG_S_F2QUEST_0002 "Я���\'%30s\'�ԍ�%d->OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "�e�X�g�p�T-�o�Z�b�e�B���O�����I \r\n\r\nLoadFieldServerDataDebug()���������肢�I"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d:%d��%5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d:%s��%5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "��?"
	#define STRMSG_S_F2NOTIFY_0003 "����"
	#define STRMSG_S_F2NOTIFY_0004 "�ݽ�-1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "�ݽ�-2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "����̎�ނ��ԈႢ�܂����B�Ǘ��҂ɖ₢���킹�����Ă��������B"
	#define STRMSG_S_F2NOTIFY_0007 "1-1?:%4.1f vs %4.1f->������ %2.2f%% ����"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s���s�A�m��(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s���s�A�m��(%d>%5.2f)-%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s���s�A�m��(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2?:%4.1f vs %4.1f->?��?�W%2.2f%%����(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s��%5.2f(%5.2f-%d/255)�n��(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s����%5.2f(%5.2f-%d/255) ���炤�B(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d,HP:%5.2f)��%5.2f(%5.2f-%d/255)�n��(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s����%5.2f(%5.2f-%d/255)���炤(%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "???���s:�m���s��>%d"
	#define STRMSG_S_F2NOTIFY_0017 "�c��???[%#08x]:%5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "�e�e��񂪂���܂���B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0019 "�e�e�̌��a��񂪑��݂��Ă��܂���B%s%d"
	#define STRMSG_S_F2NOTIFY_0020 "�e�e�̏��ł��B%s%d"
	#define STRMSG_S_F2NOTIFY_0021 "���ɃC�x���g���������̂��߁A��-�v�ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0022 "���S���Ă��邽�߃�-�v�ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0023 "�ґ��풆�̂��߃�-�v�ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0024 "ϯ�ߐ���G��-�I�Ǘ��҂ɂ��₢���킹���������I"
	#define STRMSG_S_F2NOTIFY_0025 "ϯ�ߐ���G��-�I�Ǘ��҂ɂ��₢���킹���������I%d��%d�̃E�B?�t??�Q�b�g�C���f�b�N�X���Ȃ��I\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "�ґ��풆�̂��߃�-�v�ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0027 "  WARP(%04d)�����s��at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1->��׸�-%10s�������-��%5.2f���󂯂܂���"
	#define STRMSG_S_F2NOTIFY_0029 "1->��׸�-%10s�����-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0030 "1->��׸�-%10s�����-�� %5.2f�� ?���܂���"
	#define STRMSG_S_F2NOTIFY_0031 "1->��׸�-%10s��???���-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0032 "2->��׸�-%10s�������-��%5.2f���󂯂܂���"
	#define STRMSG_S_F2NOTIFY_0033 "2->��׸�-%10s�����-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0034 "2->�ݽ�-%3d�����-��%5.2f(%d)��?���܂���"
	#define STRMSG_S_F2NOTIFY_0035 "2->��׸�-%10s�����-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0036 "2->��׸�-%10s��???���-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0037 "2->�ݽ�-%3d�������-��%5.2f���󂯂܂���"
	#define STRMSG_S_F2NOTIFY_0038 "MINE->��׸�-%10s�����-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0039 "MINE->��׸�-%10s��???���-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0040 "MINE->�ݽ�-%10s�����-��%5.2f��?���܂���"
	#define STRMSG_S_F2NOTIFY_0041 "��-���������ɐ������܂����B"
	#define STRMSG_S_F2NOTIFY_0042 "���S�����Ƃ��ɂ͎g�p�ł��܂���"
	#define STRMSG_S_F2NOTIFY_0043 "ENCHANT_INFO�Ȃ�"
	#define STRMSG_S_F2NOTIFY_0044 "�����Ăɐ������܂���"
	#define STRMSG_S_F2NOTIFY_0045 "�����ĂɎ��s���܂���"
	#define STRMSG_S_F2NOTIFY_0046 "���c�ɏ������Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0047 "���ɐ\�����ݑҋ@���ł��B"
	#define STRMSG_S_F2NOTIFY_0048 "���΂炭��ōĎ��s���Ă��������B"
	#define STRMSG_S_F2NOTIFY_0049 "���������肪���c���ł͂���܂���B"
	#define STRMSG_S_F2NOTIFY_0050 "���ɗ��c�풆�ł��B"
	#define STRMSG_S_F2NOTIFY_0051 "�����̗��c��������ϯ�߂ɑ��݂��Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0052 "�S�ґ������o-������ϯ�߂ɓ����Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0053 "�S�ґ������o-������ϯ�߂ɓ����Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0054 "���c�ɏ������Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0055 "�\�����ݎ҂Ɣ�?�����ݎ҂��Ⴂ�܂��B"
	#define STRMSG_S_F2NOTIFY_0056 "���������肪���c���ł͂���܂���B"
	#define STRMSG_S_F2NOTIFY_0057 "�����̗��c��������ϯ�߂ɑ��݂��Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0058 "���c�ɏ������Ă��܂���B"
	#define STRMSG_S_F2NOTIFY_0059 "�\�����ݎ҂Ɣ�\�����ݎ҂��Ⴂ�܂��B"
	#define STRMSG_S_F2NOTIFY_0060 "���������肪���c���ł͂���܂���B"
	#define STRMSG_S_F2NOTIFY_0061 "�s�s��̐�h��ɐ������܂����B"
	#define STRMSG_S_F2NOTIFY_0062 "Я��ݐݒ�G��-�ł��B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0063 "���̈ʒu�ł͊Y������(%s)�𑕔��ł��܂���"
	#define STRMSG_S_F2NOTIFY_0064 "�G���W���̃X���b�g�͋󂯂邱�Ƃ��ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0065 "���шړ�:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0066 "�Ԉ���Ă��鱲�шړ�:(%I64d,%d)->(%I64d,%d)"
	#define STRMSG_S_F2NOTIFY_0067 "  EVENT(%d)�����s��at Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "ϯ�߲���ď��ُ�I�Ǘ��҂ɂ��₢���킹���������I�I"
	#define STRMSG_S_F2NOTIFY_0069 "�Y����-�v??�Q�b�g���Ȃ�"
	#define STRMSG_S_F2NOTIFY_0070 "���эw���G��-�ł��B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0071 "�w������X�L�����x���������X�L���̃��x�����Ⴂ�������ł��B"
	#define STRMSG_S_F2NOTIFY_0072 "�X�L���w���̂��߂ɂͱ��т��K�v�ł��B"
	#define STRMSG_S_F2NOTIFY_0073 "���є̔���-�ł��B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0074 "���эw����-�ł��B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0075 "\'ص��ݱ���\'���w�����܂����B"
	#define STRMSG_S_F2NOTIFY_0076 "�w�����X�g:\'%s(%d��)\'"
	#define STRMSG_S_F2NOTIFY_0077 "���ɕґ��ɉ������Ă��܂��B"
	#define STRMSG_S_F2NOTIFY_0078 "���Ȃ��͕ґ����Ȃ̂ł��܂���"
	#define STRMSG_S_F2NOTIFY_0079 "�ґ��킪�i�s���̂��߉����ł��܂���B"
	#define STRMSG_S_F2NOTIFY_0080 "�S�ґ������o-�̏����󂯎�邱�Ƃ͂ł��܂���I"
	#define STRMSG_S_F2NOTIFY_0081 "ϯ�߲���ď��ُ�I�Ǘ��҂ɂ��₢���킹���������I�I"
	#define STRMSG_S_F2NOTIFY_0082 "�������ł��Ȃ��A�J�E���g�ł��B"
	#define STRMSG_S_F2NOTIFY_0083 "%s�l�͐ύڗʒ��߂ł��B"
	#define STRMSG_S_F2NOTIFY_0084 "�ړ���?���W:(5, 5)->(%d,%d)"
	#define STRMSG_S_F2NOTIFY_0085 "��ڲ�-:"
	#define STRMSG_S_F2NOTIFY_0086 "�ő�20�l�܂Ō��邱�Ƃ��ł��܂�"
	#define STRMSG_S_F2NOTIFY_0087 "�Y����ڲ�-(%s)�����܂���"
	#define STRMSG_S_F2NOTIFY_0088 "�ґ��ɏ������Ă��܂���"
	#define STRMSG_S_F2NOTIFY_0089 "���ݎ���:%d:%d�A�A�g?����:%d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "�ύX����:%d:%d�A�A�g?����:%d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "NPC�-��-�ɐڑ����Ă��܂���"
	#define STRMSG_S_F2NOTIFY_0092 "�Y������(%d)�����݂��Ă��܂���"
	#define STRMSG_S_F2NOTIFY_0093 "Countable Item����Ȃ��ꍇ��10�ɐ�������܂�"
	#define STRMSG_S_F2NOTIFY_0094 "ϯ��\'%s\'�̑S�̐ڑ���:%d�l"
	#define STRMSG_S_F2NOTIFY_0095 "ϯ��%s%s�����ڑ���:%d�l-'%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "ϯ��%s%s�����ڑ���:%d�l-'%s'"
	#define STRMSG_S_F2NOTIFY_0097 "����ϯ�������:%s�A%d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "�e�e��񂪂���܂���B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0099 "�e�e�̌��a��񂪑��݂��܂���B%s%d"
	#define STRMSG_S_F2NOTIFY_0100 "�e�e��񂪂���܂���B�Ǘ��҂ɂ��₢���킹���������B"
	#define STRMSG_S_F2NOTIFY_0101 "�e�e�̌��a��񂪑��݂��Ă��܂���B%s%d"
	#define STRMSG_S_F2NOTIFY_0102 "�Y����ڲ�-(%s)�����܂���"
	#define STRMSG_S_F2NOTIFY_0103 "�Y����ڲ�-(%s)��?��ł��܂�"
	#define STRMSG_S_F2NOTIFY_0104 "�Y����ڲ�-(%s)�����܂���"
	#define STRMSG_S_F2NOTIFY_0105 "��ʃA�J�E���g�ɐݒ肵�܂���"
	#define STRMSG_S_F2NOTIFY_0106 "��ʃA�J�E���g����������܂���"
	#define STRMSG_S_F2NOTIFY_0107 "���G(���-�ނ��󂯂Ȃ�)���j�b�g�ɐݒ肵�܂���"
	#define STRMSG_S_F2NOTIFY_0108 "���G(���-�ނ��󂯂Ȃ�)���j�b�g�ݒ肪��������܂���"
	#define STRMSG_S_F2NOTIFY_0109 "���킪%5.0f%%�̂��蓾�Ȃ����\�������܂���"
	#define STRMSG_S_F2NOTIFY_0110 "���эđ��U������������܂�"
	#define STRMSG_S_F2NOTIFY_0111 "���эđ��U������������܂�"
	#define STRMSG_S_F2NOTIFY_0112 "�Y����ڲ�-(%s)�����܂���"
	#define STRMSG_S_F2NOTIFY_0113 "������Ԃ���������܂���"
	#define STRMSG_S_F2NOTIFY_0114 "������Ԃ����������܂���"
	#define STRMSG_S_F2NOTIFY_0115 "%s�C�x���g���i�s���ł͂���܂���"
	#define STRMSG_S_F2NOTIFY_0116 "%s�C�x���g���J�n(?��:%4.2f�A�C�x���g����:%3d��)"
	#define STRMSG_S_F2NOTIFY_0117 "������бѱ���Ăɐݒ肳��܂���"
	#define STRMSG_S_F2NOTIFY_0118 "���бѱ���Đݒ�Ɏ��s���܂���"
	#define STRMSG_S_F2NOTIFY_0119 "�-��-���бѱ���Ăɐݒ肳��܂���"
	#define STRMSG_S_F2NOTIFY_0120 "�s�s��̐�ϯ�߂ł͂���܂���"
	#define STRMSG_S_F2NOTIFY_0121 "�s�s��̐���J�n�ł��܂���"
	#define STRMSG_S_F2NOTIFY_0122 "�s�s��̐���I���ł��܂���"
	#define STRMSG_S_F2NOTIFY_0123 "������Ԃ�����������܂���"
	#define STRMSG_S_F2NOTIFY_0124 "������ԂɂȂ�܂���"
	#define STRMSG_S_F2NOTIFY_0125 "ϯ�߂������ł��B"
	#define STRMSG_S_F2NOTIFY_0126 "HappyHour�ɐݒ�[�i�s����:%4d��)]"
	#define STRMSG_S_F2NOTIFY_0127 "HappyHour�I��"
	#define STRMSG_S_F2NOTIFY_0128 "��?->�ݽ�-%3d�������-��%5.2f���󂯂܂���"
	#define STRMSG_S_F2NOTIFY_0129 "��?->�ݽ�-%3d�������-��%5.2f���󂯂܂���(???)"
	#define STRMSG_S_F2NOTIFY_0130 "%s�����Ƃ��Đڑ����܂���"
	#define STRMSG_S_F2NOTIFY_0131 "�I����-�e�B�����������Ȃ�?%s:CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine():�ґ������o-�������s�I%s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix\'%s\'����:%d<=%d<=%d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix\'%s\'����:%d<=%d<=%d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s:��?�I"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR:�Ǘ��҂ɂ��₢���킹���������I�V���b�v�ϐ����蓖�ăG��-?�I"
	#define STRMSG_S_F2NOTIFY_0137 "%s���폜����܂����B"
	#define STRMSG_S_F2NOTIFY_0138 "���݂�?�����l���͔񊈐����̂��߃��ݽ�-����т��̑�??��"
	#define STRMSG_S_F2NOTIFY_0139 "��?���܂��B�ق�������ق𗘗p���Ă��������B"
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2d��]:%04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "?�C??����%s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HP�����񕜂�?���܂�"
	#define STRMSG_S_F2NOTIFY_0143 "�����\�n��ł͂Ȃ����߁AHP�����񕜂�?���܂�"
	#define STRMSG_S_F2NOTIFY_0144 "��?�ɂ��HP5.2f��"
	#define STRMSG_S_F2NOTIFY_0145 "Gradual HP UP ��?(�c�莞��:%d)"
	#define STRMSG_S_F2NOTIFY_0146 "Gradual DP UP ��?(�c�莞��:%d)"
	#define STRMSG_S_F2NOTIFY_0147 "Gradual EP UP ��?(�c�莞��:%d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s�C�x���g���I�����܂����B"
	#define STRMSG_S_F2NOTIFY_0149 "%s�C�x���g�i�s��(?��:%4.2f,�c�莞��:%3d��)"
	#define STRMSG_S_F2NOTIFY_0150 "���ߌオ���s����Ă��܂���"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "	�o���l���z�G��-(%s,%s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "����Game Startү�-�޴�-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "����Game Start ү�-�޴�-ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d)�����s��at ProcessQuestResult(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "ϯ�߲���ď��ُ�I�Ǘ��҂ɂ��₢���킹���������I�ICurrent(%s,%s,%04d),Target(%04d,%d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d)�����s��at T_FC_PARTY_REQUEST_PARTY_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "ϯ�߲���ď��ُ�I�Ǘ��҂ɂ��₢���킹���������I�ICurrent(%s,%s,%04d),Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP�����s��at T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d)�����s��(�ґ���)at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) �����s��at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME().%s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) �����s��at Process_FC_EVENT_REQUEST_WARP(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP �����s��at T_FC_PARTY_REQUEST_PARTY_WARP().%s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "�ґ���-�v���s:%s->����:%5.2f, bodycon: %d,%d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) �����s��at Process_FC_CHARACTER_DEAD_GAMESTART(),%s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s->OK??���N���b�N�d���I\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Я��݂���-�f�B���O����Ă��܂���B\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s)�����s�� at HandleAdminCommands(),/�ړ�,%s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s)�����s�� at HandleAdminCommands(),/���M,%s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATAL ERROR:�Y�������o-�������Ă��Ȃ�̨-��޻-��-�ɂ́A���̃��b�Z-�W�����M����Ă͂����܂���Bcheck it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d)�����s��at T_FI_ADMIN_CALL_CHARACTER,%s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s)�����s��at T_FI_ADMIN_MOVETO_CHARACTER,%s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "�o���l"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "�o���l����"
	#define STRMSG_S_F2EVENTTYPE_0003 "������ۯ��"
	#define STRMSG_S_F2EVENTTYPE_0004 "ڱ������ۯ��"
	#define STRMSG_S_F2EVENTTYPE_0005 "�C�x���g�s��"
// 5_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Pre Server�ɐڑ����܂����B\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Pre Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\'�͊��ɑ��݂��Ă��闷�c���ł��B"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\'�͊��ɗ��c�ɉ������Ă��܂��B"
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\'�͊��ɑ��݂��闷�c���ł��B"
	#define STRMSG_S_I2NOTIFY_0003 "���c��-�f�B���O���s-�Ǘ��҂ɂ��₢���킹���������I"
	#define STRMSG_S_I2NOTIFY_0004 "�F�B'%s'�l�����O�C�����܂����B"
	#define STRMSG_S_I2NOTIFY_0005 "�ȑO�̕ґ����m�F���܂�"
	#define STRMSG_S_I2NOTIFY_0006 "�����̕ґ������݂��Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0007 "�ґ��ɍĉ������܂���"
	#define STRMSG_S_I2NOTIFY_0008 "���ɉ������Ă���ґ�������܂��B"
	#define STRMSG_S_I2NOTIFY_0009 "Fatal Error:?���ȕґ��G��-�Iat T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "�ґ������o-�̏�Ԃ��s���ł�"
	#define STRMSG_S_I2NOTIFY_0011 "�ґ������o-�����ɗ��c�ɉ������Ă��܂�"
	#define STRMSG_S_I2NOTIFY_0012 "�Ώۂ����ɗ��c�ɉ������Ă��܂�"
	#define STRMSG_S_I2NOTIFY_0013 "���������҂��邱�Ƃ͂ł��܂���"
	#define STRMSG_S_I2NOTIFY_0014 "���c������������Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0015 "�����\�ȗ��c�����o-���𒴉߂��܂���"
	#define STRMSG_S_I2NOTIFY_0016 "���c������������Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0017 "���c���͒E�ނł��܂���"
	#define STRMSG_S_I2NOTIFY_0018 "���c�풆�̂��߁A���c����E�ނł��܂���"
	#define STRMSG_S_I2NOTIFY_0019 "���c�풆�̂��߁A���c�����o-��Ǖ��ł��܂���"
	#define STRMSG_S_I2NOTIFY_0020 "���c���͒Ǖ��ł��܂���"
	#define STRMSG_S_I2NOTIFY_0021 "���c�풆�̂��߁A���c�����U�ł��܂���"
	#define STRMSG_S_I2NOTIFY_0022 "�������O�ɕύX�ł��܂���"
	#define STRMSG_S_I2NOTIFY_0023 "���c����ύX�ł��Ȃ���Ԃł�"
	#define STRMSG_S_I2NOTIFY_0024 "���c�-���ύX�ł��Ȃ���Ԃł�"
	#define STRMSG_S_I2NOTIFY_0025 "�K����ύX�ł��Ȃ���Ԃł�"
	#define STRMSG_S_I2NOTIFY_0026 "�K�����d������܂���"
	#define STRMSG_S_I2NOTIFY_0027 "���c���ւ̊K���ύX�͂ł��܂���B"
	#define STRMSG_S_I2NOTIFY_0028 "���c���̊K���ύX�͂ł��܂���B"
	#define STRMSG_S_I2NOTIFY_0029 "�S����ڲ�-��:%d�l(%�l�܂ŏo��)"
	#define STRMSG_S_I2NOTIFY_0030 "�^�c�҃��b�Z-�W���X�g�ɒǉ����܂���"
	#define STRMSG_S_I2NOTIFY_0031 "�^�c�҃��b�Z-�W���X�g����폜����܂���"
	#define STRMSG_S_I2NOTIFY_0032 "�-��-IP:%s"
	#define STRMSG_S_I2NOTIFY_0033 "�-��-���-�� \'%s\'�̑S�̐ڑ���:%d�l"
	#define STRMSG_S_I2NOTIFY_0034 "�{���ɻ-��-(%s)���I�����܂����H����:%d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\'�͹�-т����Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0036 "�S����ڲ�-��:%d�l(%d�l�܂ŏo��)"
	#define STRMSG_S_I2NOTIFY_0037 "/���M%s%s"
	#define STRMSG_S_I2NOTIFY_0038 "�Y�����c������܂���B"
	#define STRMSG_S_I2NOTIFY_0039 "�����₫�u���b�N����������܂����I"
	#define STRMSG_S_I2NOTIFY_0040 "�����₫���u���b�N���܂����I"
	#define STRMSG_S_I2NOTIFY_0041 "���c�ɉ������Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0042 "���c(%d)�������ł�"
	#define STRMSG_S_I2NOTIFY_0043 "�Y���V�C(%s)�����݂��Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0044 "Field Server�������ł�"
	#define STRMSG_S_I2NOTIFY_0045 "�Y��ϯ��(%s)�����݂��Ă��܂���"
	#define STRMSG_S_I2NOTIFY_0046 "���Ȃ���%d�������ċ֎~�ł��I"
	#define STRMSG_S_I2NOTIFY_0047 "������ۯ��ݒ�:'%10s',%3d��"
	#define STRMSG_S_I2NOTIFY_0048 "������ۯ�����������܂���"
	#define STRMSG_S_I2NOTIFY_0049 "������ۯ�����:'%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s(�A�J�E���g:%s,?�b�v:%d(%d),���x��: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "�������ĂԂ��Ƃ��ł��܂���"
	#define STRMSG_S_I2NOTIFY_0052 "�Y�����c������܂���B"

	#define STRMSG_S_IMSERVER_050607_0001	"�Y��ϯ�߂�����܂���B"
// 6_end
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Field Server�ɐڑ����܂����B\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Field Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "							�ݽ�-�ƃI�u�W�F�N�g�̏Փ˂��������Ȃ�\r\n"		
	#define STRMSG_S_N2NOTIFY_0001 "�s�s��̐��ݽ�-(%10s)����\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "�Γc�k���Y"
// 7_end
///////////////////////////////////////////////////////////////////////////////	
	

///////////////////////////////////////////////////////////////////////////////	
// 8 - PreServer	
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "%s�A�J�E���g(%s)�ɐڑ����܂����B IP:%s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "����"
	#define STRMSG_S_P2PRENOTIFY_0002 "���s"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR]�A�J�E���g���ǉ��G��-�A AccountName(%s)privateIP(%15s)\n"
	
	
	#define STRMSG_SCAT_051115_0001		"���͂悤�������܂��B�-���ײ݉^�c�-тł��B"
	#define STRMSG_SCAT_051115_0002		"?���A10������14���܂Œ�������e�i���X����?���܂��B"
	#define STRMSG_SCAT_051115_0003		"���S�ȏꏊ�Ɉړ����āA�ڑ����I�����Ă��������B"
	#define STRMSG_SCAT_051115_0004		"�܂�NPC�-��-����I�����܂��B"
	#define STRMSG_SCAT_051115_0005		"���ꂩ��-���ײݒ�������e�i���X���J�n���܂��B"
	#define STRMSG_SCAT_051115_0006		"�-���ײ݂Ɗy����������߂����Ă��������B"
	#define STRMSG_SCAT_051115_0007		"�܂��Ȃ��ً}�����e�i���X�̂��߻-��-���I�����܂��B"
	#define STRMSG_SCAT_051115_0008		"�����e�i���X�̎��Ԃ�2���Ԃł��B"







///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"�������:��ڲ�-�����邱�Ƃ��ł��Ȃ��A�S����g�p�s��"
	#define STRMSG_060509_0001			"���G���:���-�ނ��󂯂Ȃ�"
	#define STRMSG_060509_0002			"��ٽ�-��:�ݽ�-����搧�U�����󂯂Ȃ�"

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you momentarily."
	#define	STRMSG_060526_0001			"����������-Ď��s�ł��܂���B\r\n\r\n�����T�C�g(%s)�޳��-����-�ނ����߯����󂯂Ĳݽ�-ق��Ă��������B\r\n\r\n    Error:%s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"����ID���o�^����Ă��Ȃ����A\r\n ID��PW���Ԉ���Ă��܂��B"
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"���ݻ-�޽����ݽ���ł��B�ڍׂȐ����͌����T�C�g�����m�F���������B"

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"�ײ�����-�ޮ݂��قȂ�܂��B\r\n�����T�C�g(%s)�޳��-����-�ނ����߯����󂯂Ĳݽ�-ق��Ă��������B"

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"%s�Ɍ��Ă���܂����B"			  			

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000			"���-��- DB(atum2_db_20) �������͑��-��-�Q���I����ɂ��Ă��������B"
	#define STRMSG_070410_0001			"�{���ɑ��-��- DB(atum2_db_20)�����������܂����H [�F�؃i���o-:%d]"
	#define STRMSG_070410_0002			"���-��- DB(atum2_db_20)������������܂����B"
	#define STRMSG_070410_0003			"���-��- DB(atum2_db_20)���������s�I"
	#define STRMSG_070410_0004			"���-��- DB(atum2_db_20)��'%s'�̏����-����"
	#define STRMSG_070410_0005			"���-��- DB(atum2_db_20)��'%s'�̏����-���s-��׸�-�����݂��܂���I"
	#define STRMSG_070410_0006			"���-��- DB(atum2_db_20)��'%s'�̏����-���s-���-��-�ɊY���A�J�E���g�̷�׸�-������܂��I"
	#define STRMSG_070410_0007			"���-��-DB(atum2_db_20)��'%s'�̏����-���s-DB�ǉ���-�ł��I"
	#define STRMSG_070410_0008			"���-��-DB(atum2_db_20)��'%s'�̏����-���s-�s��(%d)�I"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon, ??? ����?
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

// 2007-06-15 by dhjin, �ϐ�֘A�X�g�����O
#define STRMSG_070615_0000				"������Ԃł͂Ȃ����ߊϐ���J�n�ł��܂���B"
#define STRMSG_070615_0001				"�ϐ���J�n�ł��܂���B"
#define STRMSG_070620_0000				"��ʐ��͂͊ϐ�ł��܂���B"

// 2007-06-26 by dhjin, �푈?�C���g�iWP�j �C�x���g �֘A �ǉ�
#define STRMSG_S_F2EVENTTYPE_0006		"�푈�߲�āiWP�j"

// 2007-06-28 by cmkwon, ?? ?????(�Q?? ?? ?? ??) - ??? �ǉ�
#define STRMSG_070628_0000				"??? ?? �Q????? ?? %d??? ?????."
#define STRMSG_070628_0001				"??? ?? �Q????? ?? %d??? ?????. �Q??�I��??? ??? ??? ??? ??�� ???."
#define STRMSG_070628_0002				"??? ?? ??? �Q????? ??????. ??? �Q????? 50%%?? ?????. ??? ??�� ??? �Q?? �I��??? ??? ??�� ??? ???? ????�� ?????"
#define STRMSG_070628_0003				"??? ?? ???? �Q????? ??????. ??? ??�� ??? ����? �Q?? �I��???. ??? ??? ??? ??? ??? ??? ??? �Q????? 0%%?? ?????. �Q?? �I�� ? 5???? ?? ??? ???? ?????."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, ��-Ńu���b�N ���� � - �ǉ������X�g�����O
#define STRMSG_070711_0000				"\'%s\'�l�ͱ�-ł̗��p�u���b�N��Ԃł͂���܂���B"
#define STRMSG_070711_0001				"\'%s\'�l�ͱ�-ł̗��p�u���b�N��Ԃł��B(�c�莞��:%d��)"
#define STRMSG_070711_0002				"���Ȃ���%d���Ա�-ł̗��p�u���b�N��Ԃł��I"
#define STRMSG_070711_0003				"��-ł̗��p�u���b�N����������܂����B"
#define STRMSG_070711_0004				"\'%s\'�l�̱�-ł̗��p�u���b�N����������܂����B"

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide ??? 1280x720(16:9) �ǉ� - ??? �ǉ�
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon, ��c�� �V�X�e? ?? - ??? �ǉ�
#define STRMSG_070830_0001				"���͑I����A�g�p�ł��閽�ߌ�ł�"
#define STRMSG_070830_0002				"�Y�����͂̉�c��ϯ��(%d)�������ł�"
#define STRMSG_070830_0003				"���݉�c���ɓ���ł���l��:%d�l"
#define STRMSG_070830_0004				"'%s'�l�͊��ɉ�c�����ꌠ���������Ă��܂��B"
#define STRMSG_070830_0005				"'%s'�l�͉�c�����ꌠ��������܂���B"
#define STRMSG_070830_0006				"'%s'�͖����ȃL�����N??�ł��B"
#define STRMSG_070830_0007				"'%s'����c�����ꌠ�����X�g�ɒǉ��ł��܂���B(�ő�%d�l)"
#define STRMSG_070830_0008				"'%s'�l�ɉ�c�����ꌠ�����t�^����܂����B"
#define STRMSG_070830_0009				"��c�����ꌠ�����t�^����܂����B"
#define STRMSG_070830_0010				"��c�����ꌠ������������܂����B"
#define STRMSG_070830_0011				"'%s'"

// 2007-11-13 by cmkwon, ???? ?? �ǉ� - 
#define STRMSG_071115_0001				"\\y%s�l��%s���т� ��ھ��Ă��܂����B"
#define STRMSG_071115_0002				"��ھ���ؽ�:\'%s(%d��)\'"
#define STRMSG_071115_0003				"\\y%s�l��%s�l��%s���т���ھ��Ă��܂����B�q�ɂ��m�F���Ă��������B"

// 2007-11-19 by cmkwon, �i�漽�� ������-� -
#define STRMSG_071120_0001				"�i�漽�ї��p���Ԃł͂���܂���B����-���-�ɂ��₢���킹���������B"
#define STRMSG_071120_0002				"�i�漽�т�����������܂����B"
#define STRMSG_071120_0003				"�i�漽�т��I�����܂����B"
#define STRMSG_071120_0004				"%s����%s�܂Ői�漽�т����s���܂��B"

// 2007-11-28 by cmkwon, ���m���ы - 
#define STRMSG_071128_0001				"%s�l��%s����%d����ھ��Ă��܂����B�q�ɂ��m�F���Ă��������B"

// 2007-12-27 by cmkwon, �E�C���h�E�-��??�ǉ� -
#define STRMSG_071228_0001				"�𑜓x�ݒ肪�����ł��B������x�m�F���Ă��������B"

// 2008-01-31 by cmkwon, �A�J�E���g�u���b�N/�������ߌ�ŉ\�ȼ��ы-
#define STRMSG_080201_0001				"'%s'�l�u���b�N�ݒ�ɴ�-������܂��B ErrorCode(%d)"
#define STRMSG_080201_0002				"'%s'�A�J�E���g���u���b�N�������܂����B[Block End Date:%s]"
#define STRMSG_080201_0003				"'%s'�A�J�E���g���u���b�N���X�g�ɂ���܂���BErrorCode(%d)"
#define STRMSG_080201_0004				"'%s'�A�J�E���g�u���b�N ���������ɴ�-������܂��BErrorCode(%d)"
#define STRMSG_080201_0005				"'%s'�A�J�E���g���u���b�N�����������܂����B"

// 2008-02-11 by cmkwon, ??? �ǉ�(1440x900) -
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin,  ??��-� - ��-� �-��- ?? ?? ??
#define STRMSG_S_MF2AFCONNECT_0000 "[Error]WndProc(),Can't connect to  ArenaServer[%15s:%4d]Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001 "Arena Server�ɐڑ����܂����B\r\n"
#define STRMSG_S_MF2AFCONNECT_0002 "Arena Server[%15s:%4d]�Ƃ̐ڑ����I�����܂����B�Đڑ����܂��B\r\n"
#define STRMSG_S_MF2AFCONNECT_0003 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004 "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001		"\\y%d�ԃA��-�iwaiting room�ɃC�x���g������ǉ����܂����B\r\n"
#define STRMSG_ARENAEVENT_080310_0002		"\\y%d�ԃA��-�iRoom�̃C�x���g�������������܂����B\r\n"
#define STRMSG_ARENAEVENT_080310_0003		"\\y�A��-�i�C�x���g�����̒ǉ��Ɏ��s���܂����B\r\n"
#define STRMSG_080428_0001					"%s�l�����Ă��܂����B"		// 2008-04-28 by dhjin, ��-� ?? - ���� ���� ? ??? �ǉ�, ��-� ϯ��???

// 2008-04-29 by cmkwon, �-��- ��� DB? �ǉ�(?? �A�J�E���g ��׸�- �쐬 ?? ���ђǉ�) - 
#define STRMSG_080430_0001					"�I�������T-�o�͐V�K��׸�-�쐬����������Ă���T-�o-�ł��B"

// 2008-06-13 by dhjin, EP3 ���c ?? ?? - 
#define STRMSG_080613_0001					"%s���c�ւ̉����\�����݂��u���b�N����܂����B"

// 2008-09-04 by cmkwon, don't need translation, �T?�o? SystemLog ??? ?? ?? ??	
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, �w�������Đ����J-�h
#define STRMSG_081230_0001					"\\y%s�����Ďg�p��%d���Ԑ������܂��B\\y"
#define STRMSG_081230_0002					"\\y�w���҂̌����ɂ�肠�Ȃ������Ďg�p��%d���Ԑ�������܂����B\\y"
#define STRMSG_081230_0003					"\\y�w�������Đ�������������܂����B\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D ���Ӱ���E����â �翁E�E- 
// 2009-09-02 by cmkwon, Gameforge4D ���� ����E����â WebPage�� ó�� - STRMSG_090831_0001�� ���������� ó��
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
#define STRMSG_090831_0002					"Install hackshield"
#define STRMSG_090831_0003					"cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ����E����â WebPage�� ó�� - 
#define STRMSG_090902_0001					"http://www.airrivals.net/launcher/hackshield.html"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ����E�ػ� �߰�(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ����E������ ���� �㿁E��Ȳ
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"�o�^����Ă��Ȃ��T-�o-�ł��B�i�v���C�x-�g�T-�o�ł���\��������܂��j"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				" DB�A�����ɃG��-���������܂����B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"�T-�o-�F�؂ɐ������܂����B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"�Y���T-�o-��IP���o�^����Ă��܂����A�F�؋��ۏ���������܂����B"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"�T-�o-�ɋ����I������ނ𑗐M���܂����B"






#define STRMSG_120330_0001	"%s�l���A�b�V����-���ŁA�B���ꂽ��Ԃւ̃�-�v�Q-�g�𔭓����܂����B"
#define STRMSG_120330_0002	"%s�l���A�b�V����-���ŁA�ݽ�-�o����100%%%%�����̃o-�X�g�C�x���g(1����)�𔭓����܂����B"
#define STRMSG_120330_0003	"%s�l���A�b�V����-���ŁA������ۯ�ߗ�100%%%%�����̃o-�X�g�C�x���g�i1���ԁj�𔭓����܂����B"
#define STRMSG_120330_0004	"%s�l���A�b�V����-���ŁA������ۯ�ߗ�100%%%%/Monster�o���l100%%%%/ SPI�l����100%%%%�����̃o-�X�g�C�x���g�i1���ԁj�𔭓����܂����B"
#define STRMSG_120330_0005	"%s�l���A�b�V����-����Weapon shop���������܂����B"
#define STRMSG_120330_0006	"%s�l���A�b�V����-���Ńn�C�p-�J-�h�V���b�v���������܂����B"
#define STRMSG_120330_0007	"%s�l���A�b�V����-���ŃL�b�g�V���b�v���������܂����B"
#define STRMSG_120330_0008	"%s�l���A�b�V����-����Boss Monster�����҂��܂����B"
#define STRMSG_120330_0009	"CRYSTAL�����ł��܂����B"



#define STRMSG_120508_0001					"%�l�����X�g�I�A�V�X����%WP���擾���܂����B"
#define STRMSG_120508_0002					"%�l�����X�g�I�A�V�X��Boss monsters���������܂����B"
#define STRMSG_120508_0003					"%�l���o-�X�g�C�x���g(1����)�𔭓����܂����B�ݽ�-�o���l��150%%%%�������܂��B"
#define STRMSG_120508_0004					"%�l���o-�X�g�C�x���g(1����)�𔭓����܂����B������ۯ�ߗ���150%%%%�������܂��B"
#define STRMSG_120508_0005					"%�l���o-�X�g�C�x���g(1����)�𔭓����܂����B�ݽ�-�o���l/������ۯ�ߗ�/SPI�l������150%%%%�������܂��B"
#define STRMSG_120508_0006					"%�l�����X�g�I�A�V�X�ŌÑ�̕X���擾���܂����B"
#define STRMSG_120508_0007					"%�l�����X�g�I�A�V�X��Item shop���������܂����B"
#define STRMSG_120508_0008					"%�l�����X�g�I�A�V�X�ŃL�b�g�V���b�v���������܂����B"
#define STRMSG_120508_0009					"%�l�����X�g�I�A�V�X�Ńn�C�p-�J-�h�V���b�v���������܂����B"
#define STRMSG_120508_0010					"%�l�����X�g�I�A�V�X��Weapon shop���������܂����B"
#define STRMSG_120508_0011					"%�l�����X�g�I�A�V�X�ŉB���ꂽ��Ԃւ̃�-�v�Q-�g���������܂����B"

#define STRMSG_120712_0001					"18�� �̸� û�ҳ⿡�� ����EǴ?���ӽð� ������ �������� ���Ͽ�, %d �� �Ŀ� ������ ����˴ϴ�."		// 2012-07-11 by hskim, ������E�˴ٿ�E

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc��E��E
#define STRMSG_121005_0001					"\\yPC��E������ �ð��� %d�� ���ҽ��ϴ�."
#define STRMSG_121005_0002					"\\y��� �� PC��E�������� ����˴ϴ�."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ��E�E�ý��� ������E- ��E�E?Ʈ���� ��������(�Ͻ�����E
#define STRMSG_121126_0001					"\\yCommand : �푈���͸ؽ�ق̔j��͏o���܂���B\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX�̺�Ʈ �� ��������
#define STRMSG_121129_0001					"\\y���̃G���A��GM�ȊO�i���ł��܂���B\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC ��E�E���EƮ���� �ý���
#define STRMSG_130121_0001					"\\c�V�X�e����NGC�R�ɂ���ĕ߂����܂����B�����P�ނ��J�n����܂����B"
#define STRMSG_130121_0002					"\\c��@��:\\c NGC����@���m�F����܂����B"
#define STRMSG_130121_0003					"\\c��@��:\\c NGC����@���j�󂳂�܂����B"
#define STRMSG_130121_0004					"\\c�w��:\\c NGC�S�����̃o���A���W�J����܂����I�o���A�𖳌�������ׂɐ���@��j�󂵂Ă��������I"
#define STRMSG_130121_0005					"\\c�w��:\\c �S�����̃o���A���j�󂳂�܂����I���U�����J�n���Ă��������I"
#define STRMSG_130121_0006					"\\c�w��:\\c �S�������j�󂳂�܂����I�e�@�͑O���ֈړ����J�n���Ă��������I"
#define STRMSG_130121_0007					"\\c�w��:\\c �S�����͍ŏ��ɔj�󂵂Ȃ���΂Ȃ�܂���B"
#define STRMSG_130121_0008					"\\c[%s]�̌��ʂ�NGC����@�̉ғ��������ł��B"
#define STRMSG_130121_0009					"\\y[NGC�A�h�o���X�x�[�X��n�V�X�e��]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������ �̺�Ʈ - ����E��� �߰����� �ý��� ����
#define STRMSG_130422_0001					"\\y%s %d�̓A���[�i���琧������Ă��܂��B�A�C�e���͑q�ɂɑ����܂����B\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �Ƹ� �÷��� - STRMSG �߰�
#define STRMSG_130531_0001					"\\g[%s] �O���̓A�[�}�[�R���N�V�����ɒǉ�����܂����B\\g"
#define STRMSG_130531_0002					"\\g[%s] �O����[%2d]��K�p����܂����B\\g"
#define STRMSG_130531_0003					"\\g[%s] �O���͓K�p�\�񐔂ɒB���܂����B�m%s�n�֕ύX����܂��B\\g"
#define STRMSG_130531_0004					"�O���̓K�p�������߂����ׁA�X�e�[�^�X���폜����܂����B�G���W������������Ă��܂���B"
#define STRMSG_130531_0005					"\\y�G���W������������Ă��܂���B�s�s�ɋA�҂��Ă��������B\\y"
#define STRMSG_130531_0006					"\\g���݃A�[�}�[�ɓK�p����Ă���O�����g�p���邱�Ƃ͂ł��܂���B\\g"
#define STRMSG_130531_0007					"\\g�O�����ύX����܂����B\\g"
#define STRMSG_130531_0008					"\\r�m%s�n�O���͊����؂�ɂȂ�܂����B\\r"
#define STRMSG_130531_0009					"\\y�O����K�p�����A�[�}�[�𔄋p���邱�Ƃ͂ł��܂���B\\y"
#define STRMSG_130531_0010					"\\y�M�A�^�C�v����v���܂���B\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, Ʈ���� �ý��� Ȯ��E- STRMSG �߰�
#define STRMSG_130708_0001					"\\c�w��:\\c NGC�R�̃V�[���h���W�J����܂����B�V�[���h�𖳌�������ɂ�NGC�R���g���[���[��j�󂵂Ă��������I"
#define STRMSG_130708_0002					"\\c�w��:\\c NGC�R����n�V�[���h���_�E�����Ă��܂��B�U�����J�n���Ă��������I"
#define STRMSG_130708_0003					"\\c��@��:\\c NGC�V�[���h�W�F�l���[�^�[���m�F����܂����B"
#define STRMSG_130708_0004					"\\c��@��:\\c NGC�V�[���h�W�F�l���[�^�[���j�󂳂�܂����B"

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, Ÿ ���� ���º���E
#define STRMSG_130726_0001					"�L�����N�^�[�͂��łɂ��̐��͂ł��B"
#define STRMSG_130726_0002					"�L�����N�^�[�̓��[�_�[�܂��̓T�u���[�_�[�ł��B���̂��ߐ��͂�ύX���邱�Ƃ͂ł��܂���B"
#define STRMSG_130726_0003					"�L�����N�^�[�͗��c�ɓ��c���Ă���ׁA���͂�ύX���邱�Ƃ͂ł��܂���B"
#define STRMSG_130726_0004					"���͕ύX�\�ȃL�����N�^�[�����܂���B"
#define STRMSG_130726_0005					"���͕ύX�Ɏ��s���܂����B[AUID(%d), CUID(%d), ToInflType(%d)] ErrorCode [%d]"
#define STRMSG_130726_0006					"���͕ύX�ɐ������܂����B [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"�A�J�E���g�����݂��܂���B"
#define STRMSG_130726_0008					"�A�J�E���g�����O�C�����Ă���ׁA���͕ύX���ł��܂���B"


// 2013-08-30 by bckim, �ʵ��̵�����������
#define STRMSG_130830_0001					"\\\y%s�l���w���Ҍ�����MAP�ւ̈ړ�����������܂����B\\y"
#define STRMSG_130830_0002					"\\y���ݎw���Ҍ����ɂ����MAP�ւ̈ړ����������ꂽ��Ԃł��B\\y"
#define STRMSG_130830_0003					"\\y%�Y���-��-�͎w���Ҍ����ɂ����MAP�ւ̈ړ����������ꂽ��Ԃł��B\\y"
// End. 2013-08-30 by bckim, �ʵ��̵�����������

// 2013-08-28 by bckim, �������� ����ȭ
#define STRMSG_130828_0001					"\\y[%s]�l �W�I�̌��j�ɍv�����܂����B\\y"
#define STRMSG_130828_0002					"\\y[%s]�l �W�I�ɑ΂���搧�U�����s���܂����B\\y"
#define STRMSG_130828_0003					"\\y[%s]�l �W�I�ɑ΂��Ĉ��̃_���[�W��^���܂����B \\y%s\\y.]\\y"
#define STRMSG_130828_0004					"\\y[%s]�l �W�I�ɑ΂��郉�X�g�A�^�b�N�ɂȂ�܂����B\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n�̌��j�ɐ������܂����B�����撣���Ă��������B"
// End. 2013-08-28 by bckim, �������� ����ȭ

// 2013-08-14 by jhseol, ������E������E- �¸����� GM �޼���E�Ѹ���E
#define STRMSG_130814_0001					"\\y[%s] NGC���_��ɏ������܂����B\\y"
// end 2013-08-14 by jhseol, ������E������E- �¸����� GM �޼���E�Ѹ���E

// 2014-03-12 by bckim, ����Ÿ��(��E�E���)
#define STRMSG_130318_0001					"%s ���������̃{�X�����X�^�[���������Ă��܂��B"
#define STRMSG_130318_0002					"%s �p�Ђ̓s�s�̃{�X�����X�^�[���������Ă��܂��B"
// End. 2014-03-12 by bckim, ����Ÿ��(��E�E���)

// 2014-03-18 by bckim, ���� ON/OFF
#define STRMSG_130318_0003					"\\y�����_�ł̓g���[�h�V���b�v�𗘗p���鎖���o���܂���B\\y"
// End. 2014-03-18 by bckim, ���� ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
