// Profiler.cpp: implementation of the CProfiler class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Profiler.h"
#include "AtumApplication.h"
#include "D3DHanFont.h"
#include "ShuttleChild.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProfiler::CProfiler()
{
	m_bShowWnd = FALSE;
	m_dwLastTime = 0;
	m_stTotalTime.dwTotalUsedTime = 0;
	m_stTotalTime.nCnt = 0;
	m_dwStartTime = 0;
	m_pItemName = "";
	m_mapUsedTime.clear();
	m_mapTotalUsedTime.clear();
	mem = NULL;
	m_pProfilerFont = NULL;
}

CProfiler::~CProfiler()
{
	SAFE_DELETE(m_pProfilerFont);
}

HRESULT CProfiler::InitDeviceObjects()
{
	if(NULL == m_pProfilerFont)
	{
		m_pProfilerFont = new CD3DHanFont(_T(g_pD3dApp->GetFontStyle()), 9, D3DFONT_ZENABLE, TRUE, 512, 32);
		m_pProfilerFont->InitDeviceObjects(g_pD3dDev);
	}
	// 2014-12-03 by jwLee 메모리 출력 코드 추가
	mem = new MEMORYSTATUS;
	// end 2014-12-03 by jwLee 메모리 출력 코드 추가

	return S_OK; 
}

HRESULT CProfiler::RestoreDeviceObjects()
{
	if(m_pProfilerFont)
		m_pProfilerFont->RestoreDeviceObjects();

	return S_OK; 
}

HRESULT CProfiler::DeleteDeviceObjects()
{
	if(m_pProfilerFont)
	{
		m_pProfilerFont->DeleteDeviceObjects();
		SAFE_DELETE(m_pProfilerFont);
	}

	// 2014-12-03 by jwLee 메모리 출력 코드 추가
	SAFE_DELETE(mem);
	// end 2014-12-03 by jwLee 메모리 출력 코드 추가

	return S_OK; 
}

HRESULT CProfiler::InvalidateDeviceObjects()
{
	if(m_pProfilerFont)
		m_pProfilerFont->InvalidateDeviceObjects();

	return S_OK; 
}

void CProfiler::Render()
{
	if(!COMPARE_RACE(g_pShuttleChild->GetMyShuttleInfo().Race, RACE_OPERATION|RACE_GAMEMASTER))
		return;

	DWORD dwNowTime = timeGetTime();
	DWORD dwNowUsedTime = dwNowTime - m_dwLastTime;
	if(0 != m_dwLastTime)
	{
		m_stTotalTime.dwTotalUsedTime += dwNowUsedTime;
		m_stTotalTime.nCnt += 1;
	}
	m_dwLastTime = dwNowTime;

	if(!IsShowProfiler())
		return;
	if(m_mapUsedTime.empty())
		return;

	char buf[128] = {0, };
	wsprintf(buf, "Name");
	m_pProfilerFont->DrawText(75, 230, GUI_FONT_COLOR_W, buf);
	wsprintf(buf, "UsedTime");
	m_pProfilerFont->DrawText(220, 230, GUI_FONT_COLOR_W, buf);
	wsprintf(buf, "Average");
	m_pProfilerFont->DrawText(320, 230, GUI_FONT_COLOR_W, buf);

	int cnt = 0;
	for(map<string, PROFILER_ITEM>::iterator it = m_mapTotalUsedTime.begin() ; it != m_mapTotalUsedTime.end() ; ++it)
	{
		sprintf(buf, it->first.c_str());
		m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
		if(m_mapUsedTime.find(it->first) != m_mapUsedTime.end())
		{
			sprintf(buf, "%3.0fms(%2.2f%%)", ((float)m_mapUsedTime[it->first]), ((float)m_mapUsedTime[it->first]) / ((float)dwNowUsedTime) * 100);
			m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
		}
		sprintf(buf, "%3.2fms(%2.2f%%)", ((float)(it->second.dwTotalUsedTime)) / m_stTotalTime.nCnt,
				((float)(it->second.dwTotalUsedTime)) / ((float)(m_stTotalTime.dwTotalUsedTime)) * 100);
		m_pProfilerFont->DrawText(320, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
		++cnt;
	}
	// 2014-12-03 by jwLee 메모리 출력 코드 추가
	++cnt;

	wsprintf(buf, "memory");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	wsprintf(buf, "data");
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	++cnt;

	wsprintf(buf, "Memmory using persent");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	wsprintf(buf, "%ld%%", mem->dwMemoryLoad);
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;
	
	wsprintf(buf, "Memmory TotalPhys");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwTotalPhys / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;

	wsprintf(buf, "Memmory AvailPhys");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwAvailPhys / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;

	wsprintf(buf, "Memmory TotalPageFile");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwTotalPageFile / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;

	wsprintf(buf, "Memmory AvailPageFile");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwAvailPageFile / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;

	wsprintf(buf, "Memmory TotalVirtual");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwTotalVirtual / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;

	wsprintf(buf, "Memmory AvailVirtual");
	m_pProfilerFont->DrawText(75, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	sprintf(buf, "%-10.2fMb", (mem->dwAvailVirtual / 1024.0 / 1024.0));
	m_pProfilerFont->DrawText(220, 250 + cnt * 12, GUI_FONT_COLOR_W, buf);
	memset(buf, 0x00, sizeof(buf));
	++cnt;
	// end 2014-12-03 by jwLee 메모리 출력 코드 추가
}

void CProfiler::ShowWnd(BOOL bShow)
{
	m_bShowWnd = bShow;
}
// 2014-12-03 by jwLee 메모리 출력 코드 추가
bool CProfiler::MemoryCheck()
{	
	ZeroMemory(mem, sizeof(MEMORYSTATUS));
	mem->dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(mem);

	return true;
}
// end 2014-12-03 by jwLee 메모리 출력 코드 추가

BOOL CProfiler::Start(char *pItemName)
{
	if(IsUsing())
	{
		return FALSE;
	}

	m_pItemName = pItemName;
	m_dwStartTime = timeGetTime();

	return TRUE;
}

BOOL CProfiler::Stop(char *pItemName)
{
	if(!IsUsing())
	{
		return FALSE;
	}
	if(0 != strcmp(pItemName, m_pItemName.c_str()))
	{
		return FALSE;
	}

	DWORD dwUsedTime = timeGetTime() - m_dwStartTime;
	m_mapUsedTime[m_pItemName] = dwUsedTime;
	if(m_mapTotalUsedTime.find(m_pItemName) == m_mapTotalUsedTime.end())
	{
		PROFILER_ITEM newItem;
		newItem.dwTotalUsedTime = dwUsedTime;
		newItem.nCnt = 1;
		m_mapTotalUsedTime[m_pItemName] = newItem;
	}
	else
	{
		m_mapTotalUsedTime[m_pItemName].dwTotalUsedTime += dwUsedTime;
		m_mapTotalUsedTime[m_pItemName].nCnt += 1;
	}

	m_dwStartTime = 0;

	return TRUE;
}

BOOL CProfiler::IsUsing()
{
	if(m_dwStartTime == 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void CProfiler::Clear()
{
	m_dwStartTime = 0;
	m_pItemName = "";
	m_mapUsedTime.clear();
}