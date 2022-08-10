#pragma once
#include "DefineMap.h"

namespace StringDefine_Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// PrintForm에 대한 요약입니다.
	/// </summary>
	public ref class PrintForm : public System::Windows::Forms::Form
	{
	public:
		PrintForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~PrintForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  identifier;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  file1str;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  file2str;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  file1format;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  file2format;





	protected: 






	protected: 



	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다.
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PrintForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->identifier = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->file1str = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->file2str = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->file1format = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->file2format = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->identifier, 
				this->file1str, this->file2str, this->file1format, this->file2format});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(1264, 602);
			this->dataGridView1->TabIndex = 3;
			// 
			// identifier
			// 
			this->identifier->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->identifier->HeaderText = L"identifier";
			this->identifier->Name = L"identifier";
			this->identifier->ReadOnly = true;
			this->identifier->Width = 77;
			// 
			// file1str
			// 
			this->file1str->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->file1str->HeaderText = L"File1";
			this->file1str->Name = L"file1str";
			this->file1str->ReadOnly = true;
			this->file1str->Width = 56;
			// 
			// file2str
			// 
			this->file2str->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->file2str->HeaderText = L"File2";
			this->file2str->Name = L"file2str";
			this->file2str->ReadOnly = true;
			this->file2str->Width = 56;
			// 
			// file1format
			// 
			this->file1format->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->file1format->HeaderText = L"File1 format";
			this->file1format->Name = L"file1format";
			this->file1format->ReadOnly = true;
			this->file1format->Width = 95;
			// 
			// file2format
			// 
			this->file2format->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->file2format->HeaderText = L"File2 format";
			this->file2format->Name = L"file2format";
			this->file2format->ReadOnly = true;
			this->file2format->Width = 95;
			// 
			// PrintForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 602);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"PrintForm";
			this->Text = L"PrintForm";
			this->Shown += gcnew System::EventHandler(this, &PrintForm::PrintForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		void SetErrorList(std::list<ErrorListMapData>* errorList) { m_errorList = errorList; };

	private: 
		System::Void PrintForm_Shown(System::Object^  sender, System::EventArgs^  e) 
		{
			for(std::list<ErrorListMapData>::iterator iter = m_errorList -> begin() ; iter != m_errorList -> end() ; ++iter)
			{
				System::String^ data1 = gcnew String(iter -> key.c_str());
				System::String^ data2 = gcnew String(iter -> file1AllString.c_str());
				System::String^ data3 = gcnew String(iter -> file2AllString.c_str());
				System::String^ data4 = gcnew String(iter -> file1KeyString.c_str());
				System::String^ data5 = gcnew String(iter -> file2KeyString.c_str());
				
				dataGridView1 -> Rows -> Add(data1, data2, data3, data4, data5);
				
				SAFE_DELETE(data1);
				SAFE_DELETE(data2);
				SAFE_DELETE(data3);
				SAFE_DELETE(data4);
				SAFE_DELETE(data5);
			}
		}


	private:
		std::list<ErrorListMapData>* m_errorList;
	};
}
