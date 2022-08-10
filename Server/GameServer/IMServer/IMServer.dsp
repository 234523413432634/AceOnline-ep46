# Microsoft Developer Studio Project File - Name="IMServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=IMServer - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "IMServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IMServer.mak" CFG="IMServer - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IMServer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "IMServer - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "IMServer - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\IMServer\Release"
# PROP Intermediate_Dir "..\..\output\IMServer\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
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
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\IMServer\Debug"
# PROP Intermediate_Dir "..\..\output\IMServer\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Test140"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Test140"
# PROP Intermediate_Dir "IMServer___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TEST140" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Comctl32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\IMServer.exe" /pdbtype:sept /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Yedang_Kor"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Yedang_Kor"
# PROP Intermediate_Dir "IMServer___Win32_D_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YEDANG_KOR" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\KOR\IMServer.exe" /pdbtype:sept /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Wikigames_Eng"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Wikigames_Eng"
# PROP Intermediate_Dir "IMServer___Win32_D_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WIKIGAMES_ENG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\CAN\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "IMServer___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YETIME_CHN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\CHN\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "IMServer___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INTECOM_VIET" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\VIE\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ENG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ENG\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_DEU" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\DEU\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_TURKISH" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\TUR\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ITA\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\FRA\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\POL\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "IMServer___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ESP\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "IMServer___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "IMServer___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "IMServer___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "IMServer___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "IMServer___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "IMServer___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\JPN\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "IMServer___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ARG\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Test140"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Test140"
# PROP Intermediate_Dir "IMServer___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "TEST140" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Comctl32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "IMServer___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YEDANG_KOR" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /pdb:"..\..\BuildResultSvr\KOR\Dbg\IMServer.pdb" /map:"..\..\BuildResultSvr\KOR\Dbg\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\KOR\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "IMServer___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WIKIGAMES_ENG" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CAN\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "IMServer___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YETIME_CHN" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CHN\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CHN\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "IMServer___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "INTECOM_VIET" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\VIE\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\VIE\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ENG" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ENG\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ENG\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_DEU" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\DEU\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\DEU\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_TURKISH" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\TUR\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\TUR\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ITA\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ITA\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\FRA\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\FRA\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\POL\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\POL\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "IMServer___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ESP\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ESP\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "IMServer___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "IMServer___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "IMServer___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "IMServer___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\Bin\Release\RUS\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "IMServer___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "IMServer___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\JPN\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\JPN\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "IMServer___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ARG\Server\Bin\Release\IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ARG\Server\Bin\Release\IMServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 D_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "IMServer___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "IMServer___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "IMServer___Win32_D_Masang_Global"
# PROP Intermediate_Dir "IMServer___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\IMServer.exe" /pdbtype:sept /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "IMServer - Win32 R_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "IMServer___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "IMServer___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "IMServer___Win32_R_Masang_Global"
# PROP Intermediate_Dir "IMServer___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /Yu"stdafx.h" /FD /c
# SUBTRACT BASE CPP /Fr
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /D "NDEBUG" /D "_MBCS" /D "_ATUM_IM_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 winmm.lib D3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release/IMServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\IMServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "IMServer - Win32 Release"
# Name "IMServer - Win32 Debug"
# Name "IMServer - Win32 D_Test140"
# Name "IMServer - Win32 D_Yedang_Kor"
# Name "IMServer - Win32 D_Wikigames_Eng"
# Name "IMServer - Win32 D_Yetime_Chn"
# Name "IMServer - Win32 D_Intecom_Viet"
# Name "IMServer - Win32 D_Gameforge4D_Eng"
# Name "IMServer - Win32 D_Gameforge4D_Deu"
# Name "IMServer - Win32 D_Gameforge4D_Turkish"
# Name "IMServer - Win32 D_Gameforge4D_Italian"
# Name "IMServer - Win32 D_Gameforge4D_France"
# Name "IMServer - Win32 D_Gameforge4D_Pol"
# Name "IMServer - Win32 D_Gameforge4D_Esp"
# Name "IMServer - Win32 D_WinnerOnline_Tha"
# Name "IMServer - Win32 D_WinnerOnline_SGP"
# Name "IMServer - Win32 D_WinnerOnline_IDN"
# Name "IMServer - Win32 D_Innova_Rus"
# Name "IMServer - Win32 D_Netpower_Tpe"
# Name "IMServer - Win32 D_Arario_Jpn"
# Name "IMServer - Win32 D_LIN_Arg"
# Name "IMServer - Win32 R_Test140"
# Name "IMServer - Win32 R_Yedang_Kor"
# Name "IMServer - Win32 R_Wikigames_Eng"
# Name "IMServer - Win32 R_Yetime_Chn"
# Name "IMServer - Win32 R_Intecom_Viet"
# Name "IMServer - Win32 R_Gameforge4D_Eng"
# Name "IMServer - Win32 R_Gameforge4D_Deu"
# Name "IMServer - Win32 R_Gameforge4D_Turkish"
# Name "IMServer - Win32 R_Gameforge4D_Italian"
# Name "IMServer - Win32 R_Gameforge4D_France"
# Name "IMServer - Win32 R_Gameforge4D_Pol"
# Name "IMServer - Win32 R_Gameforge4D_Esp"
# Name "IMServer - Win32 R_WinnerOnline_Tha"
# Name "IMServer - Win32 R_WinnerOnline_SGP"
# Name "IMServer - Win32 R_WinnerOnline_IDN"
# Name "IMServer - Win32 R_Innova_Rus"
# Name "IMServer - Win32 R_Netpower_Tpe"
# Name "IMServer - Win32 R_Arario_Jpn"
# Name "IMServer - Win32 R_LIN_Arg"
# Name "IMServer - Win32 D_Masang_Global"
# Name "IMServer - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Main\ANoticeManager.cpp
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

SOURCE=.\main\AtumIMDBManager.cpp
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

SOURCE=..\CommonGameServer\ChatBlockManager.cpp
# End Source File
# Begin Source File

SOURCE=.\ChatRoom.cpp
# End Source File
# Begin Source File

SOURCE=.\ChatRoomManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Config.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CountdownChecker.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Global.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GlobalGameServer.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Guild.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\IMGlobal.cpp
# End Source File
# Begin Source File

SOURCE=.\main\IMIOCP.cpp
# End Source File
# Begin Source File

SOURCE=.\main\IMIOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\IMParty.cpp
# End Source File
# Begin Source File

SOURCE=.\IMServer.cpp
# End Source File
# Begin Source File

SOURCE=.\IMServer.rc
# End Source File
# Begin Source File

SOURCE=.\Main\IMTickManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Localization.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Overlapped.cpp
# End Source File
# Begin Source File

SOURCE=.\main\PreIMWinSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SecurityManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ServerGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\sha256.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\StringDefineSecurityCommand.h
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
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Main\ANoticeManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumDBManager.h
# End Source File
# Begin Source File

SOURCE=.\main\AtumIMDBManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParam.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumProtocol.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumProtocolVoIP.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumThread.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ChatBlockManager.h
# End Source File
# Begin Source File

SOURCE=.\ChatRoom.h
# End Source File
# Begin Source File

SOURCE=.\ChatRoomManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\CountdownChecker.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Guild.h
# End Source File
# Begin Source File

SOURCE=.\Main\IMGlobal.h
# End Source File
# Begin Source File

SOURCE=.\main\IMIOCP.h
# End Source File
# Begin Source File

SOURCE=.\main\IMIOCPSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\IMParty.h
# End Source File
# Begin Source File

SOURCE=.\IMServer.h
# End Source File
# Begin Source File

SOURCE=.\Main\IMTickManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCPSocket.h
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

SOURCE=.\main\PreIMWinSocket.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\TickManager.h
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
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\IMServer.ico
# End Source File
# Begin Source File

SOURCE=.\small.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\IMServerModifyList.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\SecurityManager.h
# End Source File
# End Target
# End Project
