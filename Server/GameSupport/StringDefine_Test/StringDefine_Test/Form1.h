#pragma once
#include "DefineMap.h"
#include "PrintForm.h"
#include <list>




namespace StringDefine_Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Form1에 대한 요약입니다.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			SAFE_DELETE(m_headerFile1);
			SAFE_DELETE(m_headerFile2);
			SAFE_DELETE(m_exceptionDefineFile);		// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
			SAFE_DELETE(m_errorList);


			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_file1;
	private: System::Windows::Forms::TextBox^  TextBox_file1path;
	private: System::Windows::Forms::Button^  btn_file1browse;
	private: System::Windows::Forms::Panel^  panel_file1;
	protected: 



	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel_file2;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label_file2;
	private: System::Windows::Forms::TextBox^  TextBox_file2path;
	private: System::Windows::Forms::Button^  btn_file2browse;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  btn_startBtn;
	private: System::Windows::Forms::Panel^  panel_file3;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label_file3;
	private: System::Windows::Forms::TextBox^  TextBox_file3path;
	private: System::Windows::Forms::Button^  btn_file3browse;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label_file1 = (gcnew System::Windows::Forms::Label());
			this->TextBox_file1path = (gcnew System::Windows::Forms::TextBox());
			this->btn_file1browse = (gcnew System::Windows::Forms::Button());
			this->panel_file1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel_file2 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label_file2 = (gcnew System::Windows::Forms::Label());
			this->TextBox_file2path = (gcnew System::Windows::Forms::TextBox());
			this->btn_file2browse = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->btn_startBtn = (gcnew System::Windows::Forms::Button());
			this->panel_file3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_file3 = (gcnew System::Windows::Forms::Label());
			this->TextBox_file3path = (gcnew System::Windows::Forms::TextBox());
			this->btn_file3browse = (gcnew System::Windows::Forms::Button());
			this->panel_file1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel_file2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel_file3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_file1
			// 
			this->label_file1->AutoSize = true;
			this->label_file1->Location = System::Drawing::Point(5, 8);
			this->label_file1->Name = L"label_file1";
			this->label_file1->Size = System::Drawing::Size(49, 12);
			this->label_file1->TabIndex = 99999;
			this->label_file1->Text = L"Source:";
			// 
			// TextBox_file1path
			// 
			this->TextBox_file1path->Location = System::Drawing::Point(80, 5);
			this->TextBox_file1path->Name = L"TextBox_file1path";
			this->TextBox_file1path->Size = System::Drawing::Size(400, 21);
			this->TextBox_file1path->TabIndex = 1;
			// 
			// btn_file1browse
			// 
			this->btn_file1browse->Location = System::Drawing::Point(486, 3);
			this->btn_file1browse->Name = L"btn_file1browse";
			this->btn_file1browse->Size = System::Drawing::Size(75, 23);
			this->btn_file1browse->TabIndex = 2;
			this->btn_file1browse->Text = L"Browse";
			this->btn_file1browse->UseVisualStyleBackColor = true;
			this->btn_file1browse->Click += gcnew System::EventHandler(this, &Form1::btn_file1browse_Click);
			// 
			// panel_file1
			// 
			this->panel_file1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_file1->Controls->Add(this->panel3);
			this->panel_file1->Controls->Add(this->label_file1);
			this->panel_file1->Controls->Add(this->TextBox_file1path);
			this->panel_file1->Controls->Add(this->btn_file1browse);
			this->panel_file1->Location = System::Drawing::Point(6, 12);
			this->panel_file1->Name = L"panel_file1";
			this->panel_file1->Size = System::Drawing::Size(566, 32);
			this->panel_file1->TabIndex = 100005;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->textBox3);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Location = System::Drawing::Point(3, 32);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(566, 32);
			this->panel3->TabIndex = 100006;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 12);
			this->label2->TabIndex = 99999;
			this->label2->Text = L"File1";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(52, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(421, 21);
			this->textBox3->TabIndex = 100000;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(479, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 100001;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// panel_file2
			// 
			this->panel_file2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_file2->Controls->Add(this->panel4);
			this->panel_file2->Controls->Add(this->label_file2);
			this->panel_file2->Controls->Add(this->TextBox_file2path);
			this->panel_file2->Controls->Add(this->btn_file2browse);
			this->panel_file2->Location = System::Drawing::Point(6, 55);
			this->panel_file2->Name = L"panel_file2";
			this->panel_file2->Size = System::Drawing::Size(566, 32);
			this->panel_file2->TabIndex = 100007;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Controls->Add(this->button2);
			this->panel4->Location = System::Drawing::Point(3, 32);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(566, 32);
			this->panel4->TabIndex = 100006;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 12);
			this->label1->TabIndex = 99999;
			this->label1->Text = L"File1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(52, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(421, 21);
			this->textBox2->TabIndex = 100000;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(479, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 100001;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label_file2
			// 
			this->label_file2->AutoSize = true;
			this->label_file2->Location = System::Drawing::Point(3, 8);
			this->label_file2->Name = L"label_file2";
			this->label_file2->Size = System::Drawing::Size(71, 12);
			this->label_file2->TabIndex = 99999;
			this->label_file2->Text = L"Destination:";
			// 
			// TextBox_file2path
			// 
			this->TextBox_file2path->Location = System::Drawing::Point(80, 5);
			this->TextBox_file2path->Name = L"TextBox_file2path";
			this->TextBox_file2path->Size = System::Drawing::Size(400, 21);
			this->TextBox_file2path->TabIndex = 3;
			// 
			// btn_file2browse
			// 
			this->btn_file2browse->Location = System::Drawing::Point(486, 3);
			this->btn_file2browse->Name = L"btn_file2browse";
			this->btn_file2browse->Size = System::Drawing::Size(75, 23);
			this->btn_file2browse->TabIndex = 4;
			this->btn_file2browse->Text = L"Browse";
			this->btn_file2browse->UseVisualStyleBackColor = true;
			this->btn_file2browse->Click += gcnew System::EventHandler(this, &Form1::btn_file2browse_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(6, 141);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(566, 30);
			this->progressBar1->TabIndex = 100009;
			this->progressBar1->Visible = false;
			// 
			// btn_startBtn
			// 
			this->btn_startBtn->Location = System::Drawing::Point(6, 141);
			this->btn_startBtn->Name = L"btn_startBtn";
			this->btn_startBtn->Size = System::Drawing::Size(566, 30);
			this->btn_startBtn->TabIndex = 5;
			this->btn_startBtn->Text = L"Scan";
			this->btn_startBtn->UseVisualStyleBackColor = true;
			this->btn_startBtn->Click += gcnew System::EventHandler(this, &Form1::btn_startBtn_Click);
			// 
			// panel_file3
			// 
			this->panel_file3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_file3->Controls->Add(this->panel2);
			this->panel_file3->Controls->Add(this->label_file3);
			this->panel_file3->Controls->Add(this->TextBox_file3path);
			this->panel_file3->Controls->Add(this->btn_file3browse);
			this->panel_file3->Location = System::Drawing::Point(6, 98);
			this->panel_file3->Name = L"panel_file3";
			this->panel_file3->Size = System::Drawing::Size(566, 32);
			this->panel_file3->TabIndex = 100008;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(3, 32);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(566, 32);
			this->panel2->TabIndex = 100006;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 12);
			this->label3->TabIndex = 99999;
			this->label3->Text = L"File1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(52, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(421, 21);
			this->textBox1->TabIndex = 100000;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(479, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 100001;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label_file3
			// 
			this->label_file3->AutoSize = true;
			this->label_file3->Location = System::Drawing::Point(3, 8);
			this->label_file3->Name = L"label_file3";
			this->label_file3->Size = System::Drawing::Size(65, 12);
			this->label_file3->TabIndex = 99999;
			this->label_file3->Text = L"Exception:";
			// 
			// TextBox_file3path
			// 
			this->TextBox_file3path->Location = System::Drawing::Point(80, 5);
			this->TextBox_file3path->Name = L"TextBox_file3path";
			this->TextBox_file3path->Size = System::Drawing::Size(400, 21);
			this->TextBox_file3path->TabIndex = 3;
			// 
			// btn_file3browse
			// 
			this->btn_file3browse->Location = System::Drawing::Point(486, 3);
			this->btn_file3browse->Name = L"btn_file3browse";
			this->btn_file3browse->Size = System::Drawing::Size(75, 23);
			this->btn_file3browse->TabIndex = 4;
			this->btn_file3browse->Text = L"Browse";
			this->btn_file3browse->UseVisualStyleBackColor = true;
			this->btn_file3browse->Click += gcnew System::EventHandler(this, &Form1::btn_file3browse_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 178);
			this->Controls->Add(this->panel_file3);
			this->Controls->Add(this->btn_startBtn);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->panel_file2);
			this->Controls->Add(this->panel_file1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(594, 216);
			this->MinimumSize = System::Drawing::Size(594, 216);
			this->Name = L"Form1";
			this->Text = L"StringDefine_Test Main";
			this->panel_file1->ResumeLayout(false);
			this->panel_file1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel_file2->ResumeLayout(false);
			this->panel_file2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel_file3->ResumeLayout(false);
			this->panel_file3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

	private: 
		
		/////////////////
		/// 찾기 버튼 ///
		/////////////////
		System::Void btn_file1browse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			_OpenFileBtnClicked(TextBox_file1path);
		}
		System::Void btn_file2browse_Click(System::Object^  sender, System::EventArgs^  e)
		{
			_OpenFileBtnClicked(TextBox_file2path);
		}
		System::Void btn_file3browse_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			_OpenFileBtnClicked(TextBox_file3path);
		}
		
		/////////////////////
		/// 검사하기 버튼 ///
		/////////////////////
		System::Void btn_startBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			progressBar1 -> Visible = true;
			btn_startBtn -> Visible = false;

			do
			{
				SAFE_DELETE(m_headerFile1);
				SAFE_DELETE(m_headerFile2);
				SAFE_DELETE(m_exceptionDefineFile);		// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
				SAFE_DELETE(m_errorList);

				/// define 저장 과정 ///
				m_headerFile1 = new CDefineMap(TextBox_file1path -> Text);
				if( _READ_FILE_NORMAL != _ReadFile(m_headerFile1, 1) )
				{
					break;
				}
				m_headerFile2 = new CDefineMap(TextBox_file2path -> Text);
				if( _READ_FILE_NORMAL != _ReadFile(m_headerFile2, 2) )
				{
					break;
				}
				// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
				m_exceptionDefineFile = new CDefineMap(TextBox_file3path -> Text);
				_READ_FILE_NORMAL != _ReadFile(m_exceptionDefineFile, 3);

				/// define 검사 과정 ///
				m_errorList = new std::list<ErrorListMapData>;
				int errorResult = m_headerFile1 -> GetErrorList(m_errorList, m_headerFile2);
				if(_GET_ERROR_LIST_NO_DEFINE_FILE == errorResult)
				{
					// 2013-12-11 by ymjoo 한글 출력을 모두 영어로 번역
//					MessageBox::Show("파일을 확인해주세요. 하나 이상의 파일에는 #define \"~~\"의 형식이 없습니다.");
					MessageBox::Show("Please check your files (Source, Destination) again.\nThere is no (#define \"~~\") format in one or both files.");
					break;
				}

				// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
				/// 예외 define 제거 과정 ///
				for(std::list<ErrorListMapData>::iterator iter = m_errorList -> begin() ; iter != m_errorList -> end() ;)
				{
					MAP::iterator objectIter = m_exceptionDefineFile -> FindIter(iter -> key);

					if( m_exceptionDefineFile -> FindEndIter() == objectIter )
						++iter;

					else
					{
						m_errorList -> erase(iter++);
					}
				}
				// END 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가

				/// 출력 과정 ///
				progressBar1 -> Increment(100);
				PrintForm^ pf = gcnew PrintForm;
				// 2013-12-11 by ymjoo 한글 출력을 모두 영어로 번역
//				pf -> Text = "찾음 : ";
				pf -> Text = "Found : ";
				pf -> Text += m_errorList -> size();
				pf -> SetErrorList(m_errorList);
				pf -> Show();
				pf = nullptr;
			} while(false);
			
			SAFE_DELETE(m_headerFile1);
			SAFE_DELETE(m_headerFile2);
			SAFE_DELETE(m_exceptionDefineFile);			// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가

			btn_startBtn -> Visible = true;
			progressBar1 -> Visible = false;
		}


	private:
		//////////////////////
		/// 파일 열기 버튼 ///
		//////////////////////
		void _OpenFileBtnClicked(TextBox^ textBox)
		{
			IO::Stream^ myStream;
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
			openFileDialog -> Filter = "header files (*.h)|*.h|All files (*.*)|*.*";
			openFileDialog -> RestoreDirectory = true;

			if ( openFileDialog -> ShowDialog() == System::Windows::Forms::DialogResult::OK )
			{
				if ( (myStream = openFileDialog -> OpenFile() ) != nullptr )
				{
					textBox -> Text = openFileDialog -> FileName;
					myStream -> Close();
				}
			}

			SAFE_DELETE(openFileDialog);
		}

		////////////////////////
		/// define 저장 과정 ///
		////////////////////////
		int _ReadFile(CDefineMap* file, int fileNum)
		{
			int result = file -> ReadAllFile();

			// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
			if( 3 == fileNum )
				return _READ_FILE_NORMAL;

			switch( result )
			{
			case _READ_FILE_FILE_PATH_ERROR:
				// 2013-12-11 by ymjoo 한글 출력을 모두 영어로 번역
//				MessageBox::Show("파일" + fileNum + "의 경로를 확인해주세요");
				MessageBox::Show("Please check the path : file" + fileNum);
				break;
			case _READ_FILE_UNDEFINED_ERROR:
				// 2013-12-11 by ymjoo 한글 출력을 모두 영어로 번역
//				MessageBox::Show("알 수 없는 오류 : 파일" + fileNum);
				MessageBox::Show("An unknown error occurred : file" + fileNum);
				break;
			}
			return result;
		}

	private:
		CDefineMap* m_exceptionDefineFile;			// 2014-01-28 by ymjoo 예외 처리한 내용 출력하지 않는 기능 추가
		CDefineMap* m_headerFile1;
		CDefineMap* m_headerFile2;
		std::list<ErrorListMapData>* m_errorList;
	};
}