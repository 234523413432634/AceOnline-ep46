# Microsoft Developer Studio Project File - Name="Atum" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Atum - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Atum.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Atum.mak" CFG="Atum - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Atum - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "Atum - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Atum - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\Atum\Release"
# PROP Intermediate_Dir "..\..\output\Atum\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"

!ELSEIF  "$(CFG)" == "Atum - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\Atum\Debug"
# PROP Intermediate_Dir "..\..\output\Atum\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Test140"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Test140"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Test140"
# PROP Intermediate_Dir "Atum___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TEST140" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Yedang_Kor0"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Yedang_Kor0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Yedang_Kor0"
# PROP Intermediate_Dir "Atum___Win32_D_Yedang_Kor0"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YEDANG_KOR" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\KOR\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Wikigames_Eng0"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Wikigames_Eng0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Wikigames_Eng0"
# PROP Intermediate_Dir "Atum___Win32_D_Wikigames_Eng0"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WIKIGAMES_ENG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\CAN\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\WIKIGAMES_ENG .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "Atum___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YETIME_CHN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\CHN\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "Atum___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INTECOM_VIET" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\VIE\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\INTECOM_VIET\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ENG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\ENG\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_DEU" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\DEU\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_TURKISH" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\TUR\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\ITA\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\FRA\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\POL\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "Atum___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\ESP\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "Atum___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "Atum___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "Atum___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "Atum___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "Atum___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "Atum___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "Atum___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "Atum___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "Atum___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\JPN\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "Atum___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "Atum___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\SpaceCowboy.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\ARG\AceOline.exe" /pdbtype:sept

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Test140"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Test140"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Test140"
# PROP Intermediate_Dir "Atum___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "TEST140" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "Atum___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "YEDANG_KOR" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\KOR\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "Atum___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "WIKIGAMES_ENG" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\CAN\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\WIKIGAMES_ENG .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "Atum___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "YETIME_CHN" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\CHN\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\Yetime_Chn .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "Atum___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "INTECOM_VIET" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\VIE\ETC\C_Exe1\Main\Phidoi.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\INTECOM_VIET\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_ENG" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ENG\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_ENG .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_DEU" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\DEU\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_DEU .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_TURKISH" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\TUR\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_TURKISH .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_ITALIAN" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ITA\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_ITALIAN .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_FRANCE" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\FRA\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_FRANCE .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_POL" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\POL\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_POL .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "Atum___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "GAMEFORGE4D_ESP" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ESP\ETC\C_Exe1\Main\AirRivals.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\GAMEFORGE4D_ESP .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "Atum___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "Atum___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "WINNERONLINE_THA" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"

!ELSEIF  "$(CFG)" == "Atum - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "Atum___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "Atum___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "WINNERONLINE_SGP" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"

!ELSEIF  "$(CFG)" == "Atum - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "Atum___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "Atum___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "WINNERONLINE_IDN" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "Atum___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "INNOVA_RUS" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "Atum___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "NETPOWER_TPE" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "Atum___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "ARARIO_JPN" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\JPN\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\ARARIO_JPN .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "Atum___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "Atum___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "NDEBUG" /D "_MGAME_RELEASE" /D "LIN_ARG" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ETC\C_Exe1\Main\SpaceCowboy.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\ARG\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\LIN_ARG .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 D_Masang_Global"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Atum___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "Atum___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Atum___Win32_D_Masang_Global"
# PROP Intermediate_Dir "Atum___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\AceOline.exe" /pdbtype:sept
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\AceOline.exe" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\WIKIGAMES_ENG .\res /Y /Q
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Atum - Win32 R_Masang_Global"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Atum___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "Atum___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Atum___Win32_R_Masang_Global"
# PROP Intermediate_Dir "Atum___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I "..\CommonGameServer\FTP" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_MGAME_RELEASE" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\ETC\C_Exe1\Main\ACEonline.exe"
# ADD LINK32 wininet.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\ETC\C_Exe1\Main\ACEonline.exe"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Desc=#### Atum Resource Copy ####
PreLink_Cmds=xcopy .\res\DEFAULT\atum.ico . /Y /Q	xcopy .\res\DEFAULT .\res /Y /Q	xcopy .\res\WIKIGAMES_ENG .\res /Y /Q
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "Atum - Win32 Release"
# Name "Atum - Win32 Debug"
# Name "Atum - Win32 D_Test140"
# Name "Atum - Win32 D_Yedang_Kor"
# Name "Atum - Win32 D_Wikigames_Eng"
# Name "Atum - Win32 D_Yetime_Chn"
# Name "Atum - Win32 D_Intecom_Viet"
# Name "Atum - Win32 D_Gameforge4D_Eng"
# Name "Atum - Win32 D_Gameforge4D_Deu"
# Name "Atum - Win32 D_Gameforge4D_Turkish"
# Name "Atum - Win32 D_Gameforge4D_Italian"
# Name "Atum - Win32 D_Gameforge4D_France"
# Name "Atum - Win32 D_Gameforge4D_Pol"
# Name "Atum - Win32 D_Gameforge4D_Esp"
# Name "Atum - Win32 D_WinnerOnline_Tha"
# Name "Atum - Win32 D_WinnerOnline_SGP"
# Name "Atum - Win32 D_WinnerOnline_IDN"
# Name "Atum - Win32 D_Innova_Rus"
# Name "Atum - Win32 D_Netpower_Tpe"
# Name "Atum - Win32 D_Arario_Jpn"
# Name "Atum - Win32 D_LIN_Arg"
# Name "Atum - Win32 R_Test140"
# Name "Atum - Win32 R_Yedang_Kor"
# Name "Atum - Win32 R_Wikigames_Eng"
# Name "Atum - Win32 R_Yetime_Chn"
# Name "Atum - Win32 R_Intecom_Viet"
# Name "Atum - Win32 R_Gameforge4D_Eng"
# Name "Atum - Win32 R_Gameforge4D_Deu"
# Name "Atum - Win32 R_Gameforge4D_Turkish"
# Name "Atum - Win32 R_Gameforge4D_Italian"
# Name "Atum - Win32 R_Gameforge4D_France"
# Name "Atum - Win32 R_Gameforge4D_Pol"
# Name "Atum - Win32 R_Gameforge4D_Esp"
# Name "Atum - Win32 R_WinnerOnline_Tha"
# Name "Atum - Win32 R_WinnerOnline_SGP"
# Name "Atum - Win32 R_WinnerOnline_IDN"
# Name "Atum - Win32 R_Innova_Rus"
# Name "Atum - Win32 R_Netpower_Tpe"
# Name "Atum - Win32 R_Arario_Jpn"
# Name "Atum - Win32 R_LIN_Arg"
# Name "Atum - Win32 D_Masang_Global"
# Name "Atum - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Atum.cpp
# End Source File
# Begin Source File

SOURCE=.\Atum.rc
# End Source File
# Begin Source File

SOURCE=.\AtumDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocol.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocolFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\FTP\FTPManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\HttpManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Iexplore.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\FTP\KbcBmp.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\FTP\KbcButton.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ListBoxEBX.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MGameDecryption.cpp
# End Source File
# Begin Source File

SOURCE=.\main\PreUpdateWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\RegistryControl.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\selectgameserverdlg.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinPacket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\XOR_Lib.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Atum.h
# End Source File
# Begin Source File

SOURCE=.\AtumDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Contents.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\FTP\FTPManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\HttpManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\IExplore.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ListBoxEBX.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\LocalizationDefineCommon.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MGameDecryption.h
# End Source File
# Begin Source File

SOURCE=.\main\PreUpdateWinSocket.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\RegistryControl.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Main\selectgameserverdlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\StringDefineCommon.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\StringDefineServer.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinPacket.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\atum.ico
# End Source File
# Begin Source File

SOURCE=.\res\Atum.ico
# End Source File
# Begin Source File

SOURCE=.\res\Atum.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BtnGameServer9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LoginServer_BG_r1_c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LoginServer_BG_r3_c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LoginServer_BG_r4_c1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LoginServer_ListItemBG.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LoginServerListItemBG.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TitleBar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\AtumModifyList.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
