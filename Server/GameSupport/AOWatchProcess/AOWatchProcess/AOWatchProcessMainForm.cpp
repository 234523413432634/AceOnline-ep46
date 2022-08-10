#include "MainFormDefine.h"
#include "AOWatchProcessMainForm.h"
#include <tchar.h>
#include <msclr/marshal_cppstd.h>
#pragma comment(lib, "user32.lib")

using namespace AOWatchProcess;
using namespace System::Drawing;
using namespace System::IO;
using namespace msclr::interop;

#define _GroupObject_(obj)	safe_cast<GroupObject^>(obj)
#define _Timer_(obj)		safe_cast<Timer^>(obj)
#define _Button_(obj)		safe_cast<Button^>(obj)

/////////////////////////
/// 생성자로부터 호출 ///
/// 멤버 초기화       ///
/////////////////////////
void AOWatchProcessMainForm::InitializeMember()
{
	groupObjectArr					= gcnew ArrayList;
	groupCnt						= 0;
	readStep						= ReadStep_GroupName;
	messageBoxCnt					= 0;
	
	checkGroupTimer					= gcnew Timer();
	checkGroupTimer->Interval		= CHECK_GROUP_INTERVAL;
	checkGroupTimer->Tick			+= gcnew EventHandler(this, &AOWatchProcessMainForm::TimerTick);
	
	checkGroupCheckBox				= gcnew CheckBox();
	checkGroupCheckBox->TabStop		= false;
	checkGroupCheckBox->Location	= Point(FORM_MARGIN_LEFT, CHECKBOX_MARGIN_TOP);
	checkGroupCheckBox->Text		= STR_CHECKBOX_TEXT;
	checkGroupCheckBox->AutoSize	= true;
	checkGroupCheckBox->Checked		= true;
	this->Controls->Add(checkGroupCheckBox);

	logStr							= new std::ostringstream("\n");
}


//////////////////////////////////////////
/// 프로그램 시작시 실행되는 함수.     ///
/// config 파일을 읽어오는 함수를 호출 ///
//////////////////////////////////////////
Void AOWatchProcessMainForm::MainFormLoad(Object^ sender, EventArgs^ e)
{
	if(E_FAIL == ReadConfigFile())
	{
		EnterMessage();
		MessageBox::Show(STR_MSG_ERR_0001);
		LeaveMessage();
		Close();
	}
	FormResize((FORM_MARGIN_LEFT + FORM_MARGIN_RIGHT - STOPBTN_SPACE_WIDTH) + GROUP_BTN_SET_WIDTH * (min(groupCnt - 1, BTN_LINE_MAX_NUM - 1) + 1),
				(FORM_MARGIN_TOP + FORM_MARGIN_BOTTOM - BTN_SPACE_HEIGHT) + GROUP_BTN_SET_HEIGHT * ((groupCnt - 1) / BTN_LINE_MAX_NUM + 1));
}
////////////////////////////////////////
/// 프로그램 종료시 실행되는 함수.   ///
/// 실행중인 그룹이 있으면 종료 캔슬 ///
////////////////////////////////////////
Void AOWatchProcessMainForm::MainFormClosing(Object^ sender, FormClosingEventArgs^ e)
{
	if(IsRun())
	{
		EnterMessage();
		MessageBox::Show(STR_MSG_CLOSING_CANCEL);
		LeaveMessage();
		e->Cancel = true;
	}
	else
	{
		SaveLogFile();
	}
}


///////////////////////////////
/// config 파일을 읽어온다. ///
///////////////////////////////
HRESULT AOWatchProcessMainForm::ReadConfigFile()
{
	if(!File::Exists(CONFIG_FILE_NAME))
	{
		return E_FAIL;
	}

	StreamReader^ sr = gcnew StreamReader(CONFIG_FILE_NAME, System::Text::Encoding::Default);
	try
	{
		while(sr->Peek() >= 0)
		{
			if(E_FAIL == ReadLineConfigFile(sr->ReadLine()))
			{
				return E_FAIL;
			}
		}
	}
	catch(Exception^)
	{
		return E_FAIL;
	}
	finally
	{
		if(sr)
		{
			delete sr;
		}
	}
	return S_OK;
}
///////////////////////////////
/// config 파일을 읽어온다. ///
///////////////////////////////
HRESULT AOWatchProcessMainForm::ReadLineConfigFile(String^ lineStr)
{
	std::string buf = SysStrToStdStr(lineStr);

	if("" == buf)
	{
		readStep = ReadStep_GroupName;
	}
	else if(ReadStep_GroupName == readStep)
	{
		/// 그룹 이름               ///
		/// 그룹과 버튼이 생성된다. ///
		AddNewGroup(buf);
		readStep = ReadStep_Process;
	}
	else
	{
		/// 그룹의 프로그램 Path 목록 ///
		GetGroupObject(groupCnt-1)->group->InsertFilePath(buf);
	}
	return S_OK;
}


//////////////////////////
/// log 파일을 남긴다. ///
//////////////////////////
void AOWatchProcessMainForm::SaveLogFile()
{
	if(logStr->str() == "\n")
	{
		return;
	}
	
	StreamWriter^ sw = gcnew StreamWriter(LOG_FILE_NAME, true);

	sw->WriteLine("");

	std::string log = logStr->str();
	std::string logLineStr = "";

	for(int i = 0 ; log.c_str()[i] ; i++)
	{
		if('\n' == log.c_str()[i])
		{
			String^ buf = gcnew String(logLineStr.c_str());
			sw->WriteLine(buf);
			logLineStr = "";
		}
		else
		{
			logLineStr += log.c_str()[i];
		}
	}

	if("" != logLineStr)
	{
		String^ buf = gcnew String(logLineStr.c_str());
		sw->WriteLine(buf);
	}
	sw->Close();
	logStr->str("\n");
}


///////////////////////////
/// 새 그룹을 추가한다. ///
///////////////////////////
void AOWatchProcessMainForm::AddNewGroup(std::string groupName)
{
	GroupObject^ newGroupObject = gcnew GroupObject(groupName);
	newGroupObject->btnResetRemainSec = BTN_RESET_INTERVAL;
	groupObjectArr->Add(newGroupObject);

	Button^	newStartBtn		= newGroupObject->startBtn;
	Button^	newStopBtn		= newGroupObject->stopBtn;

	Point	newBtnPos		= Point(FORM_MARGIN_LEFT + GROUP_BTN_SET_WIDTH * (groupCnt % BTN_LINE_MAX_NUM),
									FORM_MARGIN_TOP + GROUP_BTN_SET_HEIGHT * (groupCnt / BTN_LINE_MAX_NUM));
	newStartBtn->Location	= Point(newBtnPos.X, newBtnPos.Y);
	newStopBtn->Location	= Point(newBtnPos.X + STARTBTN_WIDTH + STARTBTN_SPACE_WIDTH, newBtnPos.Y);
	newStartBtn->Size		= Drawing::Size(STARTBTN_WIDTH, BTN_HEIGHT);
	newStopBtn->Size		= Drawing::Size(STOPBTN_WIDTH, BTN_HEIGHT);
	newStartBtn->TabIndex	= groupCnt;
	newStopBtn->TabIndex	= groupCnt;
	newStartBtn->Text		= gcnew String(newGroupObject->group->GetGroupName().c_str());
	newStopBtn->Text		= STR_CBTN_TEXT;
	newStartBtn->Enabled	= true;
	newStopBtn->Enabled		= false;
	newStartBtn->Click		+= gcnew EventHandler(this, &AOWatchProcessMainForm::GroupStartBtnClick);
	newStopBtn->Click		+= gcnew EventHandler(this, &AOWatchProcessMainForm::GroupStopBtnClick);
	this->Controls->Add(newStartBtn);
	this->Controls->Add(newStopBtn);

	Timer^ newBtnResetTimer	= newGroupObject->btnResetTimer;
	newBtnResetTimer->Interval	= 1000 + groupCnt;
	newBtnResetTimer->Tick		+= gcnew EventHandler(this, &AOWatchProcessMainForm::TimerTick_BtnReset);

	++groupCnt;
}
////////////////////
/// 폼 크기 변경 ///
////////////////////
void AOWatchProcessMainForm::FormResize(int width, int height)
{
	this->MaximumSize	= Drawing::Size(0, 0);
	this->MinimumSize	= Drawing::Size(0, 0);
	this->ClientSize	= Drawing::Size(width, height);
	this->MaximumSize	= this->Size;
	this->MinimumSize	= this->Size;

	this->Location		= Point(GetSystemMetrics(SM_CXSCREEN) / 2 - this->Width / 2,
								GetSystemMetrics(SM_CYSCREEN) / 2 - this->Height / 2);
}


///////////////////////////////////
/// 버튼을 누르면 호출되는 함수 ///
///////////////////////////////////
void AOWatchProcessMainForm::GroupStartBtnClick(Object^ sender, EventArgs^ e)
{
	int				groupNum	= _Button_(sender)->TabIndex;
	GroupObject^	groupObject	= GetGroupObject(groupNum);
	
	std::string btnText = SysStrToStdStr(groupObject->startBtn->Text) + STR_BTN_RUNNING_TEXT;
	groupObject->startBtn->Text		= gcnew String(btnText.c_str());
	groupObject->startBtn->Enabled	= false;
	groupObject->stopBtn->Enabled	= true;
	
	StartGroup(groupNum);
	checkGroupTimer->Start();
}
void AOWatchProcessMainForm::GroupStopBtnClick(Object^ sender, EventArgs^ e)
{
	int				groupNum	= _Button_(sender)->TabIndex;
	GroupObject^	groupObject	= GetGroupObject(groupNum);
	String^			groupName	= gcnew String(groupObject->group->GetGroupName().c_str());

	EnterMessage();
	if(MessageBox::Show(STR_MSG_STOPBTN_YESNO, groupName, MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		std::ostringstream buf;
		buf << groupObject->group->GetGroupName() << "\n" << groupObject->btnResetRemainSec;
		groupObject->startBtn->Text		= gcnew String(buf.str().c_str());
		groupObject->stopBtn->Enabled	= false;
		
		StopGroup(groupNum);
		CheckClosedProcesses(groupNum);
		groupObject->btnResetTimer->Start();
	}
	LeaveMessage();
}


/////////////////
/// 실행한다. ///
/////////////////
void AOWatchProcessMainForm::StartGroup(int groupNum)
{
	CWatchProcess^ group = GetGroupObject(groupNum)->group;

	if(group->IsRun())
	{
		group->CloseAllProcesses();
	}
	group->LoadGroup(GROUP_POS_X + GROUP_SPACE_WIDTH * (groupNum % GROUP_LINE_MAX_NUM),
					GROUP_POS_Y + GROUP_SPACE_HEIGHT * (groupNum / GROUP_LINE_MAX_NUM),
					GROUP_PROCESS_SPACE_WIDTH,
					GROUP_PROCESS_SPACE_HEIGHT);
}
/////////////////
/// 정지한다. ///
/////////////////
void AOWatchProcessMainForm::StopGroup(int groupNum)
{
	GetGroupObject(groupNum)->group->CloseAllProcesses();
}


//////////////////////////////////////////////////
/// 일정 시간마다 호출되는 함수                ///
/// 열려있는 프로세스들을 주기적으로 체크한다. ///
//////////////////////////////////////////////////
void AOWatchProcessMainForm::TimerTick(Object^ sender, EventArgs^ e)
{
	if(MessageBoxShown())
	{
		return;
	}

	checkGroupTimer->Stop();
	
	bool isAnyGroupRun = false;

	for(int i = 0 ; i < groupCnt ; ++i)
	{
		CWatchProcess^ group = GetGroupObject(i)->group;
		if(group->IsRun())
		{
			isAnyGroupRun = true;

			group->CheckOpeningProcessesPosition();

			if(false == checkGroupCheckBox->Checked::get())
			{
				continue;
			}

			switch(group->CheckProcesses())
			{
			case S_OK:
				break;
				
			case FWP_E_NOT_FOUND:
				if(E_FAIL == group->RestartDeadProcesses())
				{
					StartGroup(i);
				}
				break;

			case E_FAIL:
				StartGroup(i);
				break;

			default:
				StartGroup(i);
				break;
			}
		}
	}

	if(isAnyGroupRun)
	{
		checkGroupTimer->Start();
	}
}
/////////////////////////////////////////////////////////////////
/// 종료 버튼을 누른 뒤 실행 버튼을 활성화 할 때까지의 타이머 ///
/////////////////////////////////////////////////////////////////
void AOWatchProcessMainForm::TimerTick_BtnReset(Object^ sender, EventArgs^ e)
{
	int				groupNum	= _Timer_(sender)->Interval - 1000;
	GroupObject^	groupObject	= GetGroupObject(groupNum);
	
	groupObject->btnResetTimer->Stop();
	if(0 == --groupObject->btnResetRemainSec || CheckClosedProcesses(groupNum))
	{
		AllProcessesClosed(groupNum);
	}
	else
	{
		std::ostringstream	buf;
		buf << groupObject->group->GetGroupName() << "\n" << groupObject->btnResetRemainSec;
		groupObject->startBtn->Text = gcnew String(buf.str().c_str());
		groupObject->btnResetTimer->Start();
	}
}


//////////////////////////////////////////
/// 하나 이상의 그룹이 실행중인지 반환 ///
//////////////////////////////////////////
bool AOWatchProcessMainForm::IsRun()
{
	for(int i = 0 ; i < groupCnt ; ++i)
	{
		Button^ groupStartBtn = GetGroupObject(i)->startBtn;
		if(false == groupStartBtn->Enabled)
		{
			return true;
		}
	}
	return false;
}
/////////////////////////////////////////////////////////
/// 종료한 그룹의 프로세스들이 모두 종료되었는지 검사 ///
/// 종료된 프로세스가 있다면 로그 추가                ///
/////////////////////////////////////////////////////////
bool AOWatchProcessMainForm::CheckClosedProcesses(int groupNum)
{
	GroupObject^ groupObject = GetGroupObject(groupNum);

	std::string closedProcessPath;
	while("" != (closedProcessPath = groupObject->group->GetClosedProcessPath()))
	{
		*logStr << GetNowTimeString() << "[" << groupObject->group->GetGroupName() << "] "
				<< STR_LOG_PROC_CLOSED_001 << closedProcessPath << STR_LOG_PROC_CLOSED_002
				<< BTN_RESET_INTERVAL - groupObject->btnResetRemainSec << STR_LOG_PROC_CLOSED_003 << '\n';
	}
	return groupObject->group->IsClosedAllProcess();
}
/////////////////////////////////////////////
/// 모든 프로세스가 종료되고 나서         ///
/// 그룹 실행 버튼 활성화, 로그 파일 저장 ///
/////////////////////////////////////////////
void AOWatchProcessMainForm::AllProcessesClosed(int groupNum)
{
	GroupObject^ groupObject = GetGroupObject(groupNum);

	TerminateAllProcesses(groupNum);

	groupObject->btnResetTimer->Stop();
	groupObject->startBtn->Enabled	= true;
	groupObject->startBtn->Text		= gcnew String(groupObject->group->GetGroupName().c_str());
	groupObject->btnResetRemainSec	= BTN_RESET_INTERVAL;

	SaveLogFile();
}
/////////////////////////////////
/// 모든 프로세스를 강제 종료 ///
/////////////////////////////////
void AOWatchProcessMainForm::TerminateAllProcesses(int groupNum)
{
	CWatchProcess^ group = GetGroupObject(groupNum)->group;

	if(false == group->IsClosedAllProcess())
	{
		group->TerminateAllProcesses();
		*logStr << GetNowTimeString() << "[" << group->GetGroupName() << "] "
				<< STR_LOG_TIME_OUT << '\n';
	}
}


///////////////////////////////////
/// Group Number -> GroupObject ///
///////////////////////////////////
GroupObject^ AOWatchProcessMainForm::GetGroupObject(int groupNum)
{
	return _GroupObject_(groupObjectArr[groupNum]);
}


/////////////////////////////////
/// 현재 시간을 문자열로 반환 ///
/// log 작성용 함수           ///
/////////////////////////////////
std::string AOWatchProcessMainForm::GetNowTimeString()
{
	TCHAR dateStr[MAX_LEN] = L"";
	TCHAR timeStr[MAX_LEN] = L"";
	GetDateFormat(LOCALE_INVARIANT, NULL, NULL, NULL, dateStr, MAX_LEN);
	GetTimeFormat(LOCALE_INVARIANT, NULL, NULL, NULL, timeStr, MAX_LEN);
	return "[" + TchToStdStr(dateStr) + " " + TchToStdStr(timeStr) + "] ";
}


/////////////////////////////////////
/// System::String -> std::string ///
/////////////////////////////////////
std::string AOWatchProcessMainForm::SysStrToStdStr(String^ sysStr)
{
	marshal_context	context;
	return context.marshal_as<std::string>(sysStr);
}
////////////////////////////
/// TCHAR -> std::string ///
////////////////////////////
std::string AOWatchProcessMainForm::TchToStdStr(TCHAR* lpStr)
{
	int		strSize	= sizeof(TCHAR) * _tcslen(lpStr) + 1;
	char*	pszStr	= new char[strSize];
	wcstombs(pszStr, lpStr, strSize);
	std::string str = pszStr;
	delete[] pszStr;
	return str;
}