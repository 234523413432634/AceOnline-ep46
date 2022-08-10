#pragma once
#include "GroupObject.h"
#include <sstream>

namespace AOWatchProcess
{
	using namespace System;
	using namespace System::Collections;
	
	public enum ReadStep
	{
		ReadStep_GroupName,
		ReadStep_Process,
	};

	public ref class AOWatchProcessMainForm : public System::Windows::Forms::Form
	{
		public: AOWatchProcessMainForm(void)
		{
			InitializeComponent();
			InitializeMember();
		}

		/// 사용 중인 모든 리소스를 정리합니다. ///
		protected: ~AOWatchProcessMainForm()
		{
			if(components)
			{
				delete components;
			}
			if(logStr)
			{
				delete logStr;
			}
		}
		
		/// 필수 디자이너 변수입니다. ///
		private: System::ComponentModel::Container ^components;

///////////////////////////////////////////////////////////
/// 디자이너 지원에 필요한 메서드입니다.                ///
/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오. ///
///////////////////////////////////////////////////////////
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(AOWatchProcessMainForm::typeid);
			this->SuspendLayout();
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"AOWatchProcessMainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AOWatchProcessMain";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AOWatchProcessMainForm::MainFormClosing);
			this->Load += gcnew System::EventHandler(this, &AOWatchProcessMainForm::MainFormLoad);
			this->ResumeLayout(false);
		}
#pragma endregion
////////////////////////////////////////////////
/// END 디자이너 지원에 필요한 메서드입니다. ///
////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// 2014-02-12 by ymjoo 프로그램의 주요 코드 부분입니다. ///
////////////////////////////////////////////////////////////
#pragma region AO Watch Process Main Form Code
	private:
		void			InitializeMember();

		Void			MainFormLoad(Object^ sender, EventArgs^ e);
		Void			MainFormClosing(Object^ sender, FormClosingEventArgs^ e);

		HRESULT			ReadConfigFile();
		HRESULT			ReadLineConfigFile(String^ lineStr);

		void			SaveLogFile();

		void			AddNewGroup(std::string groupName);
		void			FormResize(int width, int height);

		void			GroupStartBtnClick(Object^ sender, EventArgs^ e);
		void			GroupStopBtnClick(Object^ sender, EventArgs^ e);

		void			StartGroup(int groupNum);
		void			StopGroup(int groupNum);

		void			TimerTick(Object^ sender, EventArgs^ e);
		void			TimerTick_BtnReset(Object^ sender, EventArgs^ e);

		bool			IsRun();
		bool			CheckClosedProcesses(int groupNum);
		void			AllProcessesClosed(int groupNum);
		void			TerminateAllProcesses(int groupNum);

		GroupObject^	GetGroupObject(int groupNum);
		
		std::string		GetNowTimeString();

		std::string		SysStrToStdStr(String^ sysStr);
		std::string		TchToStdStr(TCHAR* lpStr);

		void			EnterMessage()		{ ++messageBoxCnt; }
		void			LeaveMessage()		{ --messageBoxCnt; }
		bool			MessageBoxShown()	{ return (0 < messageBoxCnt); }

	//////////////////////
	/// 멤버 변수 목록 ///
	//////////////////////
	private:
		ArrayList^			groupObjectArr;		// 그룹
		int					groupCnt;			// 그룹 개수
		ReadStep			readStep;			// Flag for ReadLine
		int					messageBoxCnt;		// 메세지 박스 체크용
		Timer^				checkGroupTimer;	// Timer for Check Groups
		CheckBox^			checkGroupCheckBox;	// CheckBox for Tick
		std::ostringstream*	logStr;				// Log String
#pragma endregion
////////////////////////////////////////////////////////////////
/// END 2014-02-12 by ymjoo 프로그램의 주요 코드 부분입니다. ///
////////////////////////////////////////////////////////////////
	};
}