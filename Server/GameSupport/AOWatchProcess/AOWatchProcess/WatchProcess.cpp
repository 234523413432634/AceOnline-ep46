#include "WatchProcess.h"
#include <sstream>
#include <tchar.h>
#pragma comment(lib, "shell32.lib")

#define MAX_LEN		512
#define CREATE_TERM	500

#define SAFE_DELETE(p)	{ if(p) delete (p); (p) = nullptr; }

//////////////
/// 생성자 ///
//////////////
CWatchProcess::CWatchProcess(std::string newName)
{
	groupName	= new std::string(newName);
	pathList	= new std::list<std::string>;
	handleList	= new std::list<HInfo>;
	handleMap	= new std::map<std::string, HInfo>;
	openingList	= new std::list<HInfo>;
	closingList	= new std::list<HANDLE>;
}
//////////////
/// 종료자 ///
//////////////
CWatchProcess::!CWatchProcess()
{
	CloseAllProcesses();

	SAFE_DELETE(groupName);
	SAFE_DELETE(pathList);
	SAFE_DELETE(handleList);
	SAFE_DELETE(handleMap);
	SAFE_DELETE(openingList);
	SAFE_DELETE(closingList);
}


//////////////////////
/// 파일 경로 추가 ///
//////////////////////
void CWatchProcess::InsertFilePath(std::string filePath)
{
	pathList->push_back(filePath);
}


/////////////////////////////////
/// 추가된 모든 프로세스 실행 ///
/////////////////////////////////
HRESULT	CWatchProcess::LoadGroup(DWORD posX, DWORD posY, DWORD spaceX, DWORD spaceY)
{
	handleList->clear();

	int processNum = 0;
	std::list<std::string>::iterator it = pathList->begin();
	for( ; pathList->end() != it ; ++it)
	{
		std::string	processPath	= *it;
		DWORD		x			= posX + spaceX * processNum;
		DWORD		y			= posY + spaceY * processNum++;

		if(E_FAIL == StartProcess(processPath, x, y))
		{
			// At Least One Program Cannot Execute //
			return E_FAIL;
		}
		Sleep(CREATE_TERM);
	}
	return S_OK;
}


///////////////////////////////////
/// 모든 실행중인 프로세스 종료 ///
///////////////////////////////////
HRESULT CWatchProcess::CloseAllProcesses()
{
	std::list<HInfo>::iterator it = handleList->begin();
	for( ; handleList->end() != it ; )
	{
		HANDLE handle = it->handle;
		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			if(STILL_ACTIVE == exitCode)
			{
				TCHAR buf[MAX_LEN] = L"";
				wsprintf(buf, L" -pid %d", GetProcessId(handle));
				ShellExecute(NULL, L"open", L"taskkill.exe", buf, NULL, SW_HIDE);

				closingList->push_back(handle);
			}
			handleList->erase(it++);
		}
	}
	openingList->clear();
	return S_OK;
}


/////////////////////
/// 프로세스 시작 ///
/////////////////////
HRESULT CWatchProcess::StartProcess(std::string processPath, DWORD x, DWORD y)
{
	TCHAR buf[MAX_LEN] = L"";
	StdStrToTch(processPath, buf, MAX_LEN);

	TCHAR startDir[MAX_LEN] = L"";
	GetProcessDirectory(buf, startDir);

	PROCESS_INFORMATION	pi = {0};
	STARTUPINFO			si = {0};
	si.cb = sizeof(STARTUPINFO);
	if(CreateProcess(buf, NULL, NULL, NULL, TRUE, 0, NULL, startDir, &si, &pi))
	{
		HInfo process;
		process.handle		= pi.hProcess;
		process.threadId	= GetThreadId(pi.hThread);
		process.x			= x;
		process.y			= y;

		CloseHandle(pi.hThread);

		(*handleMap)[processPath] = process;
		handleList->push_back(process);
		openingList->push_back(process);
		return S_OK;
	}
	else
	{
		// Program Cannot Execute //
		handleList->clear();
		return E_FAIL;
	}
}


//////////////////////////////////////////////////////////
/// 모든 종료 명령 보낸 프로세스들이 종료되었는지 반환 ///
//////////////////////////////////////////////////////////
bool CWatchProcess::IsClosedAllProcess()
{
	return closingList->empty();
}


/////////////////////////////////////////////////////////////////////
/// 종료 명령 보낸 프로세스 중 종료된 프로세스 하나의 Path를 반환 ///
/////////////////////////////////////////////////////////////////////
std::string CWatchProcess::GetClosedProcessPath()
{
	std::list<HANDLE>::iterator it = closingList->begin();
	for( ; closingList->end() != it ; ++it)
	{
		HANDLE handle = *it;

		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			if(STILL_ACTIVE != exitCode)
			{
				closingList->erase(it);
				return GetProcessPathByHandle(handle);
			}
		}
	}
	return "";
}


//////////////////////////////////////////////
/// 모든 종료 명령 보낸 프로세스 강제 종료 ///
//////////////////////////////////////////////
HRESULT CWatchProcess::TerminateAllProcesses()
{
	std::list<HANDLE>::iterator it = closingList->begin();
	for( ; closingList->end() != it ; ++it)
	{
		HANDLE handle = *it;

		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			if(STILL_ACTIVE == exitCode)
			{
				TerminateProcess(handle, 0);
			}
		}
	}
	closingList->clear();
	return S_OK;
}


/////////////////////////////////////////
/// 실행중인 프로세스들의 상태를 체크 ///
/////////////////////////////////////////
HRESULT	CWatchProcess::CheckProcesses()
{
	std::list<HInfo>::iterator it = handleList->begin();
	for( ; handleList->end() != it ; ++it)
	{
		HANDLE handle = it->handle;

		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			if(STILL_ACTIVE != exitCode)
			{
				// At Least One Handle is Dead //
				return FWP_E_NOT_FOUND;
			}
		}
		else
		{
			// At Least One Handle is Missed //
			return E_FAIL;
		}
	}
	return S_OK;
}


/////////////////////////////////////////////////////////////
/// 프로세스가 열린 뒤 정해진 좌표로 이동하도록 하는 함수 ///
/////////////////////////////////////////////////////////////
HRESULT CWatchProcess::CheckOpeningProcessesPosition()
{
	if(openingList->empty())
	{
		return S_OK;
	}

	std::list<HInfo>::iterator it = openingList->begin();
	for( ; openingList->end() != it; )
	{
		DWORD exitCode;
		GetExitCodeProcess(it->handle, &exitCode);
		HWND hwnd = GetHWndByHandle(it->handle);
		if(STILL_ACTIVE == exitCode
			&& false == IsHungAppWindow(hwnd)
			&& GetWindowThreadProcessId(hwnd, NULL) == it->threadId)
		{
			UINT flags = SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE;
			SetWindowPos(hwnd, NULL, it->x, it->y, NULL, NULL, flags);
			openingList->erase(it++);
			SortProcessesByZOrder();
		}
		else
		{
			++it;
		}
	}
	return S_OK;
}


////////////////////////////////////////////////////////////
/// 프로세스가 좌표를 이동할 때 잘 보이도록 Z order 정렬 ///
////////////////////////////////////////////////////////////
HRESULT CWatchProcess::SortProcessesByZOrder()
{
	HWND preProcess = NULL;

	std::list<std::string>::reverse_iterator it = pathList->rbegin();
	for( ; pathList->rend() != it ; ++it)
	{
		HANDLE handle = GetHandleByProcessPath(*it);

		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			HWND hwnd = GetHWndByHandle(handle);
			if(STILL_ACTIVE == exitCode && false == IsHungAppWindow(hwnd))
			{
				UINT flags = SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE;
				if(NULL == preProcess)
				{
					flags |= SWP_NOZORDER;
				}
				SetWindowPos(hwnd, preProcess, NULL, NULL, NULL, NULL, flags);
			}
			preProcess = hwnd;
		}
	}
	return S_OK;
}


///////////////////////////////////////////////////////////////////
/// WatchProcess가 종료하지 않았지만 종료된 프로세스들을 재실행 ///
///////////////////////////////////////////////////////////////////
HRESULT CWatchProcess::RestartDeadProcesses()
{
	std::list<HInfo>::iterator it = handleList->begin();
	for( ; handleList->end() != it ; )
	{
		HANDLE handle = it->handle;

		if(handle)
		{
			DWORD exitCode;
			GetExitCodeProcess(handle, &exitCode);
			if(STILL_ACTIVE != exitCode)
			{
				RestartProcess(*(it++));
			}
			else
			{
				++it;
			}
		}
		else
		{
			// At Least One Handle is Missed //
			return E_FAIL;
		}
	}
	return S_OK;
}


///////////////////////
/// 프로세스 재실행 ///
///////////////////////
HRESULT CWatchProcess::RestartProcess(HInfo deadProcess)
{
	std::list<HInfo>::iterator it = handleList->begin();
	for( ; handleList->end() != it ; )
	{
		if(it->handle == deadProcess.handle)
		{
			handleList->erase(it++);
		}
		else
		{
			++it;
		}
	}

	std::string	processPath	= GetProcessPathByHandle(deadProcess.handle);
	DWORD		x			= deadProcess.x;
	DWORD		y			= deadProcess.y;

	if(E_FAIL == StartProcess(processPath, x, y))
	{
		return E_FAIL;
	}
	return S_OK;
}


////////////////////////////
/// 현재 실행중인지 반환 ///
////////////////////////////
bool CWatchProcess::IsRun()
{
	return !handleList->empty();
}


//////////////////////////////////////
/// 프로세스 핸들 -> 프로세스 경로 ///
//////////////////////////////////////
std::string CWatchProcess::GetProcessPathByHandle(HANDLE handle)
{
	std::map<std::string, HInfo>::iterator it = handleMap->begin();
	for( ; handleMap->end() != it ; ++it)
	{
		if(handle == it->second.handle)
		{
			return it->first;
		}
	}
	return "";
}
//////////////////////////////////////
/// 프로세스 경로 -> 프로세스 핸들 ///
//////////////////////////////////////
HANDLE CWatchProcess::GetHandleByProcessPath(std::string processPath)
{
	std::map<std::string, HInfo>::iterator it = handleMap->begin();
	for( ; handleMap->end() != it ; ++it)
	{
		if(processPath == it->first)
		{
			return it->second.handle;
		}
	}
	return nullptr;
}
////////////////////////////////////
/// 프로세스 핸들 -> 윈도우 핸들 ///
////////////////////////////////////
HWND CWatchProcess::GetHWndByHandle(HANDLE handle)
{
	return GetHWndByProcessId(GetProcessId(handle));
}
//////////////////////////////////
/// 프로세스 ID -> 윈도우 핸들 ///
//////////////////////////////////
struct CallbackData
{
	DWORD	pid;
	HWND	hwnd;
};
static bool CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
{
	if(!IsWindowVisible(hwnd))
	{
		return true;
	}

	CallbackData*	data	= (CallbackData*)lParam;
	DWORD			pid		= 0;
	GetWindowThreadProcessId(hwnd, &pid);
	if(data->pid != pid)
	{
		return true;
	}

	data->hwnd = hwnd;
	return false;
}
HWND CWatchProcess::GetHWndByProcessId(DWORD pid)
{
	if(0 == pid)
	{
		return NULL;
	}

	CallbackData data;
	data.pid	= pid;
	data.hwnd	= NULL;

	EnumWindows((WNDENUMPROC)EnumProc, (LPARAM)&data);
	return data.hwnd;
}


/////////////////////////////////////////////////////
/// 프로세스 경로로 프로세스가 속한 디렉토리 반환 ///
/////////////////////////////////////////////////////
void CWatchProcess::GetProcessDirectory(TCHAR* processPath, TCHAR* processDir)
{
	for(int i = 0 ; processPath[i] ; i++)
	{
		if('\\' == processPath[i])
		{
			_tcsncpy_s(processDir, MAX_LEN, processPath, i);
		}
	}
}


////////////////////////////
/// std::string -> TCHAR ///
////////////////////////////
void CWatchProcess::StdStrToTch(std::string stdStr, TCHAR* lpStr, int len)
{
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, stdStr.c_str(), stdStr.length(), lpStr, len);
}