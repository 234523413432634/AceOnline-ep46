#include "AOWatchProcessMainForm.h"

using namespace AOWatchProcess;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	// ��Ʈ���� ��������� ���� Windows XP �ð� ȿ���� Ȱ��ȭ�մϴ�.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �� â�� ����� �����մϴ�.
	Application::Run(gcnew AOWatchProcessMainForm());
	return 0;
}