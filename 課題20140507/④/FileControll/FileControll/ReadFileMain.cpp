#include<iostream>
using namespace System;
using namespace System::IO;

int main()
{
	String^ fileName = "../sample.txt";					//相対パスでファイルを指定

	try{
		StreamReader^ din = File::OpenText(fileName);	//ファイルオープン

		Console::WriteLine(din->ReadLine());			//1行読み込んで表示

		din->Close();									//ファイルを閉じる
	}
	catch (Exception^ e){								//エラー処理
		if (dynamic_cast<FileNotFoundException^>(e)){	
			Console::WriteLine("File not found!!");
		}
		else{											
			Console::WriteLine("ERROR!!");
		}
	}

	getchar();
	return 0;
}