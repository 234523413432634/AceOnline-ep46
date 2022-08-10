# Microsoft Developer Studio Project File - Name="NPCServer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=NPCServer - Win32 D_Masang_Global
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NPCServer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NPCServer.mak" CFG="NPCServer - Win32 D_Masang_Global"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NPCServer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Test140" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Test140" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Yedang_Kor" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Wikigames_Eng" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Yetime_Chn" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Intecom_Viet" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Eng" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Deu" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Turkish" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Italian" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_France" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Pol" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Gameforge4D_Esp" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_WinnerOnline_Tha" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_WinnerOnline_SGP" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_WinnerOnline_IDN" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Innova_Rus" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Netpower_Tpe" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Arario_Jpn" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_LIN_Arg" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 D_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE "NPCServer - Win32 R_Masang_Global" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NPCServer - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\output\NPCServer\Release"
# PROP Intermediate_Dir "..\..\output\NPCServer\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\output\NPCServer\Debug"
# PROP Intermediate_Dir "..\..\output\NPCServer\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Test140"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Test140"
# PROP Intermediate_Dir "NPCServer___Win32_D_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TEST140" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib Comctl32.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Yedang_Kor"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Yedang_Kor"
# PROP Intermediate_Dir "NPCServer___Win32_D_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YEDANG_KOR" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\KOR\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Wikigames_Eng"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Wikigames_Eng"
# PROP Intermediate_Dir "NPCServer___Win32_D_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WIKIGAMES_ENG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\CAN\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Yetime_Chn"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Yetime_Chn"
# PROP Intermediate_Dir "NPCServer___Win32_D_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "YETIME_CHN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\CHN\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Intecom_Viet"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Intecom_Viet"
# PROP Intermediate_Dir "NPCServer___Win32_D_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INTECOM_VIET" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\VIE\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Eng"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ENG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ENG\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Deu"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_DEU" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\DEU\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Turkish"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_TURKISH" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\TUR\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Italian"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ITA\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_France"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_France"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\FRA\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Pol"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\POL\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Gameforge4D_Esp"
# PROP Intermediate_Dir "NPCServer___Win32_D_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ESP\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_WinnerOnline_Tha"
# PROP Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_WinnerOnline_SGP"
# PROP Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_WinnerOnline_IDN"
# PROP Intermediate_Dir "NPCServer___Win32_D_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Innova_Rus"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Innova_Rus"
# PROP Intermediate_Dir "NPCServer___Win32_D_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Netpower_Tpe"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Netpower_Tpe"
# PROP Intermediate_Dir "NPCServer___Win32_D_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Arario_Jpn"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Arario_Jpn"
# PROP Intermediate_Dir "NPCServer___Win32_D_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\JPN\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_LIN_Arg"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_LIN_Arg"
# PROP Intermediate_Dir "NPCServer___Win32_D_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\ARG\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Test140"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Test140"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Test140"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Test140"
# PROP Intermediate_Dir "NPCServer___Win32_R_Test140"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "TEST140" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib Comctl32.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Yedang_Kor"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Yedang_Kor"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Yedang_Kor"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Yedang_Kor"
# PROP Intermediate_Dir "NPCServer___Win32_R_Yedang_Kor"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YEDANG_KOR" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /pdb:"..\..\BuildResultSvr\KOR\Dbg\NPCServer.pdb" /map:"..\..\BuildResultSvr\KOR\Dbg\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\KOR\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Wikigames_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Wikigames_Eng"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Wikigames_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Wikigames_Eng"
# PROP Intermediate_Dir "NPCServer___Win32_R_Wikigames_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "WIKIGAMES_ENG" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CAN\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Yetime_Chn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Yetime_Chn"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Yetime_Chn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Yetime_Chn"
# PROP Intermediate_Dir "NPCServer___Win32_R_Yetime_Chn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "YETIME_CHN" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CHN\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\CHN\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Intecom_Viet"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Intecom_Viet"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Intecom_Viet"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Intecom_Viet"
# PROP Intermediate_Dir "NPCServer___Win32_R_Intecom_Viet"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "INTECOM_VIET" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\VIE\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\VIE\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Eng"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Eng"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Eng"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Eng"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_ENG" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ENG\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ENG\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Deu"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Deu"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Deu"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Deu"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_DEU" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\DEU\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\DEU\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Turkish"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Turkish"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Turkish"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Turkish"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "GAMEFORGE4D_TURKISH" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\TUR\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\TUR\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Italian"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Italian"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Italian"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Italian"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ITALIAN" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ITA\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ITA\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_France"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_France"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_France"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_France"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_France"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_FRANCE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\FRA\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\FRA\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Pol"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Pol"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Pol"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Pol"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_POL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\POL\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\POL\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Gameforge4D_Esp"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Esp"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Gameforge4D_Esp"
# PROP Intermediate_Dir "NPCServer___Win32_R_Gameforge4D_Esp"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "GAMEFORGE4D_ESP" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ESP\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ESP\Server\Bin\Release\NPCServer.exe" /libpath:"..\..\Lib" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_WinnerOnline_Tha"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_Tha"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_WinnerOnline_Tha"
# PROP Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_Tha"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_THA" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_WinnerOnline_SGP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_SGP"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_WinnerOnline_SGP"
# PROP Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_SGP"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_SGP" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_WinnerOnline_IDN"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_IDN"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_WinnerOnline_IDN"
# PROP Intermediate_Dir "NPCServer___Win32_R_WinnerOnline_IDN"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "WINNERONLINE_IDN" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Innova_Rus"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Innova_Rus"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Innova_Rus"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Innova_Rus"
# PROP Intermediate_Dir "NPCServer___Win32_R_Innova_Rus"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "INNOVA_RUS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\Bin\Release\RUS\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Netpower_Tpe"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Netpower_Tpe"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Netpower_Tpe"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Netpower_Tpe"
# PROP Intermediate_Dir "NPCServer___Win32_R_Netpower_Tpe"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "NETPOWER_TPE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Arario_Jpn"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Arario_Jpn"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Arario_Jpn"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Arario_Jpn"
# PROP Intermediate_Dir "NPCServer___Win32_R_Arario_Jpn"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "ARARIO_JPN" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\JPN\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\JPN\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_LIN_Arg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_LIN_Arg"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_LIN_Arg"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_LIN_Arg"
# PROP Intermediate_Dir "NPCServer___Win32_R_LIN_Arg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_MBCS" /D "WIN32" /D "_WINDOWS" /D "LIN_ARG" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\Bin\Release/NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\Server\Bin\Release/NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\ARG\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\ARG\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 D_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NPCServer___Win32_D_Masang_Global"
# PROP BASE Intermediate_Dir "NPCServer___Win32_D_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NPCServer___Win32_D_Masang_Global"
# PROP Intermediate_Dir "NPCServer___Win32_D_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "_ATUM_SERVER" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "MASANG_GLOBAL" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /incremental:no /map /debug /machine:I386 /out:"..\..\Bin\Debug\GLOBAL\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "NPCServer - Win32 R_Masang_Global"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "NPCServer___Win32_R_Masang_Global"
# PROP BASE Intermediate_Dir "NPCServer___Win32_R_Masang_Global"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "NPCServer___Win32_R_Masang_Global"
# PROP Intermediate_Dir "NPCServer___Win32_R_Masang_Global"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "." /I "..\..\Common" /I ".\Main" /I "..\CommonGameServer" /I ".\D3D\Include" /I ".\D3D\Src" /D "NDEBUG" /D "_MBCS" /D "_ATUM_NPC_SERVER" /D "WIN32" /D "_WINDOWS" /D "_ATUM_SERVER" /D "MASANG_GLOBAL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 d3d8.lib D3dx8.lib D3dxof.lib Dxguid.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib Winmm.lib /nologo /subsystem:windows /map:"..\..\BuildResultSvr\CAN\Server\Bin\Release\NPCServer.map" /debug /machine:I386 /out:"..\..\BuildResultSvr\GLOBAL\Server\Bin\Release\NPCServer.exe" /MAPINFO:EXPORTS /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "NPCServer - Win32 Release"
# Name "NPCServer - Win32 Debug"
# Name "NPCServer - Win32 D_Test140"
# Name "NPCServer - Win32 D_Yedang_Kor"
# Name "NPCServer - Win32 D_Wikigames_Eng"
# Name "NPCServer - Win32 D_Yetime_Chn"
# Name "NPCServer - Win32 D_Intecom_Viet"
# Name "NPCServer - Win32 D_Gameforge4D_Eng"
# Name "NPCServer - Win32 D_Gameforge4D_Deu"
# Name "NPCServer - Win32 D_Gameforge4D_Turkish"
# Name "NPCServer - Win32 D_Gameforge4D_Italian"
# Name "NPCServer - Win32 D_Gameforge4D_France"
# Name "NPCServer - Win32 D_Gameforge4D_Pol"
# Name "NPCServer - Win32 D_Gameforge4D_Esp"
# Name "NPCServer - Win32 D_WinnerOnline_Tha"
# Name "NPCServer - Win32 D_WinnerOnline_SGP"
# Name "NPCServer - Win32 D_WinnerOnline_IDN"
# Name "NPCServer - Win32 D_Innova_Rus"
# Name "NPCServer - Win32 D_Netpower_Tpe"
# Name "NPCServer - Win32 D_Arario_Jpn"
# Name "NPCServer - Win32 D_LIN_Arg"
# Name "NPCServer - Win32 R_Test140"
# Name "NPCServer - Win32 R_Yedang_Kor"
# Name "NPCServer - Win32 R_Wikigames_Eng"
# Name "NPCServer - Win32 R_Yetime_Chn"
# Name "NPCServer - Win32 R_Intecom_Viet"
# Name "NPCServer - Win32 R_Gameforge4D_Eng"
# Name "NPCServer - Win32 R_Gameforge4D_Deu"
# Name "NPCServer - Win32 R_Gameforge4D_Turkish"
# Name "NPCServer - Win32 R_Gameforge4D_Italian"
# Name "NPCServer - Win32 R_Gameforge4D_France"
# Name "NPCServer - Win32 R_Gameforge4D_Pol"
# Name "NPCServer - Win32 R_Gameforge4D_Esp"
# Name "NPCServer - Win32 R_WinnerOnline_Tha"
# Name "NPCServer - Win32 R_WinnerOnline_SGP"
# Name "NPCServer - Win32 R_WinnerOnline_IDN"
# Name "NPCServer - Win32 R_Innova_Rus"
# Name "NPCServer - Win32 R_Netpower_Tpe"
# Name "NPCServer - Win32 R_Arario_Jpn"
# Name "NPCServer - Win32 R_LIN_Arg"
# Name "NPCServer - Win32 D_Masang_Global"
# Name "NPCServer - Win32 R_Masang_Global"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
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

SOURCE=.\Main\AtumNode.cpp
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

SOURCE=..\CommonGameServer\Config.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GameDataLast.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Global.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GlobalGameServer.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\HPAction.cpp
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

SOURCE=..\CommonGameServer\MapBlock.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapProject.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\md5_lib_src.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Monster.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MonsterDBAccess.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTCriticalSection.cpp
# End Source File
# Begin Source File

SOURCE=.\main\N2FSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\NPCGlobal.cpp
# End Source File
# Begin Source File

SOURCE=.\main\NPCIOCP.cpp
# End Source File
# Begin Source File

SOURCE=.\main\NPCIOCPSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\NPCMapChannel.cpp
# End Source File
# Begin Source File

SOURCE=.\main\NPCMapProject.cpp
# End Source File
# Begin Source File

SOURCE=.\main\NPCMapWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\NPCMonster.cpp
# End Source File
# Begin Source File

SOURCE=.\NPCServer.cpp
# End Source File
# Begin Source File

SOURCE=.\NPCServer.rc
# End Source File
# Begin Source File

SOURCE=.\NPCSkillManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\NPCTickManager.cpp
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\Overlapped.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\QueueINT.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\sha256.cpp
# End Source File
# Begin Source File

SOURCE=.\Main\SkinnedMesh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Common\SocketHeader.cpp
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

SOURCE=.\Main\AtumNode.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumParam.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\AtumProtocol.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Config.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\DebugAssert.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GameDataLast.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\GeneralArray.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\HPAction.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCP.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\IOCPSocket.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapBlock.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapChannel.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapProject.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MapWorkspace.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\Monster.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\MonsterDBAccess.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\MTAutoCriticalSection.h
# End Source File
# Begin Source File

SOURCE=.\main\N2FSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\NPCGlobal.h
# End Source File
# Begin Source File

SOURCE=.\main\NPCIOCP.h
# End Source File
# Begin Source File

SOURCE=.\main\NPCIOCPSocket.h
# End Source File
# Begin Source File

SOURCE=.\Main\NPCMapChannel.h
# End Source File
# Begin Source File

SOURCE=.\main\NPCMapProject.h
# End Source File
# Begin Source File

SOURCE=.\main\NPCMapWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\Main\NPCMonster.h
# End Source File
# Begin Source File

SOURCE=.\NPCServer.h
# End Source File
# Begin Source File

SOURCE=.\NPCSkillManager.h
# End Source File
# Begin Source File

SOURCE=.\Main\NPCTickManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\ODBCStatement.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\Main\SkinnedMesh.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\SystemLogManager.h
# End Source File
# Begin Source File

SOURCE=..\CommonGameServer\WayPointManager.h
# End Source File
# Begin Source File

SOURCE=..\..\Common\WinPacket.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\NPCServer.ico
# End Source File
# Begin Source File

SOURCE=.\small.ico
# End Source File
# End Group
# Begin Group "D3D"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\D3D\src\d3dapp.cpp
# End Source File
# Begin Source File

SOURCE=.\D3D\include\d3dapp.h
# End Source File
# Begin Source File

SOURCE=.\D3D\src\d3dutil.cpp
# End Source File
# Begin Source File

SOURCE=.\D3D\src\dxutil.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\NPCServerModifyList.txt
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
