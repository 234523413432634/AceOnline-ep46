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

		/// ��� ���� ��� ���ҽ��� �����մϴ�. ///
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
		
		/// �ʼ� �����̳� �����Դϴ�. ///
		private: System::ComponentModel::Container ^components;

///////////////////////////////////////////////////////////
/// �����̳� ������ �ʿ��� �޼����Դϴ�.                ///
/// �� �޼����� ������ �ڵ� ������� �������� ���ʽÿ�. ///
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
/// END �����̳� ������ �ʿ��� �޼����Դϴ�. ///
////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// 2014-02-12 by ymjoo ���α׷��� �ֿ� �ڵ� �κ��Դϴ�. ///
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
	/// ��� ���� ��� ///
	//////////////////////
	private:
		ArrayList^			groupObjectArr;		// �׷�
		int					groupCnt;			// �׷� ����
		ReadStep			readStep;			// Flag for ReadLine
		int					messageBoxCnt;		// �޼��� �ڽ� üũ��
		Timer^				checkGroupTimer;	// Timer for Check Groups
		CheckBox^			checkGroupCheckBox;	// CheckBox for Tick
		std::ostringstream*	logStr;				// Log String
#pragma endregion
////////////////////////////////////////////////////////////////
/// END 2014-02-12 by ymjoo ���α׷��� �ֿ� �ڵ� �κ��Դϴ�. ///
////////////////////////////////////////////////////////////////
	};
}