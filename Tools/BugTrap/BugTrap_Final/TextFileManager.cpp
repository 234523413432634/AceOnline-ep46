#include "StdAfx.h"
#include <fstream>
#include "CpuUsage.h"
#include <d3d9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#include "TextFileManager.h"

#pragma comment(lib, "User32.lib")

#define BUFSIZE 256

typedef void (WINAPI *PGETSYSTEMINFO)(LPSYSTEM_INFO);
typedef BOOL (WINAPI *PGETPRODUCTINFO)(DWORD, DWORD, DWORD, DWORD, PDWORD);

CTextFileManager::CTextFileManager()
{

}


CTextFileManager::~CTextFileManager(void)
{

}
void CTextFileManager::CreateTextFile(wchar_t* wFilePath)
{
	CCpuUsage    cpuUsage;
	if( cpuUsage.init() == false )
		return ;

	wchar_t wcText[512] = {0,};
	{
		std::ofstream SaveFile(wFilePath);
		SaveFile.close();
	}
	
	std::wfstream SaveFile(wFilePath);
	GetOsVersion(wcText);
	SaveFile << wcText;

	GetCpuInfo(wcText);
	SaveFile << wcText;

	for(int i= 0; i<1; ++i)
	{
		Sleep( 1000 );
		double  val = 0.0;
		if( cpuUsage.getCpuUsage( &val ) )
		{
			SaveFile << "Cpu Usage : " << val << "%\n";
		}

	}
	SaveFile<<std::endl;

	GetMemoryInfo(wcText);
	SaveFile << wcText;
	GetHddinfo(wcText);
	SaveFile << wcText;

	GetVGAinfo(wcText);
	SaveFile << wcText;

	SaveFile.close();
		
}
wchar_t* CTextFileManager::GetOsVersion(LPTSTR pszText)
{
	wchar_t pszOS[BUFSIZE];
	wchar_t ReturnString[BUFSIZE] = {0,};
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	PGETSYSTEMINFO pGetSystemInfo;
	PGETPRODUCTINFO pGetProductInfo;
	BOOL bOsVersionInfoEx;
	DWORD dwType;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	{
		_tcscat(pszText, _T("This sample does not support this version of Windows.\n"));
		return pszText;
	}

	// Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.

	pGetSystemInfo = (PGETSYSTEMINFO ) GetProcAddress(
		GetModuleHandle(TEXT("kernel32.dll")), 
		"GetNativeSystemInfo");
	if(NULL != pGetSystemInfo)
		pGetSystemInfo(&si);
	else GetSystemInfo(&si);

	if ( VER_PLATFORM_WIN32_NT==osvi.dwPlatformId && 
		osvi.dwMajorVersion > 4 )
	{
		StringCchCopy(pszOS, BUFSIZE, TEXT("Microsoft "));

		// Test for the specific product.

		if ( osvi.dwMajorVersion == 6 )
		{
			if( osvi.dwMinorVersion == 0 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows Vista "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2008 " ));
			}

			if ( osvi.dwMinorVersion == 1 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCat(pszOS, BUFSIZE, TEXT("Windows 7 "));
				else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2008 R2 " ));
			}

			pGetProductInfo = (PGETPRODUCTINFO) GetProcAddress(
				GetModuleHandle(TEXT("kernel32.dll")), 
				"GetProductInfo");

			pGetProductInfo( osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);

			switch( dwType )
			{
			case PRODUCT_ULTIMATE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Ultimate Edition" ));
				break;
			case 0x00000030:
				StringCchCat(pszOS, BUFSIZE, TEXT("Professional" ));
				break;
			case PRODUCT_HOME_PREMIUM:
				StringCchCat(pszOS, BUFSIZE, TEXT("Home Premium Edition" ));
				break;
			case PRODUCT_HOME_BASIC:
				StringCchCat(pszOS, BUFSIZE, TEXT("Home Basic Edition" ));
				break;
			case PRODUCT_ENTERPRISE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition" ));
				break;
			case PRODUCT_BUSINESS:
				StringCchCat(pszOS, BUFSIZE, TEXT("Business Edition" ));
				break;
			case PRODUCT_STARTER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Starter Edition" ));
				break;
			case PRODUCT_CLUSTER_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Cluster Server Edition" ));
				break;
			case PRODUCT_DATACENTER_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Datacenter Edition" ));
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Datacenter Edition (core installation)" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition (core installation)" ));
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				StringCchCat(pszOS, BUFSIZE, TEXT("Enterprise Edition for Itanium-based Systems" ));
				break;
			case PRODUCT_SMALLBUSINESS_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Small Business Server" ));
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				StringCchCat(pszOS, BUFSIZE, TEXT("Small Business Server Premium Edition" ));
				break;
			case PRODUCT_STANDARD_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Standard Edition" ));
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				StringCchCat(pszOS, BUFSIZE, TEXT("Standard Edition (core installation)" ));
				break;
			case PRODUCT_WEB_SERVER:
				StringCchCat(pszOS, BUFSIZE, TEXT("Web Server Edition" ));
				break;
			}
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 )
		{
			if( GetSystemMetrics(SM_SERVERR2) )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Server 2003 R2, "));
			else if ( osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Storage Server 2003"));
			else if ( osvi.wSuiteMask & 0x00008000  )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Windows Home Server"));
			else if( osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)
			{
				StringCchCat(pszOS, BUFSIZE, TEXT( "Windows XP Professional x64 Edition"));
			}
			else StringCchCat(pszOS, BUFSIZE, TEXT("Windows Server 2003, "));

			// Test for the server type.
			if ( osvi.wProductType != VER_NT_WORKSTATION )
			{
				if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64 )
				{
					if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Edition for Itanium-based Systems" ));
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise Edition for Itanium-based Systems" ));
				}

				else if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64 )
				{
					if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter x64 Edition" ));
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise x64 Edition" ));
					else StringCchCat(pszOS, BUFSIZE, TEXT( "Standard x64 Edition" ));
				}

				else
				{
					if ( osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Compute Cluster Edition" ));
					else if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Edition" ));
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Enterprise Edition" ));
					else if ( osvi.wSuiteMask & VER_SUITE_BLADE )
						StringCchCat(pszOS, BUFSIZE, TEXT( "Web Edition" ));
					else StringCchCat(pszOS, BUFSIZE, TEXT( "Standard Edition" ));
				}
			}
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
		{
			StringCchCat(pszOS, BUFSIZE, TEXT("Windows XP "));
			if( osvi.wSuiteMask & VER_SUITE_PERSONAL )
				StringCchCat(pszOS, BUFSIZE, TEXT( "Home Edition" ));
			else StringCchCat(pszOS, BUFSIZE, TEXT( "Professional" ));
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
		{
			StringCchCat(pszOS, BUFSIZE, TEXT("Windows 2000 "));

			if ( osvi.wProductType == VER_NT_WORKSTATION )
			{
				StringCchCat(pszOS, BUFSIZE, TEXT( "Professional" ));
			}
			else 
			{
				if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Datacenter Server" ));
				else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
					StringCchCat(pszOS, BUFSIZE, TEXT( "Advanced Server" ));
				else StringCchCat(pszOS, BUFSIZE, TEXT( "Server" ));
			}
		}

		// Include service pack (if any) and build number.

		if( _tcslen(osvi.szCSDVersion) > 0 )
		{
			StringCchCat(pszOS, BUFSIZE, TEXT(" ") );
			StringCchCat(pszOS, BUFSIZE, osvi.szCSDVersion);
		}

		TCHAR buf[80];

		StringCchPrintf( buf, 80, TEXT(" (build %d)"), osvi.dwBuildNumber);
		StringCchCat(pszOS, BUFSIZE, buf);

		if ( osvi.dwMajorVersion >= 6 )
		{
			if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64 )
				StringCchCat(pszOS, BUFSIZE, TEXT( ", 64-bit" ));
			else if (si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_INTEL )
				StringCchCat(pszOS, BUFSIZE, TEXT(", 32-bit"));
		}

		wsprintf(pszText, L"OS Version Information : %s\n\n", pszOS);
		return pszText;
	}

	else
	{  
		wsprintf(pszText, L"This sample does not support this version of Windows.\n\n");
		return pszText;
	}
}

void CTextFileManager::GetCpuInfo( LPTSTR pszText )
{
	// key를 먼저 얻어야함.
	HKEY hKey;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE ,L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",	0 ,KEY_READ ,&hKey);
	RegQueryValueEx(hKey, L"ProcessorNameString",  NULL, NULL, (LPBYTE)&m_strTemp, &m_dwTempSize);
	wsprintf(pszText, L"Cpu Name : %s\n", m_strTemp);
	

	RegOpenKeyEx(HKEY_LOCAL_MACHINE ,L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",	0 ,KEY_READ ,&hKey);
	RegQueryValueEx(hKey, L"ProcessorNameString",  NULL, NULL, (LPBYTE)&m_strTemp, &m_dwTempSize);
	wsprintf(pszText, L"Cpu Name : %s\n", m_strTemp);

	SYSTEM_INFO	sys;
	ZeroMemory(&sys, sizeof(SYSTEM_INFO));
	GetSystemInfo(&sys);
	_tcscat(pszText, _T("Cpu Core : "));
	switch(sys.dwNumberOfProcessors)
	{
	case 1:		//m_strData = L"싱글 코어"; 
		_tcscat(pszText, _T("Single Core"));
		break;
	case 2:		//m_strData = L"듀얼 코어"; 
		_tcscat(pszText, _T("Dual Core"));
		break;
	case 4:	//	m_strData = L"쿼드 코어"; 
		_tcscat(pszText, _T("Quad Core"));
		break;
	default:	//	m_strData = L"Unknown";
		_tcscat(pszText, _T("Unknown"));
		break;
	}

	long cpu_clock;
	DWORD dwSize = sizeof(long);
	RegQueryValueEx(hKey, TEXT("~MHz"),  NULL, NULL, (LPBYTE)&cpu_clock, &dwSize);
	wsprintf(m_strTemp, L" %ld MHz\n", cpu_clock);

	_tcscat(pszText, m_strTemp);

	_tcscat(pszText, _T("Cpu Model : "));

	RegQueryValueEx(hKey, L"Identifier",  NULL, NULL, (LPBYTE)&m_strTemp, &m_dwTempSize);

	_tcscat(pszText, m_strTemp);
	_tcscat(pszText, L"\n");

	RegCloseKey(hKey);
}

void CTextFileManager::GetMemoryInfo( LPTSTR pszText )
{
	MEMORYSTATUS mem;
	ZeroMemory(&mem, sizeof(MEMORYSTATUS));
	mem.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&mem);
	wchar_t TempString[256] = {0,};

	wsprintf(pszText, L"Memory UsePersent : %ld%%\n", (mem.dwMemoryLoad));
	wsprintf(TempString, L"Memmory TotalPhys : %ld Byte\n", (mem.dwTotalPhys / 1024));
	_tcscat(pszText, TempString);
	memset(TempString, 0x00, sizeof(TempString));

	wsprintf(TempString, L"Memmory AvailPhys : %ld Byte\n", (mem.dwAvailPhys / 1024));
	_tcscat(pszText, TempString);
	memset(TempString, 0x00, sizeof(TempString));

	wsprintf(TempString, L"Memmory TotalVirtual : %ld Byte\n", (mem.dwTotalVirtual / 1024));
	_tcscat(pszText, TempString);
	memset(TempString, 0x00, sizeof(TempString));

	wsprintf(TempString, L"Memmory AvailVirtual : %ld Byte\n\n", (mem.dwAvailVirtual / 1024));
	_tcscat(pszText, TempString);
}

void CTextFileManager::GetHddinfo( LPTSTR pszText )
{
	char* pszDirve = "C:";

	unsigned __int64 i64FreeBytesToCaller,
		i64TotalBytes,
		i64FreeBytes;

	// 첫번째 파라메터로 NULL을 넘기면 CurrentDir의 디스크 용량
	if( ::GetDiskFreeSpaceExA(NULL, (PULARGE_INTEGER)&i64FreeBytesToCaller, 
		(PULARGE_INTEGER)&i64TotalBytes, 
		(PULARGE_INTEGER)&i64FreeBytes ) == FALSE ) {
//			return 0;
	}
	memset(m_strTemp, 0x00, sizeof(m_strTemp));
	wsprintf(pszText, L"Current HDD Total Space : %I64dKByte\n", (i64TotalBytes/1024));

	wsprintf(m_strTemp, L"Current HDD Empty Space : %I64dKByte\n\n",(i64FreeBytes/1024));
	_tcscat(pszText, m_strTemp);
}

void CTextFileManager::GetVGAinfo( LPTSTR pszText )
{
	DISPLAY_DEVICE disp;
	ZeroMemory(&disp, sizeof(DISPLAY_DEVICE));
	disp.cb =  sizeof(DISPLAY_DEVICE);

	int nVgaCnt = 0;
	while ( EnumDisplayDevices(NULL, nVgaCnt, &disp, 0) )
	{
		if(disp.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)	
			wsprintf(pszText, L"Vga Model : %s\n", disp.DeviceString);

		nVgaCnt++;
		if(nVgaCnt == 100)
		{
			wsprintf(pszText, L"Vga Model : No Find VGA Info\n");
			return;
		}
	}

	 LPDIRECT3D9       g_pD3D = NULL; // Used to create the D3DDevice
	 D3DCAPS9 caps;
	 int nVP;
	 if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		 return;

	 D3DDISPLAYMODE dspm;
	 for(UINT i=0; i<g_pD3D->GetAdapterCount(); ++i)
	 {
		 g_pD3D->GetAdapterDisplayMode(i, &dspm);

		 wsprintf(m_strTemp, L"Vga Monitor : DISPLAY%d\n", (i+1));
		 _tcscat(pszText,m_strTemp);
		 wsprintf(m_strTemp, L"Vga Resolution : %d * %d\n", dspm.Width, dspm.Height);
		 _tcscat(pszText,m_strTemp);
		 wsprintf(m_strTemp, L"Vga  RefreshRate : %dHz\n", (dspm.RefreshRate));
		 _tcscat(pszText,m_strTemp);
	 }
	 
	 ZeroMemory(&caps, sizeof(D3DCAPS9));
	 g_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	 switch(caps.VertexShaderVersion)
	 {
	 case D3DVS_VERSION(1, 1):		wsprintf(m_strTemp, L"VertexShaderVersion : 1.1\n"); break;
	 case D3DVS_VERSION(2, 0):		wsprintf(m_strTemp, L"VertexShaderVersion : 2.0\n"); break;
	 case D3DVS_VERSION(3, 0):		wsprintf(m_strTemp, L"VertexShaderVersion : 3.0\n"); break;
	 default :		wsprintf(m_strTemp, L"VertexShaderVersion : Unknown\n"); break;
	 }

	 _tcscat(pszText,m_strTemp);

	 switch(caps.PixelShaderVersion)
	 {
	 case D3DPS_VERSION(1, 1):				wsprintf(m_strTemp, L"PixelShaderVersion : 1.1\n"); break;
	 case D3DPS_VERSION(1, 2):				wsprintf(m_strTemp, L"PixelShaderVersion : 1.2\n"); break;
	 case D3DPS_VERSION(1, 3):				wsprintf(m_strTemp, L"PixelShaderVersion : 1.3\n"); break;
	 case D3DPS_VERSION(1, 4):				wsprintf(m_strTemp, L"PixelShaderVersion : 1.4\n"); break;
	 case D3DPS_VERSION(2, 0):				wsprintf(m_strTemp, L"PixelShaderVersion : 2.0\n"); break;
	 case D3DPS_VERSION(3, 0):				wsprintf(m_strTemp, L"PixelShaderVersion : 3.0\n"); break;
	 default :								wsprintf(m_strTemp, L"PixelShaderVersion : Unknown\n"); break;
	 }

	 _tcscat(pszText,m_strTemp);

	 wsprintf(m_strTemp, L"NumSimultaneousRTs : %d\n", caps.NumSimultaneousRTs);
	 _tcscat(pszText,m_strTemp);
	 wsprintf(m_strTemp, L"MaxTextureWidth : %d\n", caps.MaxTextureWidth);
	 _tcscat(pszText,m_strTemp);
	 wsprintf(m_strTemp, L"MaxTextureHeight : %d\n", caps.MaxTextureHeight);
	 _tcscat(pszText,m_strTemp);
	 wsprintf(m_strTemp, L"MaxVolumeExtent : %d\n", caps.MaxVolumeExtent);
	 _tcscat(pszText,m_strTemp);
}