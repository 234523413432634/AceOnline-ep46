# Microsoft Developer Studio Project File - Name="QuestLoader" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=QuestLoader - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "QuestLoader.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "QuestLoader.mak" CFG="QuestLoader - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "QuestLoader - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "QuestLoader - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "QuestLoader - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\QuestLoader\Release"
# PROP Intermediate_Dir "..\..\output\QuestLoader\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\QuestLoader\Debug"
# PROP Intermediate_Dir "..\..\output\QuestLoader\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Test140"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Test140"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Test140"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "TEST140" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "YEDANG_KOR" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WIKIGAMES_ENG" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "YETIME_CHN" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "INTECOM_VIET" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ENG" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_DEU" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_TURKISH" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ITALIAN" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_FRANCE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_POL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ESP" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_THA" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_SGP" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "QuestLoader___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_IDN" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "INNOVA_RUS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "NETPOWER_TPE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "ARARIO_JPN" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "QuestLoader___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "LIN_ARG" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Test140"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Test140"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "TEST140" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Yedang_Kor"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Yedang_Kor"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "YEDANG_KOR" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\KOR\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Wikigames_Eng"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Wikigames_Eng"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WIKIGAMES_ENG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\CAN\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "YETIME_CHN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\CHN\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "INTECOM_VIET" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\VIE\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ENG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\ENG\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_DEU" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\DEU\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_TURKISH" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\TUR\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ITALIAN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\ITA\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_FRANCE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\FRA\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_POL" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\POL\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "GAMEFORGE4D_ESP" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\ESP\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_THA" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_SGP" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "QuestLoader___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "WINNERONLINE_IDN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "INNOVA_RUS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "NETPOWER_TPE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "ARARIO_JPN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\JPN\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "QuestLoader___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "LIN_ARG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug/QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\ARG\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "QuestLoader___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "QuestLoader___Win32_D_Masang_Global"
# PROP Intermediate_Dir "QuestLoader___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "MASANG_GLOBAL" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "_DEBUG" /D "_WINDOWS" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "MASANG_GLOBAL" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\QuestLoaderD.exe" /pdbtype:sept
# ADD LINK32 libflex.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\QuestLoaderD.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Masang_Global"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "QuestLoader___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "QuestLoader___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "QuestLoader___Win32_R_Masang_Global"
# PROP Intermediate_Dir "QuestLoader___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "MASANG_GLOBAL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I "..\..\GameServer\CommonGameServer" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "YY_NEVER_INTERACTIVE" /D "WIN32" /D "_MBCS" /D "_ATUM_DATA_LOADER" /D "MASANG_GLOBAL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"
# ADD LINK32 libflex.lib /nologo /debug /machine:I386 /out:"..\..\Bin\Release/QuestLoader.exe"

!ENDIF 

# Begin Target

# Name "QuestLoader - Win32 Release"
# Name "QuestLoader - Win32 Debug"
# Name "QuestLoader - Win32 R_Test140"
# Name "QuestLoader - Win32 R_Yedang_Kor"
# Name "QuestLoader - Win32 R_Wikigames_Eng"
# Name "QuestLoader - Win32 R_Yetime_Chn"
# Name "QuestLoader - Win32 R_Intecom_Viet"
# Name "QuestLoader - Win32 R_Gameforge4D_Eng"
# Name "QuestLoader - Win32 R_Gameforge4D_Deu"
# Name "QuestLoader - Win32 R_Gameforge4D_Turkish"
# Name "QuestLoader - Win32 R_Gameforge4D_Italian"
# Name "QuestLoader - Win32 R_Gameforge4D_France"
# Name "QuestLoader - Win32 R_Gameforge4D_Pol"
# Name "QuestLoader - Win32 R_Gameforge4D_Esp"
# Name "QuestLoader - Win32 R_WinnerOnline_Tha"
# Name "QuestLoader - Win32 R_WinnerOnline_SGP"
# Name "QuestLoader - Win32 R_WinnerOnline_IDN"
# Name "QuestLoader - Win32 R_Innova_Rus"
# Name "QuestLoader - Win32 R_Netpower_Tpe"
# Name "QuestLoader - Win32 R_Arario_Jpn"
# Name "QuestLoader - Win32 R_LIN_Arg"
# Name "QuestLoader - Win32 D_Test140"
# Name "QuestLoader - Win32 D_Yedang_Kor"
# Name "QuestLoader - Win32 D_Wikigames_Eng"
# Name "QuestLoader - Win32 D_Yetime_Chn"
# Name "QuestLoader - Win32 D_Intecom_Viet"
# Name "QuestLoader - Win32 D_Gameforge4D_Eng"
# Name "QuestLoader - Win32 D_Gameforge4D_Deu"
# Name "QuestLoader - Win32 D_Gameforge4D_Turkish"
# Name "QuestLoader - Win32 D_Gameforge4D_Italian"
# Name "QuestLoader - Win32 D_Gameforge4D_France"
# Name "QuestLoader - Win32 D_Gameforge4D_Pol"
# Name "QuestLoader - Win32 D_Gameforge4D_Esp"
# Name "QuestLoader - Win32 D_WinnerOnline_Tha"
# Name "QuestLoader - Win32 D_WinnerOnline_SGP"
# Name "QuestLoader - Win32 D_WinnerOnline_IDN"
# Name "QuestLoader - Win32 D_Innova_Rus"
# Name "QuestLoader - Win32 D_Netpower_Tpe"
# Name "QuestLoader - Win32 D_Arario_Jpn"
# Name "QuestLoader - Win32 D_LIN_Arg"
# Name "QuestLoader - Win32 D_Masang_Global"
# Name "QuestLoader - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\GameServer\CommonGameServer\Quest.cpp
# End Source File
# Begin Source File

SOURCE=.\QuestLoader.cpp
# End Source File
# Begin Source File

SOURCE=.\QuestLoader.l.cpp
# End Source File
# Begin Source File

SOURCE=.\QuestLoaderParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\GameServer\CommonGameServer\UserVariable.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\GameServer\CommonGameServer\Quest.h
# End Source File
# Begin Source File

SOURCE=.\QuestLoader.cpp.h
# End Source File
# Begin Source File

SOURCE=..\..\GameServer\CommonGameServer\QuestLoaderParser.h
# End Source File
# Begin Source File

SOURCE=..\..\GameServer\CommonGameServer\UserVariable.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\QuestLoader.l

!IF  "$(CFG)" == "QuestLoader - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Test140"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yedang_Kor"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Wikigames_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yetime_Chn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Intecom_Viet"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Deu"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Turkish"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Italian"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_France"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Pol"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Esp"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_Tha"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_SGP"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_IDN"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Innova_Rus"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Netpower_Tpe"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Arario_Jpn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_LIN_Arg"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Test140"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yedang_Kor"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Wikigames_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yetime_Chn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Intecom_Viet"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Deu"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Turkish"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Italian"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_France"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Pol"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Esp"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_Tha"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_SGP"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_IDN"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Innova_Rus"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Netpower_Tpe"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Arario_Jpn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_LIN_Arg"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Masang_Global"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Masang_Global"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Lexer
InputPath=.\QuestLoader.l
InputName=QuestLoader

"$(InputName).l.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	flex.exe -PQuestLoader -t $(InputName).l > $(InputName).l.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\QuestLoader.y

!IF  "$(CFG)" == "QuestLoader - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Test140"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yedang_Kor"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Wikigames_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Yetime_Chn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Intecom_Viet"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Deu"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Turkish"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Italian"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_France"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Pol"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Gameforge4D_Esp"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_Tha"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_SGP"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_WinnerOnline_IDN"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Innova_Rus"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Netpower_Tpe"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Arario_Jpn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_LIN_Arg"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Test140"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yedang_Kor"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Wikigames_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Yetime_Chn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Intecom_Viet"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Eng"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Deu"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Turkish"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Italian"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_France"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Pol"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Gameforge4D_Esp"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_Tha"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_SGP"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_WinnerOnline_IDN"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Innova_Rus"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Netpower_Tpe"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Arario_Jpn"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_LIN_Arg"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 D_Masang_Global"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -v -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ELSEIF  "$(CFG)" == "QuestLoader - Win32 R_Masang_Global"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - Building Parser
InputPath=.\QuestLoader.y
InputName=QuestLoader

"$(InputName).cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	bison.exe -pQuestLoader -o QuestLoader.cpp -d $(InputName).y

# End Custom Build

!ENDIF 

# End Source File
# End Target
# End Project
