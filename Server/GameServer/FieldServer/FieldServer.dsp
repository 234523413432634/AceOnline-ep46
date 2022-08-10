# Microsoft Developer Studio Project File - Name="FieldServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FieldServer - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FieldServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FieldServer.mak" CFG="FieldServer - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FieldServer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "FieldServer - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FieldServer - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\FieldServer\Release"
# PROP Intermediate_Dir "..\..\output\FieldServer\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\FieldServer\Debug"
# PROP Intermediate_Dir "..\..\output\FieldServer\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Test140"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Test140"
# PROP Intermediate_Dir "FieldServer___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "TEST140" /D "_WIN32_DCOM" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib Comctl32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Yedang_Kor"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Yedang_Kor"
# PROP Intermediate_Dir "FieldServer___Win32_D_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "YEDANG_KOR" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\KOR\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Wikigames_Eng"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Wikigames_Eng"
# PROP Intermediate_Dir "FieldServer___Win32_D_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "WIKIGAMES_ENG" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\CAN\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "FieldServer___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "YETIME_CHN" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\CHN\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "FieldServer___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "INTECOM_VIET" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\VIE\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_ENG" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\ENG\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_DEU" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\DEU\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_TURKISH" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\TUR\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_ITALIAN" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\ITA\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_FRANCE" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\FRA\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_POL" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\POL\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "FieldServer___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_ESP" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\ESP\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "WINNERONLINE_THA" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "WINNERONLINE_SGP" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "FieldServer___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "WINNERONLINE_IDN" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "FieldServer___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "INNOVA_RUS" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "FieldServer___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "NETPOWER_TPE" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "FieldServer___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "ARARIO_JPN" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\JPN\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "FieldServer___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "LIN_ARG" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\ARG\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Test140"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Test140"
# PROP Intermediate_Dir "FieldServer___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "TEST140" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib Comctl32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "FieldServer___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "YEDANG_KOR" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /pdb:"..\..\BuildResultSvr\KOR\Dbg\FieldServer.pdb" /map:"..\..\BuildResultSvr\KOR\Dbg\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\KOR\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "FieldServer___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "WIKIGAMES_ENG" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CAN\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "FieldServer___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "YETIME_CHN" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CHN\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CHN\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "FieldServer___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "INTECOM_VIET" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\VIE\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\VIE\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_ENG" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ENG\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ENG\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_DEU" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\DEU\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\DEU\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "GAMEFORGE4D_TURKISH" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\TUR\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\TUR\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ITA\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ITA\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\FRA\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\FRA\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\POL\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\POL\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "FieldServer___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ESP\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ESP\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "FieldServer___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "FieldServer___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\Bin\Release\RUS\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "FieldServer___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "FieldServer___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\JPN\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\JPN\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "FieldServer___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ARG\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ARG\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 D_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "FieldServer___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "FieldServer___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "FieldServer___Win32_D_Masang_Global"
# PROP Intermediate_Dir "FieldServer___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "MASANG_GLOBAL" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_ATUM_LOAD_TEST" /D "MASANG_GLOBAL" /FR /YX"StdAfx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\GLOBAL\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLibD.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcpmtd.lib" /out:"..\..\Bin\Debug\GLOBAL\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "FieldServer - Win32 R_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "FieldServer___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "FieldServer___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "FieldServer___Win32_R_Masang_Global"
# PROP Intermediate_Dir "FieldServer___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "MASANG_GLOBAL" /YX"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_FIELD_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "_ATUM_LOAD_TEST" /D "MASANG_GLOBAL" /YX"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib QuestLoaderLib.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\FieldServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\FieldServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "FieldServer - Win32 Release"
# Name "FieldServer - Win32 Debug"
# Name "FieldServer - Win32 D_Test140"
# Name "FieldServer - Win32 D_Yedang_Kor"
# Name "FieldServer - Win32 D_Wikigames_Eng"
# Name "FieldServer - Win32 D_Yetime_Chn"
# Name "FieldServer - Win32 D_Intecom_Viet"
# Name "FieldServer - Win32 D_Gameforge4D_Eng"
# Name "FieldServer - Win32 D_Gameforge4D_Deu"
# Name "FieldServer - Win32 D_Gameforge4D_Turkish"
# Name "FieldServer - Win32 D_Gameforge4D_Italian"
# Name "FieldServer - Win32 D_Gameforge4D_France"
# Name "FieldServer - Win32 D_Gameforge4D_Pol"
# Name "FieldServer - Win32 D_Gameforge4D_Esp"
# Name "FieldServer - Win32 D_WinnerOnline_Tha"
# Name "FieldServer - Win32 D_WinnerOnline_SGP"
# Name "FieldServer - Win32 D_WinnerOnline_IDN"
# Name "FieldServer - Win32 D_Innova_Rus"
# Name "FieldServer - Win32 D_Netpower_Tpe"
# Name "FieldServer - Win32 D_Arario_Jpn"
# Name "FieldServer - Win32 D_LIN_Arg"
# Name "FieldServer - Win32 R_Test140"
# Name "FieldServer - Win32 R_Yedang_Kor"
# Name "FieldServer - Win32 R_Wikigames_Eng"
# Name "FieldServer - Win32 R_Yetime_Chn"
# Name "FieldServer - Win32 R_Intecom_Viet"
# Name "FieldServer - Win32 R_Gameforge4D_Eng"
# Name "FieldServer - Win32 R_Gameforge4D_Deu"
# Name "FieldServer - Win32 R_Gameforge4D_Turkish"
# Name "FieldServer - Win32 R_Gameforge4D_Italian"
# Name "FieldServer - Win32 R_Gameforge4D_France"
# Name "FieldServer - Win32 R_Gameforge4D_Pol"
# Name "FieldServer - Win32 R_Gameforge4D_Esp"
# Name "FieldServer - Win32 R_WinnerOnline_Tha"
# Name "FieldServer - Win32 R_WinnerOnline_SGP"
# Name "FieldServer - Win32 R_WinnerOnline_IDN"
# Name "FieldServer - Win32 R_Innova_Rus"
# Name "FieldServer - Win32 R_Netpower_Tpe"
# Name "FieldServer - Win32 R_Arario_Jpn"
# Name "FieldServer - Win32 R_LIN_Arg"
# Name "FieldServer - Win32 D_Masang_Global"
# Name "FieldServer - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AllGuildItemManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Security\ApexProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\ArenaDeathMatchRoom.cpp
# End Source File
# Begin Source File

SOURCE=.\ArenaFieldWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\ArenaManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ArenaTeam.cpp
# End Source File
# Begin Source File

SOURCE=.\ArenaTickManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\ArmorCollection.cpp
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

SOURCE=.\main\AtumFieldDBManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumLogSender.cpp
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

SOURCE=..\CommonGameServer\AtumThread.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\BazaarManager.cpp
# End Source File
# Begin Source File

SOURCE=.\BillCrux_BillingLib.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Billing_Yetime_Chn.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\BunchCountableItemCount.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\CallWarpEventManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ChatBlockManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Cinema.cpp
# End Source File
# Begin Source File

SOURCE=.\CityLeader.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\CityWar.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\CityWarManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\CollectionManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Config.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CountdownChecker.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\CouponManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Debuff.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\DestroyAuctionManager.cpp
# End Source File
# Begin Source File

SOURCE=.\DissolutionItemmanager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Dot.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\DropItemManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\EXPDivisionManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldCharacterQuest.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldDataManager.cpp
# End Source File
# Begin Source File

SOURCE=.\FieldDebuff.cpp
# End Source File
# Begin Source File

SOURCE=.\FieldDot.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldGlobal.cpp
# End Source File
# Begin Source File

SOURCE=.\main\FieldIOCP.cpp
# End Source File
# Begin Source File

SOURCE=.\main\FieldIOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldIOCPSocket2.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldItemManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldMapChannel.cpp
# End Source File
# Begin Source File

SOURCE=.\main\FieldMapProject.cpp
# End Source File
# Begin Source File

SOURCE=.\main\FieldMapWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldMonster.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldODBC.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldParty.cpp
# End Source File
# Begin Source File

SOURCE=.\FieldServer.cpp
# End Source File
# Begin Source File

SOURCE=.\FieldServer.rc
# End Source File
# Begin Source File

SOURCE=.\Main\FieldSkillManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldTickManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldTimerManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebIOCP.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebIOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebTickManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GameDataLast.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\GameEventManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\GeneralRequestHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GenericHTTPClient.cpp
# End Source File
# Begin Source File

SOURCE=.\GiveItemManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Global.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\GlobalFunc.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GlobalGameServer.cpp
# End Source File
# Begin Source File

SOURCE=.\GuildDamageManager.cpp
# End Source File
# Begin Source File

SOURCE=.\GuildItemManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\GuildWar.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\HappyHourEventManager.cpp
# End Source File
# Begin Source File

SOURCE=.\main\IMWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityBase.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityBossrush.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityDefence.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityManager.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityMapManager.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityMShipBattle.cpp
# End Source File
# Begin Source File

SOURCE=.\InfinityTickManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\InflRateManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\InflWarManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\InnovaLibrary.cpp
# End Source File
# Begin Source File

SOURCE=.\InvokingItemInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\InvokingItemManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\LetterManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\LoadLibrary.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Localization.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\LogWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapBlock.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapChannel.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\MapOwnership.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapProject.cpp
# End Source File
# Begin Source File

SOURCE=.\MapTriggerManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\MarketDataManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.cpp
# End Source File
# Begin Source File

SOURCE=.\MemoryHackHistory.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Monster.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MonsterDBAccess.cpp
# End Source File
# Begin Source File

SOURCE=.\MonthlyArmorManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\NPCScripts.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.cpp
# End Source File
# Begin Source File

SOURCE=.\OutPost.cpp
# End Source File
# Begin Source File

SOURCE=.\OutPostManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Overlapped.cpp
# End Source File
# Begin Source File

SOURCE=.\PCBangIPManager.cpp
# End Source File
# Begin Source File

SOURCE=.\PetDataManager.cpp
# End Source File
# Begin Source File

SOURCE=.\main\PreWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Quest.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\QuestMatching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\Racing.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\RacingDemon.cpp
# End Source File
# Begin Source File

SOURCE=.\Revision.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SecurityManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\ServicePauseManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\sha256.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\SpeedHackHistory.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticsManager.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\..\Common\SystemLogManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\ThreadCheck.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\TickManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerCrystalDestroyGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerCrystalGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionCrystal.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionNGCInflWar.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionNGOutPost.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerMapBuffManager.cpp
# End Source File
# Begin Source File

SOURCE=.\TriggerNGCInflWarMonsterGroup.cpp
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

SOURCE=.\WarContributionCalculation.cpp
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

SOURCE=.\Main\WRankingFame.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingFameManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingLevel.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingLevelManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingPVP.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingPVPManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingServiceManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\XmlRpc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\XOR_Lib.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Security\XTrap4Server.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Security\zwave_sdk_linker.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AllGuildItemManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Security\ApexProxy.h
# End Source File
# Begin Source File

SOURCE=.\ArenaDeathMatchRoom.h
# End Source File
# Begin Source File

SOURCE=.\ArenaFieldWinSocket.h
# End Source File
# Begin Source File

SOURCE=.\ArenaManager.h
# End Source File
# Begin Source File

SOURCE=.\ArenaTeam.h
# End Source File
# Begin Source File

SOURCE=.\ArenaTickManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\ArmorCollection.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDataLoader.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDateTime.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBHelper.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumError.h
# End Source File
# Begin Source File

SOURCE=.\main\AtumFieldDBManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumLogSender.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParam.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumProtocol.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumSJ.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumThread.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumTime.h
# End Source File
# Begin Source File

SOURCE=.\Main\BazaarManager.h
# End Source File
# Begin Source File

SOURCE=.\BillCrux_BillingLib.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Billing_Yetime_Chn.h
# End Source File
# Begin Source File

SOURCE=.\Main\BunchCountableItemCount.h
# End Source File
# Begin Source File

SOURCE=.\Main\CallWarpEventManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ChatBlockManager.h
# End Source File
# Begin Source File

SOURCE=.\Cinema.h
# End Source File
# Begin Source File

SOURCE=.\CityLeader.h
# End Source File
# Begin Source File

SOURCE=.\Main\CityWar.h
# End Source File
# Begin Source File

SOURCE=.\Main\CityWarManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\CollectionManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Config.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CountdownChecker.h
# End Source File
# Begin Source File

SOURCE=.\Main\CouponManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Debuff.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\DefineGlobal.h
# End Source File
# Begin Source File

SOURCE=.\Main\DestroyAuctionManager.h
# End Source File
# Begin Source File

SOURCE=.\DissolutionItemmanager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Dot.h
# End Source File
# Begin Source File

SOURCE=.\Main\DropItemManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\EXPDivisionManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldCharacterQuest.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldDataManager.h
# End Source File
# Begin Source File

SOURCE=.\FieldDebuff.h
# End Source File
# Begin Source File

SOURCE=.\FieldDot.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldGlobal.h
# End Source File
# Begin Source File

SOURCE=.\main\FieldIOCP.h
# End Source File
# Begin Source File

SOURCE=.\main\FieldIOCPSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldItemManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldMapChannel.h
# End Source File
# Begin Source File

SOURCE=.\main\FieldMapProject.h
# End Source File
# Begin Source File

SOURCE=.\main\FieldMapWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldMonster.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldODBC.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldParty.h
# End Source File
# Begin Source File

SOURCE=.\FieldServer.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldSkillManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldTickManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldTimerManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebIOCP.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebIOCPSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\FieldWebTickManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GameDataLast.h
# End Source File
# Begin Source File

SOURCE=.\Main\GameEventManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\GeneralRequestHandler.h
# End Source File
# Begin Source File

SOURCE=.\GiveItemManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GlobalGameServer.h
# End Source File
# Begin Source File

SOURCE=.\GuildDamageManager.h
# End Source File
# Begin Source File

SOURCE=.\GuildItemManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\GuildWar.h
# End Source File
# Begin Source File

SOURCE=.\Main\HappyHourEventManager.h
# End Source File
# Begin Source File

SOURCE=.\main\IMWinSocket.h
# End Source File
# Begin Source File

SOURCE=.\InfinityBase.h
# End Source File
# Begin Source File

SOURCE=.\InfinityBossrush.h
# End Source File
# Begin Source File

SOURCE=.\InfinityDefence.h
# End Source File
# Begin Source File

SOURCE=.\InfinityManager.h
# End Source File
# Begin Source File

SOURCE=.\InfinityMapManager.h
# End Source File
# Begin Source File

SOURCE=.\InfinityMShipBattle.h
# End Source File
# Begin Source File

SOURCE=.\InfinityTickManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\InflRateManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\InflWarManager.h
# End Source File
# Begin Source File

SOURCE=.\InvokingItemInfo.h
# End Source File
# Begin Source File

SOURCE=.\InvokingItemManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.h
# End Source File
# Begin Source File

SOURCE=.\LetterManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Localization.h
# End Source File
# Begin Source File

SOURCE=.\Main\LogWinSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\MallAgentConnect.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapBlock.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapChannel.h
# End Source File
# Begin Source File

SOURCE=.\Main\MapOwnership.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapProject.h
# End Source File
# Begin Source File

SOURCE=.\MapTriggerManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\Main\MarketDataManager.h
# End Source File
# Begin Source File

SOURCE=.\MemoryHackHistory.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Monster.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MonsterDBAccess.h
# End Source File
# Begin Source File

SOURCE=.\MonthlyArmorManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\mt_stl.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTCriticalSection.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.h
# End Source File
# Begin Source File

SOURCE=.\OutPost.h
# End Source File
# Begin Source File

SOURCE=.\OutPostManager.h
# End Source File
# Begin Source File

SOURCE=.\PCBangIPManager.h
# End Source File
# Begin Source File

SOURCE=.\PetDataManager.h
# End Source File
# Begin Source File

SOURCE=.\main\PreWinSocket.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Quest.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\QuestLoaderParser.h
# End Source File
# Begin Source File

SOURCE=.\Main\QuestMatching.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.h
# End Source File
# Begin Source File

SOURCE=.\Main\Racing.h
# End Source File
# Begin Source File

SOURCE=.\Main\RacingDemon.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\Revision.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SecurityManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\ServicePauseManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\sha256.h
# End Source File
# Begin Source File

SOURCE=.\SpeedHackHistory.h
# End Source File
# Begin Source File

SOURCE=.\StatisticsManager.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\StringDefineSecurityCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\SystemLogManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\TickManager.h
# End Source File
# Begin Source File

SOURCE=.\TriggerCrystalDestroyGroup.h
# End Source File
# Begin Source File

SOURCE=.\TriggerCrystalGroup.h
# End Source File
# Begin Source File

SOURCE=.\TriggerFunction.h
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionCrystal.h
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionNGCInflWar.h
# End Source File
# Begin Source File

SOURCE=.\TriggerFunctionNGOutPost.h
# End Source File
# Begin Source File

SOURCE=.\TriggerMapBuffManager.h
# End Source File
# Begin Source File

SOURCE=.\TriggerNGCInflWarMonsterGroup.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\UserVariable.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\VMem.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\VMemPool.h
# End Source File
# Begin Source File

SOURCE=.\WarContributionCalculation.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\WayPointManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinPacket.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingFame.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingFameManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingLevel.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingLevelManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingPVP.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingPVPManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\WRankingServiceManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\XmlRpc.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\FieldServer.ico
# End Source File
# Begin Source File

SOURCE=.\small.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\FieldServerModifyList.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
