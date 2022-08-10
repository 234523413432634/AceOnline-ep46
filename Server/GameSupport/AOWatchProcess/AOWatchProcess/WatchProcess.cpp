#include "WatchProcess.h"
#include <sstream>
#include <tchar.h>
#pragma comment(lib, "shell32.lib")

#define MAX_LEN		512
#define CREATE_TERM	500

#define SAFE_DELETE(p)	{ if(p) delete (p); (p) = nullptr; }

//////////////
/// ������ ///
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
/// ������ ///
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
/// ���� ��� �߰� ///
//////////////////////
void CWatchProcess::InsertFilePath(std::string filePath)
{
	pathList->push_back(filePath);
}


/////////////////////////////////
/// �߰��� ��� ���μ��� ���� ///
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
/// ��� �������� ���μ��� ���� ///
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
/// ���μ��� ���� ///
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
/// ��� ���� ��� ���� ���μ������� ����Ǿ����� ��ȯ ///
//////////////////////////////////////////////////////////
bool CWatchProcess::IsClosedAllProcess()
{
	return closingList->empty();
}


/////////////////////////////////////////////////////////////////////
/// ���� ��� ���� ���μ��� �� ����� ���μ��� �ϳ��� Path�� ��ȯ ///
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
/// ��� ���� ��� ���� ���μ��� ���� ���� ///
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
/// �������� ���μ������� ���¸� üũ ///
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
/// ���μ����� ���� �� ������ ��ǥ�� �̵��ϵ��� �ϴ� �Լ� ///
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
/// ���μ����� ��ǥ�� �̵��� �� �� ���̵��� Z order ���� ///
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
/// WatchProcess�� �������� �ʾ����� ����� ���μ������� ����� ///
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
/// ���μ��� ����� ///
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
/// ���� ���������� ��ȯ ///
////////////////////////////
bool CWatchProcess::IsRun()
{
	return !handleList->empty();
}


//////////////////////////////////////
/// ���μ��� �ڵ� -> ���μ��� ��� ///
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
/// ���μ��� ��� -> ���μ��� �ڵ� ///
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
/// ���μ��� �ڵ� -> ������ �ڵ� ///
////////////////////////////////////
HWND CWatchProcess::GetHWndByHandle(HANDLE handle)
{
	return GetHWndByProcessId(GetProcessId(handle));
}
//////////////////////////////////
/// ���μ��� ID -> ������ �ڵ� ///
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
/// ���μ��� ��η� ���μ����� ���� ���丮 ��ȯ ///
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