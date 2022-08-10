# Microsoft Developer Studio Project File - Name="SpaceCowboyDBEditorTool" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SpaceCowboyDBEditorTool - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SpaceCowboyDBEditorTool.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SpaceCowboyDBEditorTool.mak" CFG="SpaceCowboyDBEditorTool - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SpaceCowboyDBEditorTool - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SpaceCowboyDBEditorTool - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "SpaceCowboyDBEditorTool - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "SpaceCowboyDBEditorTool - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SpaceCowboyDBEditorTool - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\SpaceCowboyDBEditorTool\Release"
# PROP Intermediate_Dir "..\..\output\SpaceCowboyDBEditorTool\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "TEST140" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\SCDBEditorTool.exe" /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SpaceCowboyDBEditorTool - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\SpaceCowboyDBEditorTool\Debug"
# PROP Intermediate_Dir "..\..\output\SpaceCowboyDBEditorTool\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_SERVER" /D "TEST140" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /debug /machine:I386 /out:"..\..\Bin\Debug\00000_SCDBTool(MS140_Kor)_Main_D.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SpaceCowboyDBEditorTool - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "SpaceCowboyDBEditorTool___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "SpaceCowboyDBEditorTool___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "SpaceCowboyDBEditorTool___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "SpaceCowboyDBEditorTool___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "TEST140" /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "INTECOM_VIET" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\SCDBEditorTool.exe" /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\SCDBEditorTool.exe" /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SpaceCowboyDBEditorTool - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "SpaceCowboyDBEditorTool___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "SpaceCowboyDBEditorTool___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "SpaceCowboyDBEditorTool___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "SpaceCowboyDBEditorTool___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "TEST140" /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "WIKIGAMES_ENG" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\SCDBEditorTool.exe" /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 D3dx8.lib odbccp32.lib odbc32.lib winmm.lib QuestLoaderLib.lib /nologo /subsystem:windows /pdb:"SpaceCowboyDBEditorTool___Win32_R_Wikigames_Eng/SCDBEditorTool.pdb" /machine:I386 /out:"..\..\BuildResultSvr\CAN\Tool\02000_SCDBTool(Wikigames_Eng)_Main.exe" /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "SpaceCowboyDBEditorTool - Win32 Release"
# Name "SpaceCowboyDBEditorTool - Win32 Debug"
# Name "SpaceCowboyDBEditorTool - Win32 R_Intecom_Viet"
# Name "SpaceCowboyDBEditorTool - Win32 R_Wikigames_Eng"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\CommonGameServer\AtumDateTime.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocol.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocolFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumSJ.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\BrowseForFolder.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineItemDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EngineItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Global.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCell.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCellBase.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridDropTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\InPlaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\LinkDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Localization.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTabConnection.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTabGuildItem.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTabItem.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTabServerIntegration.cpp
# End Source File
# Begin Source File

SOURCE=.\LogTabUser.cpp
# End Source File
# Begin Source File

SOURCE=.\MapEditorDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MapEditorDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterAttackDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterAttackDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterDropDetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterDropDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyTabCtrl.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\PreviewDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Quest.cpp
# End Source File
# Begin Source File

SOURCE=.\QuestEditorDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\QuestLoadDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SCGridHelper.cpp
# End Source File
# Begin Source File

SOURCE=.\SCLogAdminDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetLanguageDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorTool.cpp
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorTool.rc
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorToolDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage100Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage101Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage102Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage1Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage2Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage3Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage4Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage5Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage61Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage62Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage6Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage71Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage7Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage8Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage97Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage98Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage99Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticPage9Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticSheetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\..\Common\SystemLogManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\TitleTip.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\UserVariable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\VMem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\VMemPool.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\WayPointManager.cpp
# End Source File
# Begin Source File

SOURCE=.\WeaponItem.cpp
# End Source File
# Begin Source File

SOURCE=.\WeaponItemDetail.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinPacket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\WriteLog.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\XOR_Lib.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\CommonGameServer\AtumSJ.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\CellRange.h
# End Source File
# Begin Source File

SOURCE=.\EngineItemDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\EngineItemDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCell.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCellBase.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridCtrl.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\GridDropTarget.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\InPlaceEdit.h
# End Source File
# Begin Source File

SOURCE=.\LinkDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogTabConnection.h
# End Source File
# Begin Source File

SOURCE=.\LogTabGuildItem.h
# End Source File
# Begin Source File

SOURCE=.\LogTabItem.h
# End Source File
# Begin Source File

SOURCE=.\LogTabServerIntegration.h
# End Source File
# Begin Source File

SOURCE=.\LogTabUser.h
# End Source File
# Begin Source File

SOURCE=.\MapEditorDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\MapEditorDlg.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\MonsterAttackDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\MonsterAttackDlg.h
# End Source File
# Begin Source File

SOURCE=.\MonsterDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\MonsterDlg.h
# End Source File
# Begin Source File

SOURCE=.\MonsterDropDetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\MonsterDropDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyTabCtrl.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.h
# End Source File
# Begin Source File

SOURCE=.\PreviewDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Quest.h
# End Source File
# Begin Source File

SOURCE=.\QuestEditorDlg.h
# End Source File
# Begin Source File

SOURCE=.\QuestLoadDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\QuestLoaderParser.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SCGridHelper.h
# End Source File
# Begin Source File

SOURCE=.\SCLogAdminDlg.h
# End Source File
# Begin Source File

SOURCE=.\SelectItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetLanguageDlg.h
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorTool.h
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorToolDlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage100Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage101Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage102Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage1Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage2Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage3Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage4Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage5Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage61Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage62Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage6Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage71Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage7Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage8Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage97Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage98Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage99Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticPage9Dlg.h
# End Source File
# Begin Source File

SOURCE=.\StatisticSheetDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\TitleTip.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\WayPointManager.h
# End Source File
# Begin Source File

SOURCE=.\WeaponItem.h
# End Source File
# Begin Source File

SOURCE=.\WeaponItemDetail.h
# End Source File
# Begin Source File

SOURCE=.\WriteLog.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\XOR_Lib.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\ItemEditer\res\ItemEditer.ico
# End Source File
# Begin Source File

SOURCE=.\res\SpaceCowboyDBEditorTool.ico
# End Source File
# Begin Source File

SOURCE=.\res\SpaceCowboyDBEditorTool.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\SpaceCowboyDBEditorToolModifyList.txt
# End Source File
# End Target
# End Project
