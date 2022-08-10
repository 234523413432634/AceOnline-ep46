#include "AOWatchProcessMainForm.h"

using namespace AOWatchProcess;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	// 컨트롤이 만들어지기 전에 Windows XP 시각 효과를 활성화합니다.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// 주 창을 만들어 실행합니다.
	Application::Run(gcnew AOWatchProcessMainForm());
	return 0;
}