#include "MyForm.h"
#using <system.dll>
#using <system.windows.forms.dll>

using namespace PointDraw;
using namespace System;
using namespace System::Windows::Forms;


int main()
{
	// ���C�� �E�B���h�E���쐬���āA���s���܂�
	Application::Run(gcnew MyForm());
	return 0;
	
}