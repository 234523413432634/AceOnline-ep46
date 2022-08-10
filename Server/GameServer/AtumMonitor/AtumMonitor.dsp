# Microsoft Developer Studio Project File - Name="AtumMonitor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=AtumMonitor - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AtumMonitor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AtumMonitor.mak" CFG="AtumMonitor - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AtumMonitor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "AtumMonitor - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AtumMonitor - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\AtumMonitor\Release"
# PROP Intermediate_Dir "..\..\output\AtumMonitor\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
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
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\AtumMonitor\Debug"
# PROP Intermediate_Dir "..\..\output\AtumMonitor\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Test140"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Test140"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Test140"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "TEST140" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Yedang_Kor"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Yedang_Kor"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YEDANG_KOR" /D "_ATUM_MONITORTOOL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\KOR\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Wikigames_Eng"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Wikigames_Eng"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WIKIGAMES_ENG" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\CAN\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YETIME_CHN" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\CHN\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "INTECOM_VIET" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\VIE\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ENG" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\ENG\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_DEU" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\DEU\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_TURKISH" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\TUR\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ITALIAN" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\ITA\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_FRANCE" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\FRA\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_POL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\POL\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ESP" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\ESP\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WINNERONLINE_THA" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WINNERONLINE_SGP" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WINNERONLINE_IDN" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "INNOVA_RUS" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "NETPOWER_TPE" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "ARARIO_JPN" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\JPN\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "LIN_ARG" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\ARG\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Test140"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Test140"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Test140"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "TEST140" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\Tool\SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "YEDANG_KOR" /D "_ATUM_MONITORTOOL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\KOR\Tool\01000_SCMonitor_MS141(Masang_Kor)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "WIKIGAMES_ENG" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\CAN\Tool\02000_SCMonitor(Wikigames_Eng)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "YETIME_CHN" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\CHN\Tool\03000_SCMonitor_MS146(Yetime_Chn)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "INTECOM_VIET" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\VIE\Tool\04000_SCMonitor_MS143(VTC-Intecom_Viet)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ENG" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\ENG\Tool\05000_SCMonitor(Gameforge4D_Eng)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_DEU" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\DEU\Tool\05100_SCMonitor(Gameforge4D_Deu)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_TURKISH" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\TUR\Tool\05200_SCMonitor(Gameforge4D_Tur)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\ITA\Tool\05400_SCMonitor(Gameforge4D_Ita)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\FRA\Tool\05500_SCMonitor(Gameforge4D_Fra)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\POL\Tool\05600_SCMonitor(Gameforge4D_Pol)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\ESP\Tool\05700_SCMonitor(Gameforge4D_Esp)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release\07000_SCMonitor(Innova_Rus)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\JPN\Tool\10000_SCMonitor_MS222(Arario_Jpn)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Release/SCMonitor.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\ARG\Tool\11000_SCMonitor_MS228(Lin_Arg).exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 D_Masang_Global"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "AtumMonitor___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "AtumMonitor___Win32_D_Masang_Global"
# PROP Intermediate_Dir "AtumMonitor___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /FR /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\GLOBAL\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 Wininet.lib odbc32.lib odbccp32.lib winmm.lib ZipArchiveD.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /nodefaultlib:"MSVCRTD" /nodefaultlib:"MSVCRT" /out:"..\..\Bin\Debug\GLOBAL\SCMonitor.exe" /pdbtype:sept /libpath:"..\..\Lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "AtumMonitor - Win32 R_Masang_Global"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "AtumMonitor___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "AtumMonitor___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "AtumMonitor___Win32_R_Masang_Global"
# PROP Intermediate_Dir "AtumMonitor___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /FR /FD /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\GLOBAL\Tool\20000_SCMonitor(MasangGlobal)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib odbc32.lib odbccp32.lib ZipArchive.lib /nologo /subsystem:windows /map /machine:I386 /nodefaultlib:"MSVCRT" /out:"..\..\BuildResultSvr\GLOBAL\Tool\20000_SCMonitor(MasangGlobal)_Main.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "AtumMonitor - Win32 Release"
# Name "AtumMonitor - Win32 Debug"
# Name "AtumMonitor - Win32 D_Test140"
# Name "AtumMonitor - Win32 D_Yedang_Kor"
# Name "AtumMonitor - Win32 D_Wikigames_Eng"
# Name "AtumMonitor - Win32 D_Yetime_Chn"
# Name "AtumMonitor - Win32 D_Intecom_Viet"
# Name "AtumMonitor - Win32 D_Gameforge4D_Eng"
# Name "AtumMonitor - Win32 D_Gameforge4D_Deu"
# Name "AtumMonitor - Win32 D_Gameforge4D_Turkish"
# Name "AtumMonitor - Win32 D_Gameforge4D_Italian"
# Name "AtumMonitor - Win32 D_Gameforge4D_France"
# Name "AtumMonitor - Win32 D_Gameforge4D_Pol"
# Name "AtumMonitor - Win32 D_Gameforge4D_Esp"
# Name "AtumMonitor - Win32 D_WinnerOnline_Tha"
# Name "AtumMonitor - Win32 D_WinnerOnline_SGP"
# Name "AtumMonitor - Win32 D_WinnerOnline_IDN"
# Name "AtumMonitor - Win32 D_Innova_Rus"
# Name "AtumMonitor - Win32 D_Netpower_Tpe"
# Name "AtumMonitor - Win32 D_Arario_Jpn"
# Name "AtumMonitor - Win32 D_LIN_Arg"
# Name "AtumMonitor - Win32 R_Test140"
# Name "AtumMonitor - Win32 R_Yedang_Kor"
# Name "AtumMonitor - Win32 R_Wikigames_Eng"
# Name "AtumMonitor - Win32 R_Yetime_Chn"
# Name "AtumMonitor - Win32 R_Intecom_Viet"
# Name "AtumMonitor - Win32 R_Gameforge4D_Eng"
# Name "AtumMonitor - Win32 R_Gameforge4D_Deu"
# Name "AtumMonitor - Win32 R_Gameforge4D_Turkish"
# Name "AtumMonitor - Win32 R_Gameforge4D_Italian"
# Name "AtumMonitor - Win32 R_Gameforge4D_France"
# Name "AtumMonitor - Win32 R_Gameforge4D_Pol"
# Name "AtumMonitor - Win32 R_Gameforge4D_Esp"
# Name "AtumMonitor - Win32 R_WinnerOnline_Tha"
# Name "AtumMonitor - Win32 R_WinnerOnline_SGP"
# Name "AtumMonitor - Win32 R_WinnerOnline_IDN"
# Name "AtumMonitor - Win32 R_Innova_Rus"
# Name "AtumMonitor - Win32 R_Netpower_Tpe"
# Name "AtumMonitor - Win32 R_Arario_Jpn"
# Name "AtumMonitor - Win32 R_LIN_Arg"
# Name "AtumMonitor - Win32 D_Masang_Global"
# Name "AtumMonitor - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AdminWindowDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDateTime.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBHelper.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBManager.cpp
# End Source File
# Begin Source File

SOURCE=.\AtumMonitor.cpp
# End Source File
# Begin Source File

SOURCE=.\AtumMonitor.rc
# End Source File
# Begin Source File

SOURCE=.\AtumMonitorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\AtumMonitorView.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocol.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParamProtocolFunctions.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumThread.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\BrowseForFolder.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckDBData.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckItemDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientFTPUpdateManagerDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CommandHistory.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\DataHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgNewServerGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\FieldServerDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Global.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GlobalGameServer.cpp
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

SOURCE=..\CommonGameServer\historycombobox.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\HttpManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ImportExcelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InfoGenDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\InPlaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\LeftView.cpp
# End Source File
# Begin Source File

SOURCE=.\LoadExcelFile.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Localization.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.cpp
# End Source File
# Begin Source File

SOURCE=.\main\MonitorNode.cpp
# End Source File
# Begin Source File

SOURCE=.\MonitorTickManager.cpp
# End Source File
# Begin Source File

SOURCE=.\main\MonitorWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=.\MyFileDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Overlapped.cpp
# End Source File
# Begin Source File

SOURCE=.\PreUserCountDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PringDBGDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordProgress.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SCServerDBConnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectServerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetCityWarTimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetCityWarTimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetMGameEventTypeDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SQLReader.cpp
# End Source File
# Begin Source File

SOURCE=.\SQLReaderDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SystemLogManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TableName.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\ThreadCheck.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\TickManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\TitleTip.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\TotalHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\TotalProgress.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\TrayIcon.cpp
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

SOURCE=..\..\Common\WinPacket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\XOR_Lib.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\Zipfile1.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\zipfileDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AdminWindowDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AMLeak.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBHelper.h
# End Source File
# Begin Source File

SOURCE=.\AtumMonitor.h
# End Source File
# Begin Source File

SOURCE=.\AtumMonitorDoc.h
# End Source File
# Begin Source File

SOURCE=.\AtumMonitorView.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\CellRange.h
# End Source File
# Begin Source File

SOURCE=.\CheckDBData.h
# End Source File
# Begin Source File

SOURCE=.\CheckItemDialog.h
# End Source File
# Begin Source File

SOURCE=.\ClientFTPUpdateManagerDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CommandHistory.h
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\DataHeader.h
# End Source File
# Begin Source File

SOURCE=.\DlgNewServerGroup.h
# End Source File
# Begin Source File

SOURCE=.\FieldServerDlg.h
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

SOURCE=..\CommonGameServer\historycombobox.h
# End Source File
# Begin Source File

SOURCE=.\ImportExcelDlg.h
# End Source File
# Begin Source File

SOURCE=.\InfoGenDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\InPlaceEdit.h
# End Source File
# Begin Source File

SOURCE=.\LeftView.h
# End Source File
# Begin Source File

SOURCE=.\LoadExcelFile.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\main\MonitorNode.h
# End Source File
# Begin Source File

SOURCE=.\MonitorTickManager.h
# End Source File
# Begin Source File

SOURCE=.\main\MonitorWinSocket.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.h
# End Source File
# Begin Source File

SOURCE=.\MyFileDialog.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.h
# End Source File
# Begin Source File

SOURCE=.\PreUserCountDlg.h
# End Source File
# Begin Source File

SOURCE=.\PringDBGDlg.h
# End Source File
# Begin Source File

SOURCE=.\RecordProgress.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SCServerDBConnDlg.h
# End Source File
# Begin Source File

SOURCE=.\SelectServerDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetMGameEventTypeDlg.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SQLReader.h
# End Source File
# Begin Source File

SOURCE=.\SQLReaderDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\StringDefineCommon.h
# End Source File
# Begin Source File

SOURCE=.\TableName.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\TickManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GridCtrl\TitleTip.h
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\TotalHeader.h
# End Source File
# Begin Source File

SOURCE=.\TotalProgress.h
# End Source File
# Begin Source File

SOURCE=.\Main\TrayIcon.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\WayPointManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\Zipfile1.h
# End Source File
# Begin Source File

SOURCE=.\Main\zipfile\zipfileDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\AtumMonitor.ico
# End Source File
# Begin Source File

SOURCE=.\res\AtumMonitor.rc2
# End Source File
# Begin Source File

SOURCE=.\res\AtumMonitorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\CheckImage.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\AtumMonitorModifyList.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
