
// 2005-04-28 by cmkwon
// #include "StringDefineServer.h"
#ifndef _STRING_DEFINE_SERVER_H_
#define _STRING_DEFINE_SERVER_H_

#include "StringDefineCommon.h"


///////////////////////////////////////////////////////////////////////////////
// 1 Atum
	// 1-1 
	#define STRERR_S_ATUMEXE_0001 "Server is not activated."
	#define STRERR_S_ATUMEXE_0002 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMEXE_0003 "Auto update failed.\r\nPlease reinstall the game.\r\n"
	#define STRERR_S_ATUMEXE_0004 "ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRERR_S_ATUMEXE_0005 "Unknown Error: %s(%#04x)"
	#define STRERR_S_ATUMEXE_0006 "Cannot connect to the download server."
	#define STRERR_S_ATUMEXE_0007 "Download files size is unknown."
	#define STRERR_S_ATUMEXE_0008 "Update file cannot be downloaded."
	#define STRERR_S_ATUMEXE_0009 "The system is out of memory or resources."
	#define STRERR_S_ATUMEXE_0010 "The .exe file is invalid."
	#define STRERR_S_ATUMEXE_0011 "File not found."
	#define STRERR_S_ATUMEXE_0012 "The specified path was not found."
// 2006-04-20 by cmkwon, 	#define STRERR_S_ATUMEXE_0013 "[Error]Unknown Message Type: %d(0x%08X)\n"
// 1_end
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// 2 - AtumLauncher
	// 2-1 STRMSG
	#define STRMSG_S_ATUMLAUNCHER_0000 "Update complete"
	#define STRMSG_S_ATUMLAUNCHER_0001 "Please choose a server."
	#define STRMSG_S_ATUMLAUNCHER_0002 "Updating Delete File List v%s\r\n"
	#define STRMSG_S_ATUMLAUNCHER_0003 "Deleting temporary files"
	#define STRMSG_S_ATUMLAUNCHER_0004 "Updating notice"
	#define STRMSG_S_ATUMLAUNCHER_0005 "Update complete (%s -> %s)"
	#define STRMSG_S_ATUMLAUNCHER_0006 "Select operation file"
	#define STRMSG_S_ATUMLAUNCHER_0007 "Select operation path"
	#define STRMSG_S_ATUMLAUNCHER_0008 "Downloading has been cancelled"
	#define STRMSG_S_ATUMLAUNCHER_0009 "Download finished"
	#define STRMSG_S_ATUMLAUNCHER_0010 "Updating to v %s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0011 "Unable to create file %s"
	#define STRMSG_S_ATUMLAUNCHER_0012 "Updating to v%s - %s(%d/%d)"
	#define STRMSG_S_ATUMLAUNCHER_0013 "Aquiring File Information %s"
    #define STRMSG_S_ATUMLAUNCHER_0014 "Update VTC Guard"				// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����
    #define STRMSG_S_ATUMLAUNCHER_0015 ""		// 2012-02-09 by hskim, ���� X-Trap -> VTC ����� ����

	// STRERR
	#define STRERR_S_ATUMLAUNCHER_0000 "[Error] Parameter Count Error, Count(%d)\n"
	#define STRERR_S_ATUMLAUNCHER_0001 "[Error] Mutex Error\n"
	#define STRERR_S_ATUMLAUNCHER_0002 "[Error] Excute Type Error, Type(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0003 "[Error] Decryption ID Error, DecryptedID(%s)\n"
	#define STRERR_S_ATUMLAUNCHER_0004 "Cannot connect to Pre server."
	#define STRERR_S_ATUMLAUNCHER_0005 "Failed to connect to the server."
	#define STRERR_S_ATUMLAUNCHER_0006 "Socket Closed by Pre Server!"
	#define STRERR_S_ATUMLAUNCHER_0007 "Notice File Error!"
//	#define STRERR_S_ATUMLAUNCHER_0008 "Please download the game again.\nURL: http://sco.gpotato.com/\nnewest version: "
	#define STRERR_S_ATUMLAUNCHER_0009 "Auto update failed.\r\nPlease reinstall the game.\r\n"
	#define STRERR_S_ATUMLAUNCHER_0010 "All servers are inactive at this time."
	#define STRERR_S_ATUMLAUNCHER_0011 "%-16s%s under examination..."
	#define STRERR_S_ATUMLAUNCHER_0012 "All servers are under examination. Try logging in later."
	#define STRERR_S_ATUMLAUNCHER_0013 "ERROR %s(%#04X) received from %s[%s]\r\n"
// 2006-05-26 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0014 "Wrong ID, password error\n\n* only people who are certified as beta tester can log in at the present."
	#define STRERR_S_ATUMLAUNCHER_0014 "You have entered an invalid login ID or password.	Please enter a registered login ID and password."
	#define STRERR_S_ATUMLAUNCHER_0015 "Error in login process"
	#define STRERR_S_ATUMLAUNCHER_0016 "User ID not entered"
	#define STRERR_S_ATUMLAUNCHER_0017 "Double log in"
	#define STRERR_S_ATUMLAUNCHER_0018 "F server is not running."
	#define STRERR_S_ATUMLAUNCHER_0019 "I server is not running."
	#define STRERR_S_ATUMLAUNCHER_0020 "Sevice is stopped temporarily.\n\nTry logging in later."
	#define STRERR_S_ATUMLAUNCHER_0021 "There are too many users online.\n\nTry logging in later."

	
	#define STRERR_S_ATUMLAUNCHER_0022 "Your account is currently blocked.\n Period : %s\n\nE-mail www.airrivals.net for further details."
	#define STRERR_S_ATUMLAUNCHER_0023 "The client version is not correct.\n\nPlease download the game again."
	#define STRERR_S_ATUMLAUNCHER_0024 "ERROR: %s(%#04X)"
	#define STRERR_S_ATUMLAUNCHER_0025 "Cannot log in to the download server."
	#define STRERR_S_ATUMLAUNCHER_0026 "Size of the download file(%s)cannot be known."
	#define STRERR_S_ATUMLAUNCHER_0027 "Size of the download file is unknwon."
	#define STRERR_S_ATUMLAUNCHER_0028 "Cannot download the update file."
	#define STRERR_S_ATUMLAUNCHER_0029 "Updated file does not exist."
	#define STRERR_S_ATUMLAUNCHER_0030 "Selected server is under examination. Try logging in later."
	#define STRERR_S_ATUMLAUNCHER_0031 "The system is out of memory or resources."
	#define STRERR_S_ATUMLAUNCHER_0032 "The .exe file is invalid."
	#define STRERR_S_ATUMLAUNCHER_0033 "File cannot be found."
	#define STRERR_S_ATUMLAUNCHER_0034 "Path cannot be found."	
    #define STRERR_S_ATUMLAUNCHER_0035 "Hackshield update is failed."
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0035 "[Error] Unhandled Message Type: %s(%#04X)\n"
// 2006-04-20 by cmkwon	#define STRERR_S_ATUMLAUNCHER_0036 "[Error] Unhandled Message Type!\n"
	#define STRERR_S_ATUMLAUNCHER_0037 "18�� �� ���� ����� ���� ���� ���� ��, ���� ��� ���� ������ ������.\n\n�� ���� ������� ����� ������."		// 2012-07-11 by hskim, ������ ��


	#define STRMSG_S_050506		"\'%s\''s account is blocked presently.\n	reason: %s\n period: %s~%s\n\nVisit http://support.airrivals.net for further details."
	#define STRMSG_S_050930		"Please download the game again.\nURL: %s\nnewest version:"
// 2_end
///////////////////////////////////////////////////////////////////////////////	

///////////////////////////////////////////////////////////////////////////////
// 3 - AtumAdminTool
	// 3-1 STRMSG
//	#define STRMSG_S_SCADMINTOOL_0000 "Male"
//	#define STRMSG_S_SCADMINTOOL_0001 "Female"
//	#define STRMSG_S_SCADMINTOOL_0002 "A.D%d, Age%d"
//	#define STRMSG_S_SCADMINTOOL_0003 "Do you really want to modify your account information?"
//	#define STRMSG_S_SCADMINTOOL_0004 "CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0005 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces attained, ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
//	#define STRMSG_S_SCADMINTOOL_0006 "'''To ' + l.PeerCharacterName + ''', give ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0007 "'''To ' + l.PeerCharacterName + ''', receive ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0008 "'''Discard ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
//	#define STRMSG_S_SCADMINTOOL_0009 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces bought, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0010 "CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces sold, remaining Spi: ' + CAST(l.RemainedMoney AS VARCHAR(10))"
//	#define STRMSG_S_SCADMINTOOL_0011 "CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0012 "'''' + l.PeerCharacterName + ''' added ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0013 "'''' + l.PeerCharacterName + ''' deleted ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'piece'"
	#define STRMSG_S_SCADMINTOOL_0014 "'Add ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces , ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0015 "'Deposit ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total ' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0016 "'Recover ' + CAST(l.ChangeCount AS VARCHAR(10)) + 'pieces, total' + CAST(l.CurrentCount AS VARCHAR(10)) + 'pieces'"
	#define STRMSG_S_SCADMINTOOL_0017 "\'game time \' + dbo.atum_GetHMSFromS(l.PlayTime) + \', whole \' + dbo.atum_GetHMSFromS(l.TotalPlayTime)"
	#define STRMSG_S_SCADMINTOOL_0018 "CAST(l.Param1 AS VARCHAR(10)) + ' -> ' + CAST(l.Param2 AS VARCHAR(10)) + ', game time: ' + dbo.atum_GetHMSFromS(l.Param3)"
//	#define STRMSG_S_SCADMINTOOL_0019 "CAST(l.Param1 AS VARCHAR(15)) + \' rise and fall, whole \' + CAST(l.Param2 AS VARCHAR(15))"
//	#define STRMSG_S_SCADMINTOOL_0020 "Crash"
//	#define STRMSG_S_SCADMINTOOL_0021 "Monster"
//	#define STRMSG_S_SCADMINTOOL_0022 "Gear"
//	#define STRMSG_S_SCADMINTOOL_0023 "Reason unknown"
//	#define STRMSG_S_SCADMINTOOL_0024 "%s, Remaining stat: %s"
	#define STRMSG_S_SCADMINTOOL_0025 "(Do not exist)"
//	#define STRMSG_S_SCADMINTOOL_0026 "myself"
//	#define STRMSG_S_SCADMINTOOL_0027 "Does not exist"
//	#define STRMSG_S_SCADMINTOOL_0028 "User with bug use"
	#define STRMSG_S_SCADMINTOOL_0029 "Account blocked"
	#define STRMSG_S_SCADMINTOOL_0030 "Chatting prohibited"
//	#define STRMSG_S_SCADMINTOOL_0031 "Connection log"
//	#define STRMSG_S_SCADMINTOOL_0032 "User log"
//	#define STRMSG_S_SCADMINTOOL_0033 "Item log"
	#define STRMSG_S_SCADMINTOOL_0034 "%s - %s server"
	#define STRMSG_S_SCADMINTOOL_0035 "%s - %s server,%d(%d)"
	#define STRMSG_S_SCADMINTOOL_0036 "Account seized"
//	#define STRMSG_S_SCADMINTOOL_0037 "Classification    "
//	#define STRMSG_S_SCADMINTOOL_0038 "Value"
	#define STRMSG_S_SCADMINTOOL_0039 "Do you want to unblock this account?"
	#define STRMSG_S_SCADMINTOOL_0040 "%s(%dsecond)"
	#define STRMSG_S_SCADMINTOOL_0041 "%d wins %d losses"
	#define STRMSG_S_SCADMINTOOL_0042 "Are you sure you want to disconnect and block the account?"
	#define STRMSG_S_SCADMINTOOL_0043 "%s item"
	#define STRMSG_S_SCADMINTOOL_0044 "[%s %15s] Notice : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0045 "Number of users : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0046 "[%s %15s] Received message : %s\r\n"
	#define STRMSG_S_SCADMINTOOL_0047 "[%s %15s] number of users : %4d\r\n"
	#define STRMSG_S_SCADMINTOOL_0048 "[%s %15s] FieldServer state : %d\r\n"
	#define STRMSG_S_SCADMINTOOL_0049 "Connection to the server has been lost\nSocket Name: %s\nIP: %s"
	
	// 3-2 AtumAdminTool - STRERR
	#define STRERR_S_SCADMINTOOL_0000 "Cannot load corresponding account information."
	#define STRERR_S_SCADMINTOOL_0001 "Failed to modify account information."
	#define STRERR_S_SCADMINTOOL_0002 "Enter your password"
	#define STRERR_S_SCADMINTOOL_0003 "Password authentication failed"
	#define STRERR_S_SCADMINTOOL_0004 "Enter log in name"
	#define STRERR_S_SCADMINTOOL_0005 "Pre Server is not executed."
	#define STRERR_S_SCADMINTOOL_0006 "Cannot connect to the PreServer!"
//	#define STRERR_S_SCADMINTOOL_0007 " "			// 2006-04-11 by cmkwon, 
	#define STRERR_S_SCADMINTOOL_0008 "ERROR: corresponding protocol does not exist."
	#define STRERR_S_SCADMINTOOL_0009 "Enter username"
	#define STRERR_S_SCADMINTOOL_0010 "Enter reason"
	#define STRERR_S_SCADMINTOOL_0011 "Experience point set up error : Level %2d ==> Exp(%.1I64f ~ %.1I64f)"
	#define STRERR_S_SCADMINTOOL_0012 "Maximum log number exceeded.\r\n\r\nPlease modify the number of the maximum log or the search condition."
	#define STRERR_S_SCADMINTOOL_0013 "Cannot connect to the database."
	#define STRERR_S_SCADMINTOOL_0014 "Not connected"
	#define STRERR_S_SCADMINTOOL_0015 "Connected"
	#define STRERR_S_SCADMINTOOL_0016 "Updating"
	#define STRERR_S_SCADMINTOOL_0017 "Logged in"
	#define STRERR_S_SCADMINTOOL_0018 "Choosing character"
	#define STRERR_S_SCADMINTOOL_0019 "Playing game"
	#define STRERR_S_SCADMINTOOL_0020 "Unknown"
	#define STRERR_S_SCADMINTOOL_0021 "Database %s(%s:%d)cannot be connected."
	#define STRERR_S_SCADMINTOOL_0022 "Failed to add item"
	#define STRERR_S_SCADMINTOOL_0023 "Failed to find blocked account."
	#define STRERR_S_SCADMINTOOL_0024 "First, disconnect from the account and block it to modify."
	#define STRERR_S_SCADMINTOOL_0025 "SPI(money) cannot be added."
	#define STRERR_S_SCADMINTOOL_0026 "Selected item already exists, so modify the amount."
	#define STRERR_S_SCADMINTOOL_0027 "Error finding item"
	#define STRERR_S_SCADMINTOOL_0028 "SPI(money) possessed by the character cannot be deleted."
	#define STRERR_S_SCADMINTOOL_0029 "Do you want to delete this item?"
	#define STRERR_S_SCADMINTOOL_0030 "Failed to delete item."
	#define STRERR_S_SCADMINTOOL_0031 "Failed to modify item."
	#define STRERR_S_SCADMINTOOL_0032 "Enter the account"
	#define STRERR_S_SCADMINTOOL_0033 "Account does not exist. (Account may possibly be blocked)"
	#define STRERR_S_SCADMINTOOL_0034 "Account or character does not exist."
	#define STRERR_S_SCADMINTOOL_0035 "Error in character information search."
	#define STRERR_S_SCADMINTOOL_0036 "Corresponding character does not exist"
	#define STRERR_S_SCADMINTOOL_0037 "Error in character update."
	#define STRERR_S_SCADMINTOOL_0038 "Character information has been updated succesfully."
	#define STRERR_S_SCADMINTOOL_0039 "Choose an item."
	#define STRERR_S_SCADMINTOOL_0040 "Choose the number of items."
	#define STRERR_S_SCADMINTOOL_0041 "Corresponding item can be created under 5 pieces."
	#define STRERR_S_SCADMINTOOL_0042 "Enter the message."
	#define STRERR_S_SCADMINTOOL_0043 "Notice cannot be sent."
	#define STRERR_S_SCADMINTOOL_0044 "%s: server state(%d)\r\n"
	#define STRERR_S_SCADMINTOOL_0045 "IM Server is not executed."
	#define STRERR_S_SCADMINTOOL_0046 "Field Server is not running."
	#define STRERR_S_SCADMINTOOL_0047 "[%s %15s] IMServer state : %d\r\n"
///////////////////////////////////////////////////////////////////////////////
// 2012-03-15 by jhseol, �� - ���� �� �� ��� ���� MSG
#define STRERR_S_SCADMINTOOL_0048 "This item slot is installed on your P.E.D. You can remove the slot using the command \remove socket."
#define STRERR_S_SCADMINTOOL_0049 "Error in saving the P.E.D. change (although the change has been carried out)."
#define STRERR_S_SCADMINTOOL_0050 "Error in loading the P.E.D. information."
#define STRERR_S_SCADMINTOOL_0051 "The equipped item slot could not be deleted."
#define STRERR_S_SCADMINTOOL_0052 "Error in using the hidden bonus for the equipped items."
#define STRERR_S_SCADMINTOOL_0053 "Error in changing the P.E.D. item slot."
#define STRERR_S_SCADMINTOOL_0054 "The P.E.D. information could not be updated."
#define STRERR_S_SCADMINTOOL_0055 "Error in loading the information about the P.E.D. level."

///////////////////////////////////////////////////////////////////////////////
// 2012-11-21 by bckim, ������á, �������۰��
#define STRERR_S_SCADMINTOOL_0056 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count Enchanted,  Current :  ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRERR_S_SCADMINTOOL_0057 "'''' + l.PeerCharacterName + '''worked ['+CAST(l.EnchantCardNumber AS VARCHAR(10)) + '] : ' + CAST(l.ChangeEnchantCount AS VARCHAR(10)) + ' Count DisEnchanted,  Current : ' + CAST(l.ResultEnchantCount AS VARCHAR(10)) + ' Enchant'"
#define STRMSG_S_SCADMINTOOL_0058 "( ======== !! Completely DisEnchant !! ======= )"
// 2012-11-21 by bckim, ������á, �������۰��. End



	// 3-3 AtumLaAtumAdminTool -
//	#define STRMSG_S_SCAT_COLNAME_0000 "Account name"
//	#define STRMSG_S_SCAT_COLNAME_0001 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0002 "Conviction"
//	#define STRMSG_S_SCAT_COLNAME_0003 "Start date"
//	#define STRMSG_S_SCAT_COLNAME_0004 "Finish date"
//	#define STRMSG_S_SCAT_COLNAME_0005 "Handling person"
//	#define STRMSG_S_SCAT_COLNAME_0006 "Handling reason"
//	#define STRMSG_S_SCAT_COLNAME_0007 "Date"
//	#define STRMSG_S_SCAT_COLNAME_0008 "Log type"
//	#define STRMSG_S_SCAT_COLNAME_0009 "IPAddress"
//	#define STRMSG_S_SCAT_COLNAME_0010 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0011 "Character name"
//	#define STRMSG_S_SCAT_COLNAME_0012 "Location"
//	#define STRMSG_S_SCAT_COLNAME_0013 "Contents"
//	#define STRMSG_S_SCAT_COLNAME_0014 "Item"
//	#define STRMSG_S_SCAT_COLNAME_0015 "UID"
//	#define STRMSG_S_SCAT_COLNAME_0016 "Own number"
//	#define STRMSG_S_SCAT_COLNAME_0017 "Name"
//	#define STRMSG_S_SCAT_COLNAME_0018 "Item number"
//	#define STRMSG_S_SCAT_COLNAME_0019 "Prefix"
//	#define STRMSG_S_SCAT_COLNAME_0020 "Suffix"
	#define STRMSG_S_SCAT_COLNAME_0021 "Equip"
//	#define STRMSG_S_SCAT_COLNAME_0022 "Amount"
//	#define STRMSG_S_SCAT_COLNAME_0023 "Endurance"
//	#define STRMSG_S_SCAT_COLNAME_0024 "Create time"
	#define STRMSG_S_SCAT_COLNAME_0025 "Not equipped"
//	#define STRMSG_S_SCAT_COLNAME_0026 "Warehouse"
//	#define STRMSG_S_SCAT_COLNAME_0027 "Auction"
//	#define STRMSG_S_SCAT_COLNAME_0028 "Map"
//	#define STRMSG_S_SCAT_COLNAME_0029 "Coordinate"
//	#define STRMSG_S_SCAT_COLNAME_0030 "Sex"
//	#define STRMSG_S_SCAT_COLNAME_0031 "Race"
//	#define STRMSG_S_SCAT_COLNAME_0032 "Authority"
//	#define STRMSG_S_SCAT_COLNAME_0033 "Unit kind"
//	#define STRMSG_S_SCAT_COLNAME_0034 "Level"
//	#define STRMSG_S_SCAT_COLNAME_0035 "Maximum level"
//	#define STRMSG_S_SCAT_COLNAME_0036 "Experience point"
//	#define STRMSG_S_SCAT_COLNAME_0037 "Decreased experience point"
//	#define STRMSG_S_SCAT_COLNAME_0038 "Auto stat division type"
//	#define STRMSG_S_SCAT_COLNAME_0039 "Attack"
//	#define STRMSG_S_SCAT_COLNAME_0040 "Defense"
//	#define STRMSG_S_SCAT_COLNAME_0041 "Fuel"
//	#define STRMSG_S_SCAT_COLNAME_0042 "Spirit"
//	#define STRMSG_S_SCAT_COLNAME_0043 "Shield"
//	#define STRMSG_S_SCAT_COLNAME_0044 "Agility"
//	#define STRMSG_S_SCAT_COLNAME_0045 "Attached regiment"
//	#define STRMSG_S_SCAT_COLNAME_0046 "Propensity"
//	#define STRMSG_S_SCAT_COLNAME_0047 "social position"
//	#define STRMSG_S_SCAT_COLNAME_0048 "Whole connection time"
//	#define STRMSG_S_SCAT_COLNAME_0049 "Generated time"
//	#define STRMSG_S_SCAT_COLNAME_0050 "Final log in time"
//	#define STRMSG_S_SCAT_COLNAME_0051 "Type"
//	#define STRMSG_S_SCAT_COLNAME_0052 "Whole"
	#define STRMSG_S_SCAT_COLNAME_0053 "Automatic type(1-1type)"
	#define STRMSG_S_SCAT_COLNAME_0054 "Valkan Type (1-1 Type)"	
	#define STRMSG_S_SCAT_COLNAME_0055 "Dualist Type (1-1 Type)" // 2005-08-01 by hblee : Grenade -> changed to dualist.
	#define STRMSG_S_SCAT_COLNAME_0056 "Cannon Type (1-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0057 "Rifle Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0058 "Gatling Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0059 "Launcher Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0060 "Mass Drive Type (1-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0061 "Rocket Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0062 "Missile Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0063 "Bundle Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0064 "Mine Type (2-1 Type)"
	#define STRMSG_S_SCAT_COLNAME_0065 "Shield Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0066 "Dummy Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0067 "Pixer Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0068 "Decoy Type (2-2 Type)"
	#define STRMSG_S_SCAT_COLNAME_0069 "Defence Type"
	#define STRMSG_S_SCAT_COLNAME_0070 "Support Equipment Type"
	#define STRMSG_S_SCAT_COLNAME_0071 "Energy Type"
	#define STRMSG_S_SCAT_COLNAME_0072 "Metal Type"
	#define STRMSG_S_SCAT_COLNAME_0073 "Card Type"
	#define STRMSG_S_SCAT_COLNAME_0074 "Upgrade Type"
	#define STRMSG_S_SCAT_COLNAME_0075 "Tank Type"
	#define STRMSG_S_SCAT_COLNAME_0076 "Bullet Type"
	#define STRMSG_S_SCAT_COLNAME_0077 "For Mission"
	#define STRMSG_S_SCAT_COLNAME_0078 "Radar Type"
	#define STRMSG_S_SCAT_COLNAME_0079 "Computer Type"
	#define STRMSG_S_SCAT_COLNAME_0080 "Gamble Card Type"
	#define STRMSG_S_SCAT_COLNAME_0081 "Upgrade Destruction Prevention Type"		// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0082 "Blaster Type"				// 2005-08-02 by cmkwon
	#define STRMSG_S_SCAT_COLNAME_0083 "Rail Gun Type"				// 2005-08-02 by cmkwon
//	#define STRMSG_S_SCAT_COLNAME_0081 "Whole item"
//	#define STRMSG_S_SCAT_COLNAME_0082 "Whole server"
//	#define STRMSG_S_SCAT_COLNAME_0083 "Server name"
//	#define STRMSG_S_SCAT_COLNAME_0084 "Server type"
//	#define STRMSG_S_SCAT_COLNAME_0085 "Server IP, Port"
//	#define STRMSG_S_SCAT_COLNAME_0086 "Present number of users"
//	#define STRMSG_S_SCAT_COLNAME_0087 "Server condition"
//	#define STRMSG_S_SCAT_COLNAME_0088 "Group server"
//	#define STRMSG_S_SCAT_COLNAME_0089 "Field server"
//	#define STRMSG_S_SCAT_COLNAME_0090 "Unknown"
//	#define STRMSG_S_SCAT_COLNAME_0091 "Not executed"
//	#define STRMSG_S_SCAT_COLNAME_0092 "Normal"
//	#define STRMSG_S_SCAT_COLNAME_0093 "Abnormal"
	#define STRMSG_S_SCAT_COLNAME_0094 "Administrator"

	#define STRMSG_S_SCADMINTOOL_050512_0000	"CAST(l.CurrentCount AS VARCHAR(10)) + '��, Param1:' + CAST(l.Param1 AS VARCHAR(10))"
// 3_end
///////////////////////////////////////////////////////////////////////////////
	
	
///////////////////////////////////////////////////////////////////////////////
// 4
	// 4-1 AtumMonitor - STRMSG
//	#define STRMSG_S_SCMONITOR_0000 "Command list\r\n"
//	#define STRMSG_S_SCMONITOR_0001 "----- List of backup account ---------------------------------------\r\n"
//	#define STRMSG_S_SCMONITOR_0002 "  Account: \'%s\', Original password: \'%s\', Temporary password: \'%s\'\r\n"
//	#define STRMSG_S_SCMONITOR_0003 "  Account: \'%s\' \r\n"
//	#define STRMSG_S_SCMONITOR_0004 "Please choose the folder where Versions for update are located"
//	#define STRMSG_S_SCMONITOR_0005 "\r\nMaking New Zip File From %s To %s...\r\n"
//	#define STRMSG_S_SCMONITOR_0006 "Rename Server Group"
//	#define STRMSG_S_SCMONITOR_0007 "File has been succesfully created.\r\n\r\nDB information: %s(%d), %s"
//	#define STRMSG_S_SCMONITOR_0008 "%04d(%2d -  active) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0009 "%04d(%2d -inactive) %3d/%3d"
//	#define STRMSG_S_SCMONITOR_0010 "Servers data has been succesfully reloaded."
//	#define STRMSG_S_SCMONITOR_0011 "Service condition has been succesfully reflected."
//	#define STRMSG_S_SCMONITOR_0012 "%04d(%2d -  active)"
//	#define STRMSG_S_SCMONITOR_0013 "%04d(%2d -inactive)"
//	#define STRMSG_S_SCMONITOR_0014 "Version Info List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0015 "Blocked Account List Reload DONE!"
//	#define STRMSG_S_SCMONITOR_0016 "Free server service has been stopped."
//	#define STRMSG_S_SCMONITOR_0017 "Free server service started."
//	#define STRMSG_S_SCMONITOR_0018 "Field server is not executed"
//	#define STRMSG_S_SCMONITOR_0019 "Do you really want to close Field Server?"
//	#define STRMSG_S_SCMONITOR_0020 "Update version list information(Maximum 1492 Bytes)\r\n\r\n    Number of version list[%3d], Data capacity[%4dBytes]"
//	#define STRMSG_S_SCMONITOR_0021 "Do you really want to close Pre Server?"
//	#define STRMSG_S_SCMONITOR_0022 "Do you really want to close IM Server?"
//	#define STRMSG_S_SCMONITOR_0023 "Do you really want to close NPC Server?"
//	#define STRMSG_S_SCMONITOR_0024 "%Yyear %mmonth %dday %Hhour %Mminute %Ssecond"
//	#define STRMSG_S_SCMONITOR_0025 "No event(%d)"
//	#define STRMSG_S_SCMONITOR_0026 "Open beta attendance event(%d)"
//	#define STRMSG_S_SCMONITOR_0027 "Do not know event(%d)"
//	#define STRMSG_S_SCMONITOR_0028 "Set up time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0029 "Standard time for next occupying battle"
//	#define STRMSG_S_SCMONITOR_0030 "Occupying brigade"

	// 4-2 AtumMonitor - STRERR
//	#define STRERR_S_SCMONITOR_0000 "  ==> Command succesful.\r\n"
//	#define STRERR_S_SCMONITOR_0001 "  ==> Command failed.\r\n"
//	#define STRERR_S_SCMONITOR_0002 "Cannot connect to the DB."
//	#define STRERR_S_SCMONITOR_0003 "Corresponding Version do not exist"
//	#define STRERR_S_SCMONITOR_0004 "Please enter name of the folder that you want to compress"
//	#define STRERR_S_SCMONITOR_0005 "Please enter name of the folder that you want to output"
//	#define STRERR_S_SCMONITOR_0006 "Please enter start version"
//	#define STRERR_S_SCMONITOR_0007 "Please enter last version"
//	#define STRERR_S_SCMONITOR_0008 "Please choose the folder that you are going to output Zip file for update"
//	#define STRERR_S_SCMONITOR_0009 "Cannot connect file"
//	#define STRERR_S_SCMONITOR_0010 "Please choose the server!"
//	#define STRERR_S_SCMONITOR_0011 "Cannot connect to the DB"
//	#define STRERR_S_SCMONITOR_0012 "[Error]Unable to process Message Type: %s(%#04x) in CLeftView::OnSocketNotify()\n"
//	#define STRERR_S_SCMONITOR_0013 "There is too many update version list.(Version list number[%3d], Data capacity[%4dBytes])\r\n\r\n    You must arrange version list."
//	#define STRERR_S_SCMONITOR_0014 "Eliminated function.\r\nPlease use management tool."
//	#define STRERR_S_SCMONITOR_0015 "This is not a city occupying map"
//	#define STRERR_S_SCMONITOR_0016 "Cannot make EDIT control."
//	#define STRERR_S_SCMONITOR_0017 "You have already registered existing file."

// 4_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 5 - FieldServer
	// 5-1 Field<->Log
	#define STRMSG_S_F2LOGCONNECT_0000 "[Error] WndProc(), Can't connect to LogServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2LOGCONNECT_0001 "Logged into Log Server.\n"
	#define STRMSG_S_F2LOGCONNECT_0002 "Connection to Log Server[%15s:%4d]has been lost. Trying reconnection.\r\n"

	// 5-2 Field<->Pre
	#define STRMSG_S_F2PRECONNECT_0000 "[Error] WndProc(), Can't connect to PreServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2PRECONNECT_0001 "Logged into Pre Server.\n"
	#define STRMSG_S_F2PRECONNECT_0002 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2PRECONNECT_0003 "Unknown Error@WM_PRE_PACKET_NOTIFY: %s(%#04x)\n"
	#define STRMSG_S_F2PRECONNECT_0004 "Connection to Pre Server[%15s:%4d]has been lost. Trying reconnection.\r\n"

	// 5-3 Field<->IM
	#define STRMSG_S_F2IMCONNECT_0000 "[Error] WndProc(), Can't connect to	IMServer[%15s:%4d] Reconnect\r\n"
	#define STRMSG_S_F2IMCONNECT_0001 "Logged into IM Server.\n"
	#define STRMSG_S_F2IMCONNECT_0002 "Connection to IM Server[%15s:%4d]has been lost. Trying reconnection.\r\n"
	#define STRMSG_S_F2IMCONNECT_0003 "T_ERROR %s(%#04X) received from %s[%s]\r\n"
	#define STRMSG_S_F2IMCONNECT_0004 "Unknown Error@WM_IM_PACKET_NOTIFY: %s(%#04x)\n"

	// 5-3 Field - DB
	#define STRMSG_S_F2DBQUERY_0000 "No such DB query In Field Server Queries! %d\n"
	#define STRMSG_S_F2DBQUERY_0001 "Corresponding item does not exist."
	#define STRMSG_S_F2DBQUERY_0002 "'%s'has applied for attendance, so promised item"
	#define STRMSG_S_F2DBQUERY_0003 "is given. Press F5 to check your inventory"
	#define STRMSG_S_F2DBQUERY_0004 "Skill %s(%d)has been added"
	#define STRMSG_S_F2DBQUERY_0005 "Corresponding item does not exist."
	#define STRMSG_S_F2DBQUERY_0006 "Failed to purchase item."

	// 5-4 Field - CityWar
	#define STRMSG_S_F2CITYWAR_0000 "City occupation battle start : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0001 "Participating brigade : GuildUID(%4d) GuildName(%10s) GuildMaster(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0002 "City occupation battle monster explosion : %d(%10s) occGuildName(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0003 "Damage sum total ==> GuildName(%10s) SumOfDamage(%8.2f)\r\n"
	#define STRMSG_S_F2CITYWAR_0004 "City occupation battle : %d(%10s) CityMapIndex(%d) QuestIndex(%d) OccGuildID(%d) OccGuildName(%s) OccGuildMasterUID(%d) �������ð�(%s)\r\n"
	#define STRMSG_S_F2CITYWAR_0005 "[Error] SetCityWarState_ DBError, MapIndex(%d)\r\n"
	#define STRMSG_S_F2CITYWAR_0006 "After %d minutes, \"%s\" city occupation battle will start."
	#define STRMSG_S_F2CITYWAR_0007 "After %d minutes, \"%s\" city occupation battle will be finished."
	#define STRMSG_S_F2CITYWAR_0008 "Monster summoned for city occupation battle(%s) : NPC occupying"
	#define STRMSG_S_F2CITYWAR_0009 "Monster summoned for city occupation battle(%s) : %s brigade occupying"
	#define STRMSG_S_F2CITYWAR_0010 "\"NPC\" is occupying \"%s\" presently."
	#define STRMSG_S_F2CITYWAR_0011 "\"%s\" bridgade is occupying \"%s\" presently."

	// 5-4 Field - Quest
	#define STRMSG_S_F2QUEST_0000 "Failed to load mission"
	#define STRMSG_S_F2QUEST_0001 "Mission has not been loaded.\r\n"
//	#define STRMSG_S_F2QUEST_0002 " \'%30s\'  %d -> OK\r\n"

	// 5-4 Field - config
	#define STRMSG_S_F2CONFIG_0000 "Server for test has been set! \r\n\r\nLoadFieldServerDataDebug() needs to be eliminated!"
	#define STRMSG_S_F2NOTIFY_0000 "splash %d: %dto %5.2f(%2.1f%%)"
	#define STRMSG_S_F2NOTIFY_0001 "monster splash %d: %sto %5.2f"
	#define STRMSG_S_F2NOTIFY_0002 "1st type"
	#define STRMSG_S_F2NOTIFY_0003 "2nd type"
	#define STRMSG_S_F2NOTIFY_0004 "Mon1(%s)"
	#define STRMSG_S_F2NOTIFY_0005 "Mon2(%s)"
	#define STRMSG_S_F2NOTIFY_0006 "Wrong weapon type! Please make an inquiry to the administrator!"
	#define STRMSG_S_F2NOTIFY_0007 "1-1type: %4.1f vs %4.1f -> Attack probability reduced by %2.2f%%"
	#define STRMSG_S_F2NOTIFY_0008 "%s->%s fail, probability(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0009 "%s->%s fail, probability(%d>%5.2f) -%5.2f"
	#define STRMSG_S_F2NOTIFY_0010 "%s->%s fail, probability(%d>%5.2f)"
	#define STRMSG_S_F2NOTIFY_0011 "1-2type: %4.1f vs %4.1f -> Damage reduced by %2.2f%%(%4.1f->%4.1f)"
	#define STRMSG_S_F2NOTIFY_0012 "%s->%s, gives %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0013 "%s->%s, receives %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0014 "%s->%s(%d, HP:%5.2f), gives %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0015 "%s->%s, receives %5.2f(%5.2f-%d/255) (%d<=%5.2f)"
	#define STRMSG_S_F2NOTIFY_0016 "Dummy failed: Probability insufficient > %d"
	#define STRMSG_S_F2NOTIFY_0017 "Remaining dummy[%#08x]: %5.2f(%5.2f-%5.2f)"
	#define STRMSG_S_F2NOTIFY_0018 "Bullet information does not exist. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0019 "Information about bullets calibre does not exist. %s %d"
	#define STRMSG_S_F2NOTIFY_0020 "This is the bullet's information. %s %d"
	#define STRMSG_S_F2NOTIFY_0021 "Warp is not possible while event is in progress"
	#define STRMSG_S_F2NOTIFY_0022 "Warp is not possible when you are dead."
	#define STRMSG_S_F2NOTIFY_0023 "Warp is not possible if you are in a formation battle"
	#define STRMSG_S_F2NOTIFY_0024 "Map production error! Please make an inquiry to the administrator!"
	#define STRMSG_S_F2NOTIFY_0025 "Map production error! Please make an inquiry to the administrator! At %d, %d number warp target index does not exist!\r\n"
	#define STRMSG_S_F2NOTIFY_0026 "Warp is not possible if formation fight is not finished"
	#define STRMSG_S_F2NOTIFY_0027 "WARP(%04d) treatment not possible at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0028 "1 -> Character %10s ,receives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0029 "1 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0030 "1 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0031 "1 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0032 "2 -> Character %10s ,receives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0033 "2 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0034 "2 -> Monster %3d ,gives damage %5.2f(%d)"
	#define STRMSG_S_F2NOTIFY_0035 "2 -> Character %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0036 "2 -> Character %10s ,gives dummy damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0037 "2 -> Monster %3d ,receives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0038 "MINE -> Character %10s , gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0039 "MINE -> Character %10s ,gives dummy damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0040 "MINE -> Monster %10s ,gives damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0041 "Stat initialization has been successful."
	#define STRMSG_S_F2NOTIFY_0042 "Unable to use this when you are dead"
	#define STRMSG_S_F2NOTIFY_0043 "UPGRADE_INFO does not exist"
	#define STRMSG_S_F2NOTIFY_0044 "Upgrade successful."
	#define STRMSG_S_F2NOTIFY_0045 "Upgrade failed."
	#define STRMSG_S_F2NOTIFY_0046 "Does not belong to the brigade."
	#define STRMSG_S_F2NOTIFY_0047 "Already in a standby state for the request."
	#define STRMSG_S_F2NOTIFY_0048 "Please try again later."
	#define STRMSG_S_F2NOTIFY_0049 "You or the other person is the brigade leader."
	#define STRMSG_S_F2NOTIFY_0050 "Already in brigade fight."
	#define STRMSG_S_F2NOTIFY_0051 "Both brigade leaders are not in the same map."
	#define STRMSG_S_F2NOTIFY_0052 "Not all formation members are in the same map"
	#define STRMSG_S_F2NOTIFY_0053 "Not all formation members are in the same map"
	#define STRMSG_S_F2NOTIFY_0054 "You do not belong to the brigade."
	#define STRMSG_S_F2NOTIFY_0055 "The receiving applicant is different."
	#define STRMSG_S_F2NOTIFY_0056 "You or the other person is not a brigade leader."
	#define STRMSG_S_F2NOTIFY_0057 "Two brigade leaders do not exist in the same map."
	#define STRMSG_S_F2NOTIFY_0058 "You do not belong to the brigade."
	#define STRMSG_S_F2NOTIFY_0059 "The receiving applicant is different."
	#define STRMSG_S_F2NOTIFY_0060 "You or the other person is not a brigade leader."
	#define STRMSG_S_F2NOTIFY_0061 "Successful in city occupying battle defence"
	#define STRMSG_S_F2NOTIFY_0062 "Mission setup error. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0063 "Corresponding item(%s) cannot be fitted at this location"
	#define STRMSG_S_F2NOTIFY_0064 "Engine cannot be vacated."
	#define STRMSG_S_F2NOTIFY_0065 "Item move: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0066 "Wrong item movement: (%I64d, %d) -> (%I64d, %d)"
	#define STRMSG_S_F2NOTIFY_0067 "EVENT(%d) unable to handle at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRMSG_S_F2NOTIFY_0068 "Map event information abnormal! Please make an inquiry to the administrator!"
	#define STRMSG_S_F2NOTIFY_0069 "Corresponding warp target does not exist"
	#define STRMSG_S_F2NOTIFY_0070 "Item purchase error. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0071 "Skill level that you want to purchase is lower or at your current level."
	#define STRMSG_S_F2NOTIFY_0072 "Item error.	Item needs a skill purchase."
	#define STRMSG_S_F2NOTIFY_0073 "Item selling error. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0074 "Item purchase error. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0075 "\'Credit item\'has been purchased."
	#define STRMSG_S_F2NOTIFY_0076 "purchase list : \'%s(%dpieces)\'"
	#define STRMSG_S_F2NOTIFY_0077 "Already joined the party."
	#define STRMSG_S_F2NOTIFY_0078 "Unable to join if you are the party leader"
	#define STRMSG_S_F2NOTIFY_0079 "Cannot join if formation battle is under progress."
	#define STRMSG_S_F2NOTIFY_0080 "Bringing up all formation personnel information is not supported!"
	#define STRMSG_S_F2NOTIFY_0081 "Map event information abnormal! Please make an inquiry to the administrator!"
	#define STRMSG_S_F2NOTIFY_0082 "This is an account that cannot make a transaction"
	#define STRMSG_S_F2NOTIFY_0083 "%s's loading capacity exceeded."
	#define STRMSG_S_F2NOTIFY_0084 "Possible movement coordination: (5, 5) -> (%d, %d)"
	#define STRMSG_S_F2NOTIFY_0085 "User:"
	#define STRMSG_S_F2NOTIFY_0086 "Maximum of 20 people can be seen."
	#define STRMSG_S_F2NOTIFY_0087 "Corresponding user (%s) do not exist"
	#define STRMSG_S_F2NOTIFY_0088 "Does not belong to the party"
	#define STRMSG_S_F2NOTIFY_0089 "Present time: %d:%d, Artum time: %d:%d"
	#define STRMSG_S_F2NOTIFY_0090 "Changed time: %d:%d, Artum time: %d:%d"
	#define STRMSG_S_F2NOTIFY_0091 "Not connected to the NPC server"
	#define STRMSG_S_F2NOTIFY_0092 "Corresponding item(%d) does not exist"
	#define STRMSG_S_F2NOTIFY_0093 "Limited to 10 pieces if it is not a countable item"
	#define STRMSG_S_F2NOTIFY_0094 "Map \'%s\' 's whole number of connected person: %dpeople"
	#define STRMSG_S_F2NOTIFY_0095 "Map %s %s simultaneous connections: %d people - '%s'(*)"
	#define STRMSG_S_F2NOTIFY_0096 "Map %s %s simultaneous connections: %d people - '%s'"
	#define STRMSG_S_F2NOTIFY_0097 "Present map channel: %s, %d(%d)"
	#define STRMSG_S_F2NOTIFY_0098 "Information of bullets do not exist. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0099 "Information about bullets calibre does not exist. %s %d"
	#define STRMSG_S_F2NOTIFY_0100 "Information about bullets does not exist. Please make an inquiry to the administrator."
	#define STRMSG_S_F2NOTIFY_0101 "Information about bullets calibre does not exist. %s %d"
	#define STRMSG_S_F2NOTIFY_0102 "Corresponding user (%s) does not exist"
	#define STRMSG_S_F2NOTIFY_0103 "Corresponding user (%s) is dead"
	#define STRMSG_S_F2NOTIFY_0104 "Corresponding users (%s) do not exist"
	#define STRMSG_S_F2NOTIFY_0105 "Set as a Standard Account"
	#define STRMSG_S_F2NOTIFY_0106 "Standard Account has been cancelled"
	#define STRMSG_S_F2NOTIFY_0107 "Invincibility has been turned on."
	#define STRMSG_S_F2NOTIFY_0108 "Invincibility has been turned off."
	#define STRMSG_S_F2NOTIFY_0109 "Weapon damage will be modified by %5.0f%%"
	#define STRMSG_S_F2NOTIFY_0110 "Will be initialized when reloading the item"
	#define STRMSG_S_F2NOTIFY_0111 "Will be initialized when reloading the item"
	#define STRMSG_S_F2NOTIFY_0112 "Corresponding user (%s) does not exist"
	#define STRMSG_S_F2NOTIFY_0113 "Invisibility has been deactivated."
	#define STRMSG_S_F2NOTIFY_0114 "Invisibility has been activated."
	#define STRMSG_S_F2NOTIFY_0115 "%s event is not under progress"
	#define STRMSG_S_F2NOTIFY_0116 "%s event has started (magnification:%4.2f, Event time:%3d minutes)"
	#define STRMSG_S_F2NOTIFY_0117 "Set as standard premium account"
	#define STRMSG_S_F2NOTIFY_0118 "Failed to set as a premium account"
	#define STRMSG_S_F2NOTIFY_0119 "Set as a super premium account"
	#define STRMSG_S_F2NOTIFY_0120 "This is not the map for city occupying battle"
	#define STRMSG_S_F2NOTIFY_0121 "City occupying battle cannot be started"
	#define STRMSG_S_F2NOTIFY_0122 "City occupying battle cannot be finished"
	#define STRMSG_S_F2NOTIFY_0123 "Stealth mode has been initialized"
	#define STRMSG_S_F2NOTIFY_0124 "In stealth state"
	#define STRMSG_S_F2NOTIFY_0125 "Map is not validated."
	#define STRMSG_S_F2NOTIFY_0126 "Happy hour event set [progress time:%4dminute)]"
	#define STRMSG_S_F2NOTIFY_0127 "Happy hour event finished"
	#define STRMSG_S_F2NOTIFY_0128 "1 -> From monster %3d ,received damage %5.2f"
	#define STRMSG_S_F2NOTIFY_0129 "1type -> From monster %3d ,received damage %5.2f(dummy)"
	#define STRMSG_S_F2NOTIFY_0130 "Logged in with %s authority"
	#define STRMSG_S_F2NOTIFY_0131 "Do not process completing routine %s: CS(%d), DBStore(%d)\r\n"
	#define STRMSG_S_F2NOTIFY_0132 "ERROR@CharacterGameEndRoutine(): Failed to eliminate party personnel! %s\r\n"
// 2005-11-24 by cmkwon, 
//	#define STRMSG_S_F2NOTIFY_0133 "Prefix \'%s\' : %d <= %d <= %d\r\n"
//	#define STRMSG_S_F2NOTIFY_0134 "Suffix \'%s\' : %d <= %d <= %d\r\n"
	#define STRMSG_S_F2NOTIFY_0135 "%s: Stopped!"
	#define STRMSG_S_F2NOTIFY_0136 "FATAL ERROR: Please make an inquiry to the administrator! Shop variable allotment error!"
	#define STRMSG_S_F2NOTIFY_0137 "%s is deleted."
	#define STRMSG_S_F2NOTIFY_0138 "The channel that you are currently using is deactivated so monsters and other functions are not available."
	#define STRMSG_S_F2NOTIFY_0139 "Stopped. Please use another channel."
	#define STRMSG_S_F2NOTIFY_0140 "Warp Obj.[%s,%2dpieces]: %04d[%1s%4d]"
	#define STRMSG_S_F2NOTIFY_0141 "Timer movement %s\r\n"
	#define STRMSG_S_F2NOTIFY_0142 "HP auto recovery stopped"
	#define STRMSG_S_F2NOTIFY_0143 "HP auto recovery has stopped as this is not a possible location for landing"
	#define STRMSG_S_F2NOTIFY_0144 "HP 5.2f recovery for emergency"
	#define STRMSG_S_F2NOTIFY_0145 "Gradual HP UP Stopped (remaining time: %d)"
	#define STRMSG_S_F2NOTIFY_0146 "Gradual DP UP Stopped(remaining time: %d)"
	#define STRMSG_S_F2NOTIFY_0147 "Gradual EP UP Stopped(remaining time: %d)"
	#define STRMSG_S_F2NOTIFY_0148 "%s event has been completed."
	#define STRMSG_S_F2NOTIFY_0149 "%s event under progress (magnification %4.2f, remaining:%3dminute)"
	#define STRMSG_S_F2NOTIFY_0150 "Command has not been exercised"


	// 5-5 Field - NOTIFY Error
	#define STRERR_S_F2NOTIFY_0000 "Experience point division error(%s, %s(%d)): fTotalDamage(%d) < 0.0f or Empty Vector: %d, Distance(%5.1f)\n"
	#define STRERR_S_F2NOTIFY_0001 "Not valid Game Start message error ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0002 "Not valid Game Start message error ClientState[%d]\r\n"
	#define STRERR_S_F2NOTIFY_0003 "WARP(%04d) treatment impossible at ProcessQuestResult(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0004 "Map event information abnormal! Please make inquiry to the administrator! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0005 "EVENT(%d) treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0006 "Map event information abnormal! Please make inquiry to the administrator! Current(%s, %s, %04d), Target(%04d, %d)\r\n"
	#define STRERR_S_F2NOTIFY_0007 "WARP treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0008 "EVENT(%d) treatment impossible(party leader) at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0009 "WARP(%04d) treatment impossible at Process_FC_PARTY_REQUEST_PARTY_WARP_WITH_MAP_NAME(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0010 "EVENT(%d) treatment impossible at Process_FC_EVENT_REQUEST_WARP(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0011 "WARP treatment impossible at T_FC_PARTY_REQUEST_PARTY_WARP(). %s\r\n"
	#define STRERR_S_F2NOTIFY_0012 "Party warp failed: %s -> distance: %5.2f, bodycon: %d, %d"
	#define STRERR_S_F2NOTIFY_0013 "WARP(%04d) treatment impossible at Process_FC_CHARACTER_DEAD_GAMESTART(), %s\r\n"
	#define STRERR_S_F2NOTIFY_0014 "%s -> click overlapped OK button!!!\r\n"
	#define STRERR_S_F2NOTIFY_0015 "Mission has not been loaded.\r\n"
	#define STRERR_S_F2NOTIFY_0016 "WARP(%s) treatment impossible at HandleAdminCommands(), /move, %s\r\n"
	#define STRERR_S_F2NOTIFY_0017 "WARP(%s) treatment impossible at HandleAdminCommands(), /send, %s\r\n"
	#define STRERR_S_F2NOTIFY_0018 "FATAL ERROR: This message should not be sent to field server that members do not belong to. Check it out\r\n"
	#define STRERR_S_F2NOTIFY_0019 "WARP(%04d) treatment impossible at T_FI_ADMIN_CALL_CHARACTER, %s\r\n"
	#define STRERR_S_F2NOTIFY_0020 "WARP(%s) treatment impossible at T_FI_ADMIN_MOVETO_CHARACTER, %s\r\n"

	// 5-6 Field - Event
	#define STRMSG_S_F2EVENTTYPE_0000 "Experience points"
	#define STRMSG_S_F2EVENTTYPE_0001 "SPI"
	#define STRMSG_S_F2EVENTTYPE_0002 "Restoration of experience points"
	#define STRMSG_S_F2EVENTTYPE_0003 "Item drop"
	#define STRMSG_S_F2EVENTTYPE_0004 "Rare item drop"
	#define STRMSG_S_F2EVENTTYPE_0005 "Unknown event"
// 5_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 6 - IMServer
	// 6-1 IM<->Pre
	#define STRMSG_S_I2PRECONNECT_0000 "Logged into Pre Server.\n"
	#define STRMSG_S_I2PRECONNECT_0001 "Connection to Pre Server [%15s:%4d]has been lost. Attempting reconnection.\r\n"

	// 6-2 IM Notify
	#define STRMSG_S_I2NOTIFY_0000 "\'%s\' already exists"
	#define STRMSG_S_I2NOTIFY_0001 "\'%s\' is already in a brigade."
	#define STRMSG_S_I2NOTIFY_0002 "\'%s\' is already the name of an existing brigade"
	#define STRMSG_S_I2NOTIFY_0003 "Brigade loading failed - Please make an inquiry to the administrator!"
	#define STRMSG_S_I2NOTIFY_0004 "Your friend '%s' has logged in"
	#define STRMSG_S_I2NOTIFY_0005 "Checking previous formation"
	#define STRMSG_S_I2NOTIFY_0006 "Previous formation does not exist"
	#define STRMSG_S_I2NOTIFY_0007 "Rejoined the formation"
	#define STRMSG_S_I2NOTIFY_0008 "You are presently in a formation"
	#define STRMSG_S_I2NOTIFY_0009 "Fatal Error: Fatal party error! at T_IC_PARTY_GET_MEMBER"
	#define STRMSG_S_I2NOTIFY_0010 "State of formation personnel is invalid"
	#define STRMSG_S_I2NOTIFY_0011 "formation personnel has already joined the brigade"
	#define STRMSG_S_I2NOTIFY_0012 "That person has already joined the brigade"
	#define STRMSG_S_I2NOTIFY_0013 "You cannot invite yourself"
	#define STRMSG_S_I2NOTIFY_0014 "You are in a state where joining brigades is not allowed"
	#define STRMSG_S_I2NOTIFY_0015 "You have exceeded the number of brigade personnel that can join"
	#define STRMSG_S_I2NOTIFY_0016 "You are in a state where joining brigades is not allowed"
	#define STRMSG_S_I2NOTIFY_0017 "Brigade leader cannot withdraw from brigade"
	#define STRMSG_S_I2NOTIFY_0018 "Cannot withdraw from brigade while you are in a brigade fight"
	#define STRMSG_S_I2NOTIFY_0019 "Cannot expel brigade personnel while in brigade fight"
	#define STRMSG_S_I2NOTIFY_0020 "Brigade leader cannot be expelled"
	#define STRMSG_S_I2NOTIFY_0021 "Cannot disperse brigade while you are in a brigade fight"
	#define STRMSG_S_I2NOTIFY_0022 "Cannot change to the same name"
	#define STRMSG_S_I2NOTIFY_0023 "You are in a state where the brigade name cannot be changed"
	#define STRMSG_S_I2NOTIFY_0024 "You are in a state where the brigade mark cannot be changed"
	#define STRMSG_S_I2NOTIFY_0025 "You are in a state where rank cannot be changed"
	#define STRMSG_S_I2NOTIFY_0026 "Rank has overlapped"
	#define STRMSG_S_I2NOTIFY_0027 "Rank change to regiment leader is not possible."
	#define STRMSG_S_I2NOTIFY_0028 "Change in regiment leaders rank is not possible."
	#define STRMSG_S_I2NOTIFY_0029 "Total number of users: %d persons (output up to %d people)"
	#define STRMSG_S_I2NOTIFY_0030 "Added to administrators message list"
	#define STRMSG_S_I2NOTIFY_0031 "Deleted from administrators message list"
	#define STRMSG_S_I2NOTIFY_0032 "Server IP: %s"
	#define STRMSG_S_I2NOTIFY_0033 "Server group \'%s\' total number of people logged on: %d people"
	#define STRMSG_S_I2NOTIFY_0034 "Do you really want to close the server(%s)? ServerID: %d"
	#define STRMSG_S_I2NOTIFY_0035 "\'%s\' is not playing the game"
	#define STRMSG_S_I2NOTIFY_0036 "Number of whole users: %d persons (Output up to %d people)"
	#define STRMSG_S_I2NOTIFY_0037 "/send %s %s"
	#define STRMSG_S_I2NOTIFY_0038 "Corresponding regiment does not exist."
	#define STRMSG_S_I2NOTIFY_0039 "Whisper block has been disabled"
	#define STRMSG_S_I2NOTIFY_0040 "Whisper has been blocked"
	#define STRMSG_S_I2NOTIFY_0041 "Did not join the brigade"
	#define STRMSG_S_I2NOTIFY_0042 "Brigade (%d) is not available"
	#define STRMSG_S_I2NOTIFY_0043 "Corresponding weather (%s) does not exist"
	#define STRMSG_S_I2NOTIFY_0044 "Field Server is invalid"
	#define STRMSG_S_I2NOTIFY_0045 "Corresponding map (%s) does not exist"
	#define STRMSG_S_I2NOTIFY_0046 "You cannot chat for %d minutes!"
	#define STRMSG_S_I2NOTIFY_0047 "Chatting block set : '%10s', %3d minutes"
	#define STRMSG_S_I2NOTIFY_0048 "Chatting block condition has been cancelled."
	#define STRMSG_S_I2NOTIFY_0049 "Chatting block cancelled: '%10s'"
	#define STRMSG_S_I2NOTIFY_0050 "%s (account: %s, map: %d(%d), level: %d) PLAYING"
	#define STRMSG_S_I2NOTIFY_0051 "Cannot summon yourself."
	#define STRMSG_S_I2NOTIFY_0052 "Corresponding brigade does not exist."

	#define STRMSG_S_IMSERVER_050607_0001	"Corresponding map does not exist."
// 6_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 7 - NPCServer
	// 7-1 NPC<->Field
	#define STRMSG_S_N2FIELDCONNECT_0000 "Logged into the Field Server.\n"
	#define STRMSG_S_N2FIELDCONNECT_0001 "Connection to Field Server[%15s:%4d] has been lost. Attempting reconnection.\r\n"

	// 7-2 IM Notify
	#define STRMSG_S_N2NOTIFY_0000 "Collision check between monster and object does not exist\r\n"
	#define STRMSG_S_N2NOTIFY_0001 "City occupation battle monster (%10s) summoned\r\n\r\n"

	#define STRMSG_S_N2TESTMONNAME_0000 "Chul Minho"
// 7_end	
///////////////////////////////////////////////////////////////////////////////
	

///////////////////////////////////////////////////////////////////////////////
// 8 - PreServer
	// 8-1 Pre Notify
	#define STRMSG_S_P2PRENOTIFY_0000 "Logged in with %s account(%s). IP: %s\r\n"
	#define STRMSG_S_P2PRENOTIFY_0001 "Success"
	#define STRMSG_S_P2PRENOTIFY_0002 "Failure"
	#define STRMSG_S_P2PRENOTIFY_0003 "[ERROR] Error in adding account information, AccountName(%s)	privateIP(%15s)\n"


	#define STRMSG_SCAT_051115_0001		"Hello. This is the AirRivals Administrator."
	#define STRMSG_SCAT_051115_0002		"We will be performing our regular maintenance in 10 minutes."
	#define STRMSG_SCAT_051115_0003		"Please move to a safe area and exit from the game."
	#define STRMSG_SCAT_051115_0004		"First, the NPC server will be shut down."
	#define STRMSG_SCAT_051115_0005		"AirRivals regular maintenance will begin."
	#define STRMSG_SCAT_051115_0006		"Enjoy your day with AirRivals."
	#define STRMSG_SCAT_051115_0007		"There will be a server checkup in 5 minutes." // 5     .
	#define STRMSG_SCAT_051115_0008		"Server will be down for 60 minutes."	//  60   
	#define STRMSG_SCAT_051115_0009		"Server maintenance begins in 30 minutes."
	#define STRMSG_SCAT_051115_0010		"Server maintenance begins in 15 minutes."
	#define STRMSG_SCAT_051115_0011		"Server maintenance begins in 10 minutes."
	#define STRMSG_SCAT_051115_0012		"Server maintenance begins in 5 minutes."
	#define STRMSG_SCAT_051115_0013		"Server maintenance will begin in a moment."


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

	// 2006-05-09 by cmkwon
	#define STRMSG_060509_0000			"Invisible Mode: Users cannot see you and weapons cannot be used."
	#define STRMSG_060509_0001			"Invincible Status: You will not receive any damage."
	#define STRMSG_060509_0002			"Stealth Mode: Monsters will not attack you first."

	// 2006-05-26 by cmkwon
	#define	STRMSG_060526_0000			"Your request has been sent to a GM. One of our GMs will contact you as soon as possible."
	#define	STRMSG_060526_0001			"You were unable to automatically update.\r\n\r\nPlease download the patch from Homepage(%s) and connect again.\r\n\r\n	Error: %s"

	// 2006-08-24 by cmkwon
	#define STRMSG_060824_0000			"This ID has not been registered or the ID and password do not match."
	
	// 2006-09-27 by cmkwon
	#define STRMSG_060927_0000			"The game server is currently offline for maintenance. Please check the official homepage (www.airrivals.net) for further information."

	// 2006-10-11 by cmkwon
	#define STRERR_061011_0000			"Game client version is not valid.\r\n	Please reinstall or download the patch file."

	// 2006-11-07 by cmkwon
	#define STRMSG_061107_0000			"You were killed by %s."

	// 2006-11-07 by cmkwon
	#define STRMSG_070410_0000   	"Jamboree server DB(atum2_db_20) initialization must be conducted after closing the jamboree server."
	#define STRMSG_070410_0001   	"Do you really want to initialize the jamboree server DB(atum2_db_20)- [Validation number:%d]"
	#define STRMSG_070410_0002   	"Jamboree server	DB(atum2_db_20) is initialized."
	#define STRMSG_070410_0003   	"Jamboree server	DB(atum2_db_20) initialization failed !!"
	#define STRMSG_070410_0004   	"'%s' data duplication to Jamboree server DB(atum2_db_20) completed."
	#define STRMSG_070410_0005   	"'%s' data duplication to Jamboree server DB(atum2_db_20) failed - character does not exist!"
	#define STRMSG_070410_0006   	"%s' data duplication to Jamboree server DB(atum2_db_20) failed - Corresponding account character exists!"
	#define STRMSG_070410_0007   	"%s' data duplication to Jamboree server DB(atum2_db_20) failed - DB addition failure!"
	#define STRMSG_070410_0008   	"%s' data duplication to Jamboree server DB(atum2_db_20) failed - Unknown (%d)!"

///////////////////////////////////////////////////////////////////////////////
// 2007-05-07 by cmkwon,   
	// 2007-07-24 by cmkwon,  800*600   -    
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

// 2007-06-15 by dhjin,   
#define STRMSG_070615_0000		"Cannot start as you are not in stealth mode."
#define STRMSG_070615_0001		"Cannot start the watch."
#define STRMSG_070620_0000	"User cannot start the watch."

// 2007-06-26 by dhjin,    
#define STRMSG_S_F2EVENTTYPE_0006		"WarPoint"

// 2007-06-28 by cmkwon,  (   ) -  
#define STRMSG_070628_0000				"You have been playing the game for %d hour(s)."
#define STRMSG_070628_0001				"You have been playing the game for %d hour(s). Please take necessary steps to get some rest."
#define STRMSG_070628_0002				"You have played too long. It is becoming dangerous for your health. Please take care of your own health and close the game. This is for your own benefit."
#define STRMSG_070628_0003				"Playing this game any more will be critical to your health. Look after your own health by closing the game right now. If not, your health will be influenced, and your game revenue will reach 0%. Your game revenue will be back to normal 5 hours after game has been closed."

///////////////////////////////////////////////////////////////////////////////
// 2007-07-11 by cmkwon, Arena block system materialization - added string
#define STRMSG_070711_0000    "\'%s\' is not prohibited in entering arena."
#define STRMSG_070711_0001 "\'%s\' is prohibited to enter the arena (time remaining: %d minutes)"
#define STRMSG_070711_0002 "You are forbidden to enter the arena for %d minutes!"
#define STRMSG_070711_0003 "Your prohibition from entering arena is finished."
#define STRMSG_070711_0004 "Use of Arena is prohibited for \'%s\'."

///////////////////////////////////////////////////////////////////////////////
// 2007-08-23 by cmkwon, Wide  1280x720(16:9)  -  
#define STRMSG_WINDOW_DEGREE_W1280x720_LOW			"1280x720 (low-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_MEDIUM		"1280x720 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_W1280x720_HIGH			"1280x720 (high-wide)"

// 2007-08-30 by cmkwon,    -  
#define STRMSG_070830_0001                                   "This command can only be used after nation has been selected."
#define STRMSG_070830_0002                                   "Conference room map(%d) of corresponding nation is not available"
#define STRMSG_070830_0003                                   "Number of users that can enter conference room : %d"
#define STRMSG_070830_0004                                   "'%s' has already been added to entrance list."
#define STRMSG_070830_0005                                   "'%s' does not have permission to enter."
#define STRMSG_070830_0006                                   "'%s' is not a valid character."
#define STRMSG_070830_0007                                 "'%s' cannot be added to conference room entrance list. (Maximum %d people)"
#define STRMSG_070830_0008                                   "'%s' has been authorized to enter the conference room."
#define STRMSG_070830_0009                                   "Permission to enter conference room has been given."
#define STRMSG_070830_0010                                   "Permission to enter conference room has been cancelled."
#define STRMSG_070830_0011                                   "'%s'"

// 2007-11-13 by cmkwon, just for Korean service, 
#define STRMSG_071115_0001									"\\y%s sent you %s as a present."
#define STRMSG_071115_0002									"Present list : \'%s (%d pieces)\'"
#define STRMSG_071115_0003									"\\y%s sent a present to %s.  Present is  %s. Please check the warehouse."
 
// 2007-11-19 by cmkwon, callGM system 
#define STRMSG_071120_0001									"Appeal system is not in effect. Please use the customer centre: http://support.airrivals.net"
#define STRMSG_071120_0002									"Appeal system is activated."
#define STRMSG_071120_0003									"Appeal system is concluded."
#define STRMSG_071120_0004									"Appeal system will start from %s to %s."

// 2007-11-28 by cmkwon,   - 
#define STRMSG_071128_0001									"%s has sent you %s(%d) as a present. Please check at your warehouse."

// 2007-12-27 by cmkwon,     - 
#define STRMSG_071228_0001				"Resolution setting is invalid. Please check again."

// 2008-01-31 by cmkwon,  /     - 
#define STRMSG_080201_0001									"'Error exists in %s' block setting. ErrorCode(%d)"
#define STRMSG_080201_0002									"'%s' account has been blocked. [Block End Date: %s]"
#define STRMSG_080201_0003									"'%s' account does not exist in block list. ErrorCode(%d)"
#define STRMSG_080201_0004									"'Error has occured in the process of blocking %s' account. ErrorCode(%d)"
#define STRMSG_080201_0005									"'%s' account has been removed from block list." 

// 2008-02-11 by cmkwon,  (1440x900) - 
#define STRMSG_WINDOW_DEGREE_1440x900_LOW			"1440x900 (low-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_MEDIUM		"1440x900 (medium-wide)"
#define STRMSG_WINDOW_DEGREE_1440x900_HIGH			"1440x900 (high-wide)"

// 2007-12-27 by dhjin, - 
#define STRMSG_S_MF2AFCONNECT_0000                       "[Error] WndProc(), Can't connect to ArenaServer[%15s:%4d] Reconnect\r\n"
#define STRMSG_S_MF2AFCONNECT_0001                       "Connected to Arena Server.\r\n"
#define STRMSG_S_MF2AFCONNECT_0002                       "Connection to Arena Server[%15s:%4d] is closed. Trying to re-connect.\r\n"
#define STRMSG_S_MF2AFCONNECT_0003                       "T_ERROR %s(%#04X) received from %s[%s]\r\n"
#define STRMSG_S_MF2AFCONNECT_0004                       "Unknown Error@WM_FIELD_PACKET_NOTIFY: %s(%#04x)\n"
#define STRMSG_ARENAEVENT_080310_0001                    "Number \\y%d Arena waiting room has been given event attribute.\r\n"
#define STRMSG_ARENAEVENT_080310_0002                    "Number \\y%d Arena waiting room has been discharged from event attribute.\r\n"
#define STRMSG_ARENAEVENT_080310_0003                    "\\y Failed to give Arena attribute.\r\n"
#define STRMSG_080428_0001					"%s has been shot down."          // 2008-04-28 by dhjin, Arena integration - String is added when taking down the opponent, only in Arena map 

// 2008-04-29 by cmkwon, ������ �� DB�� �(�� �� ���� ���� �� ������) - 
#define STRMSG_080430_0001					"Selected server is the server where the creation of new characters is not available."

// 2008-06-13 by dhjin, EP3 ���� �� ���� - 
#define STRMSG_080613_0001					"Admission to %s brigade has been rejected."

// 2008-09-04 by cmkwon, don't need translation, SystemLog 
#define STRMSG_080904_0001					 "[DB Error] No such DB query process(QP_xxx) function !! QueryType(%d:%s)\r\n"


// 2008-12-30 by cmkwon, ������ ��� �� �� ���� - 
#define STRMSG_081230_0001					"\\y%s will be restricted from chatting for %d minutes.\\y"
#define STRMSG_081230_0002					"\\yChatting has been restricted by the leader for %d minutes.\\y"
#define STRMSG_081230_0003					"\\yChatting restriction by leader is released.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2009-08-31 by cmkwon, Gameforge4D �� ����� ���� - 
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����� WebPage�� � - ������� ��, STRMSG_090831_0001�� �������� �
//#define STRMSG_090831_0001					"AirRivals is now protected from cheaters with a hackshield.\r\nPlease install it to help us to make AirRivals even safer.\r\nYou can only continue gameplay once you have installed the hackshield.\r\nPlease read the privacy policy< http://agb.gameforge.de/mmog/index.php?lang=en&art=datenschutz_mmog&special=airrivals&&f_text=b1daf2&f_text_hover=ffffff&f_text_h=061229&f_text_hr=061229&f_text_hrbg=061229&f_text_hrborder=9EBDE4&f_text_font=arial%2C+arial%2C+arial%2C+sans-serif&f_bg=000000 > to find out more about the hackshield's function."
//#define STRMSG_090831_0002					"Install Hackshield"
#define STRMSG_090831_0002					"Install nProtect" // 2015-03-11 by shchoi Gameforge4D nProtect ����â ����
#define STRMSG_090831_0003					"Cancel"

///////////////////////////////////////////////////////////////////////////////
// 2009-09-02 by cmkwon, Gameforge4D ���� ���� ����?WebPage�� �?- 
#define STRMSG_090902_0001					"http://en.airrivals.gameforge.com/launcher/gameguard"

///////////////////////////////////////////////////////////////////////////////
// 2009-10-16 by cmkwon, ���� �� �(1680x1050,1920x1080,1920x1200) - 
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
// 2011-01-26 by hskim, ���� ������ �� ��� ��
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_NOT_REGISTER			"Non-registered server (could be an illegal private server.)"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_DB_ERROR				"An error occurred during the connection with the data bank."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_OK						"The confirmation was successful"
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_BLOCKED				"Server IP registered, but further confirmations have been denied."
#define STRMSG_AUTHENTICATION_ACCEPT_COMMENT_SHUTDOWN				"The command to shut down the Windows server has been sent."

///////////////////////////////////////////////////////////////////////////////
// 2012-03-30 by hskim, EP4 ���� �����  ��

// 1�� 

#define STRMSG_120330_0001					"%s activates the warp portal to the Hidden Place on the Ash Trail."
#define STRMSG_120330_0002					"%s activates a 100%%%% increase in experience points on the Ash Trail (Happy Hour event for 1 hour)."
#define STRMSG_120330_0003					"%s activates a 100%%%% increase in item drop rate on the Ash Trail (Happy Hour event for 1 hour)."
#define STRMSG_120330_0004					"%s activates a 100%%%% increase in item drop rate/experience points/SPI on the Ash Trail (Happy Hour event for 1 hour)."
#define STRMSG_120330_0005					"%s activates the weapon shop on the Ash Trail."
#define STRMSG_120330_0006					"%s activates the hypercard shop on the Ash Trail."
#define STRMSG_120330_0007					"%s activates the kit shop on the Ash Trail."
#define STRMSG_120330_0008					"%s summons a gigantic monster to the Ash Trail."
#define STRMSG_120330_0009					"The crystal has disappeared."

// 2�� 

#define STRMSG_120508_0001					"%s receives the amount of War Points that %d received in the Sunken Oasis."
#define STRMSG_120508_0002					"%s summons a boss monster to the Sunken Oasis."
#define STRMSG_120508_0003					"%s activates a 150%%%% increase in experience points in the Sunken Oasis (Happy Hour event for 1 hour)."
#define STRMSG_120508_0004					"%s activates a 150%%%% increase in item drop rate in the Sunken Oasis (Happy Hour event for 1 hour)."
#define STRMSG_120508_0005					"%s activates a 150%%%% increase in item drop rate/experience points/SPI in the Sunken Oasis (Happy Hour event for 1 hour)."
#define STRMSG_120508_0006					"%s receives Ancient Ice in the Sunken Oasis."
#define STRMSG_120508_0007					"%s activates the expanded item shop in the Sunken Oasis."
#define STRMSG_120508_0008					"%s activates the kit shop in the Sunken Oasis."
#define STRMSG_120508_0009					"%s activates the hypercard shop in the Sunken Oasis."
#define STRMSG_120508_0010					"%s activates the weapon shop in the Sunken Oasis."
#define STRMSG_120508_0011					"%s activates the warp portal to the Hidden Place in the Sunken Oasis."

#define STRMSG_120712_0001					"18�� �� ���� ����� ���� ���� ���� ��, %d ��  ������ ���."		// 2012-07-11 by hskim, ������ ��

////////////////////////////////////////////////////////////////////////
// 2012-10-05 by jhseol, NPlay pc�� ���
#define STRMSG_121005_0001					"\\yPC�� ���� ���� %d�� ����."
#define STRMSG_121005_0002					"\\y��� �� PC�� ������ ���."

////////////////////////////////////////////////////////////////////////
// 2012-11-26 by jhseol, ���� ����� ������ - ����� ���� ��������(����)
#define STRMSG_121126_0001					"\\yCommand: during combat any activities relating to Crystals are banned.\\y"

////////////////////////////////////////////////////////////////////////
// 2012-11-29 by jhseol, OX �� ������
#define STRMSG_121129_0001					"\\y� �� �� �� ���� ��.\\y"

////////////////////////////////////////////////////////////////////////
// 2013-01-21 by jhseol, NGC �������� ���� �����
#define STRMSG_130121_0001					"\\cThe system has been captured by NGC troops. Immediate evacuation has begun."
#define STRMSG_130121_0002					"\\cScouts:\\c The \\rNGC Controller\\r has been reinforced."
#define STRMSG_130121_0003					"\\cScouts:\\c The \\rNGC Controller\\r has been destroyed."
#define STRMSG_130121_0004					"\\cCommand:\\c \\rGomora's\\r shields are online. Destroy the \\rNGC Controller\\r to deactivate the shields."
#define STRMSG_130121_0005					"\\cCommand:\\c \\rGomora's\\r shields are down! Attack now!"
#define STRMSG_130121_0006					"\\cCommand:\\c \\rGomora\\r has been destroyed! Everyone move up!"
#define STRMSG_130121_0007					"\\cCommand:\\c \\rGomora\\r must be destroyed first."
#define STRMSG_130121_0008					"\\c[%s] has been activated by overloading the \\c\\rNGC Controller\\r."
#define STRMSG_130121_0009					"\\y[NGC Outpost Base System]\\y."

///////////////////////////////////////////////////////////////////////////////
// 2013-04-22 by jhseol, ������  - ������ ᱸ ����� ����
#define STRMSG_130422_0001					"\\y%s %d is not permitted in the Arena. The item was sent to your warehouse.\\y"

///////////////////////////////////////////////////////////////////////////////
// 2013-05-31 by jhseol,bckim �� ����� - STRMSG �
#define STRMSG_130531_0001					"\\g[\\g%s\\g]\\g \\gThe contour has been added to your collection.\\g"
#define STRMSG_130531_0002					"\\g[\\g%s\\g]\\g \\gThe contour has been used [%2d] times.\\g"
#define STRMSG_130531_0003					"\\g[%s] The contour has been used the maximum number of times. You receive [\\c%s\\c].\\g"
#define STRMSG_130531_0004					"Your contour has expired and the stats removed. Your engine is no longer equipped."
#define STRMSG_130531_0005					"\\yNo engine is equipped. You will be teleported back to the city.\\y"
#define STRMSG_130531_0006					"\\gThe contour which is currently applied to your armour cannot be used.\\g"
#define STRMSG_130531_0007					"\\gContour changed.\\g"
#define STRMSG_130531_0008					"\\rContour [%s] has expired.\\r"
#define STRMSG_130531_0009					"\\yArmour equipped with contours cannot be sold.\\y"
#define STRMSG_130531_0010					"\\yIncorrect Gear type.\\y"

///////////////////////////////////////////////////////////////////////////////
// // 2013-07-08 by jhseol, ���� ����� �� - STRMSG �
#define STRMSG_130708_0001					"\\cCommand:\\c  The NGC shields have been activated. Destroy the \\rNGC Controller\\r to knock out \\rGomora's\\r shields."
#define STRMSG_130708_0002					"\\cCommand:\\c The NGC military base's defences are down! Attack now!"
#define STRMSG_130708_0003					"\\cScouts:\\c The \\rNGC shield generator\\r has been sighted."
#define STRMSG_130708_0004					"\\cScouts:\\c The \\rNGC shield generator\\r has been destroyed."

///////////////////////////////////////////////////////////////////////////////
// 2013-07-26 by jhseol, � �� �������
#define STRMSG_130726_0001					"The character is already a member of this nation."
#define STRMSG_130726_0002					"The character is a leader or sub-leader, and thus cannot change nation."
#define STRMSG_130726_0003					"The character is in a brigade, so the nation cannot be changed."
#define STRMSG_130726_0004					"There is no character available which can change nation."
#define STRMSG_130726_0005					"Changing nation failed [AUID(%d), CUID(%d), ToInflType(%d), ErrorCode(%d)]!"
#define STRMSG_130726_0006					"Nation changed successfully [AUID(%d), CUID(%d), ToInflType(%d)]!"
#define STRMSG_130726_0007					"This account does not exist."
#define STRMSG_130726_0008					"You are logged into your account. The nation cannot be changed."


// 2013-08-30 by bckim, �����������
#define STRMSG_130830_0001					"\\y%s's flight privileges were revoked by the nation leader.\\y"
#define STRMSG_130830_0002					"\\yFlight privileges were revoked by the nation leader.\\y"
#define STRMSG_130830_0003					"\\y%s's flight privileges were revoked by the nation leader.\\y"
// End. 2013-08-30 by bckim, �����������

// 2013-08-28 by bckim, �������� ����
#define STRMSG_130828_0001					"\\y[%s assisted in destroying \\y%s\\y.]\\y"
#define STRMSG_130828_0002					"\\y[%s drew first blood on \\y%s\\y.]\\y"
#define STRMSG_130828_0003					"\\y[%s did the most attacks against \\y%s\\y overall.]\\y"
#define STRMSG_130828_0004					"\\y[%s made the final blow against \\y%s\\y.]\\y"
#define STRMSG_130828_0005					"\\y%s\\y\\n was defeated."
// End. 2013-08-28 by bckim, �������� ����

// 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����
#define STRMSG_130814_0001					"\\y[%s] won the NGC Strategic Point War.\\y"
// end 2013-08-14 by jhseol, ���� ������ - ������� GM ���� ����

// 2014-03-12 by bckim, ���ן��(��������)
#define STRMSG_130318_0001					"%s has summoned the boss in a restricted area."
#define STRMSG_130318_0002					"%s has summoned the boss in the ruins."
// End. 2014-03-12 by bckim, ���ן��(��������)

// 2014-03-18 by bckim, ���� ON/OFF
#define STRMSG_130318_0003					"\\yYou can't use the Auction House at the moment.\\y"
// End. 2014-03-18 by bckim, ���� ON/OFF

#endif // end_#ifndef _STRING_DEFINE_SERVER_H_
