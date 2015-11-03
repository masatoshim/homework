#include "MyForm.h"
#using <system.dll>
#using <system.windows.forms.dll>

using namespace PointDraw;
using namespace System;
using namespace System::Windows::Forms;


int main()
{
	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew MyForm());
	return 0;
	
}