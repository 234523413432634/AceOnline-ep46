#pragma once
#include <Windows.h>
#include <list>
#include <map>

struct HInfo
{
	HANDLE	handle;
	DWORD	threadId;
	DWORD	x;
	DWORD	y;
};

public ref class CWatchProcess
{
public:
	CWatchProcess()		{ CWatchProcess(""); }
	~CWatchProcess()	{ this->!CWatchProcess(); }
public:
	CWatchProcess(std::string newName);
protected:
	!CWatchProcess();


public:
	void		SetGroupName(std::string newName)	{ *groupName = newName; }

	void		InsertFilePath(std::string filePath);

	HRESULT		LoadGroup(DWORD posX, DWORD posY, DWORD spaceX, DWORD spaceY);
	HRESULT		CloseAllProcesses();

	HRESULT		StartProcess(std::string processPath, DWORD x, DWORD y);

	bool		IsClosedAllProcess();
	std::string	GetClosedProcessPath();
	HRESULT		TerminateAllProcesses();
	HRESULT		CheckProcesses();

	HRESULT		CheckOpeningProcessesPosition();
	HRESULT		SortProcessesByZOrder();

	HRESULT		RestartDeadProcesses();
	HRESULT		RestartProcess(HInfo deadProcess);

	bool		IsRun();

	std::string	GetGroupName()	{ return *groupName; }

private:
	std::string	GetProcessPathByHandle(HANDLE handle);
	HANDLE		GetHandleByProcessPath(std::string processPath);
	HWND		GetHWndByHandle(HANDLE handle);
	HWND		GetHWndByProcessId(DWORD pid);

	void		GetProcessDirectory(TCHAR* processPath, TCHAR* processDir);

	void		StdStrToTch(std::string stdStr, TCHAR* lpStr, int len);


private:
	std::string*					groupName;
	std::list<std::string>*			pathList;
	std::list<HInfo>*				handleList;
	std::map<std::string, HInfo>*	handleMap;
	std::list<HInfo>*				openingList;
	std::list<HANDLE>*				closingList;
};