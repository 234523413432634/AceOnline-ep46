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
	CWatchProcess^	group;				// �׷�
	Button^			startBtn;			// �׷캰 ���� ��ư
	Button^			stopBtn;			// �׷캰 ���� ��ư
	Timer^			btnResetTimer;		// Timer for Reset Start Button
	int				btnResetRemainSec;	// Remain Second for Reset Start Button
};