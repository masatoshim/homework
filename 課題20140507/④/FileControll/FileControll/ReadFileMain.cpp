#include<iostream>
using namespace System;
using namespace System::IO;

int main()
{
	String^ fileName = "../sample.txt";					//���΃p�X�Ńt�@�C�����w��

	try{
		StreamReader^ din = File::OpenText(fileName);	//�t�@�C���I�[�v��

		Console::WriteLine(din->ReadLine());			//1�s�ǂݍ���ŕ\��

		din->Close();									//�t�@�C�������
	}
	catch (Exception^ e){								//�G���[����
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