#pragma once
#include "WatchProcess.h"

using namespace System::Windows::Forms;

public ref class GroupObject
{
public:
	GroupObject()
	{
		GroupObject("");
	}
	GroupObject(std::string groupName)
	{
		group				= gcnew CWatchProcess(groupName);
		startBtn			= gcnew Button;
		stopBtn				= gcnew Button;
		btnResetTimer		= gcnew Timer;
		btnResetRemainSec	= 0;
	}

public:
	CWatchProcess^	group;				// 그룹
	Button^			startBtn;			// 그룹별 시작 버튼
	Button^			stopBtn;			// 그룹별 종료 버튼
	Timer^			btnResetTimer;		// Timer for Reset Start Button
	int				btnResetRemainSec;	// Remain Second for Reset Start Button
};