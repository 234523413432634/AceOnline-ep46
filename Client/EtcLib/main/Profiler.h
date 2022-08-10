// Profiler.h: interface for the CProfiler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROFILER_H__1703B581_AC47_4887_A3AB_F46E02B9A5A7__INCLUDED_)
#define AFX_PROFILER_H__1703B581_AC47_4887_A3AB_F46E02B9A5A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windows.h"

#define MAX_LENGTH_PROFILER 128

#ifdef C_PROFILER_YMJOO
#define START_PROFILER(str)	{ if(g_pD3dApp->m_pProfiler) g_pD3dApp->m_pProfiler->Start(str); }
#define STOP_PROFILER(str)	{ if(g_pD3dApp->m_pProfiler) g_pD3dApp->m_pProfiler->Stop(str); }
#else
#define START_PROFILER(str)	{ }
#define STOP_PROFILER(str)	{ }
#endif

class CD3DHanFont;

struct PROFILER_ITEM
{
	DWORD dwTotalUsedTime;
	int nCnt;
};

class CProfiler
{
public:
	CProfiler();
	virtual ~CProfiler();

	virtual HRESULT InitDeviceObjects();
	virtual HRESULT RestoreDeviceObjects();
	virtual HRESULT DeleteDeviceObjects();
	virtual HRESULT InvalidateDeviceObjects();

	void	Render();
	void	ShowWnd(BOOL bShow);
	BOOL	IsShowProfiler() { return m_bShowWnd; }

	bool	MemoryCheck(); // 2014-12-03 by jwLee 메모리 출력 코드 추가

	BOOL	Start(char *pItemName);
	BOOL	Stop(char *pItemName);
	BOOL	IsUsing();
	void	Clear();
	
private:
	BOOL						m_bShowWnd;
	DWORD						m_dwLastTime;
	PROFILER_ITEM				m_stTotalTime;
	DWORD						m_dwStartTime;
	string						m_pItemName;
	map<string, DWORD>			m_mapUsedTime;
	map<string, PROFILER_ITEM>	m_mapTotalUsedTime;
	MEMORYSTATUS*				mem;					// 2014-12-03 by jwLee 메모리 출력 코드 추가
	CD3DHanFont*				m_pProfilerFont;
};

#endif // !defined(AFX_PROFILER_H__1703B581_AC47_4887_A3AB_F46E02B9A5A7__INCLUDED_)
