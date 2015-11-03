#include<iostream>
using namespace System;
using namespace System::IO;


//�l���̍\����
ref struct Person
{
	String^ name;
	int age;
	String^ job;

	Person(String^ n, int a, String^ j)
	{
		name = n;
		age = a;
		job = j;
	}
};

//�l���z��̏����o�C�i�����[�h�Ńt�@�C���ɏ�������
int main()
{
	//�l���̏�����
	array<Person^>^ p = gcnew array<Person^>{
			gcnew Person("john", 21, "aaaaa"),
			gcnew Person("david", 22, "bbbbb"),
			gcnew Person("leon", 23, "ccccc"),
			gcnew Person("elam", 24, "ddddd")
	};
	
	String^ fileName = "../data.bin";								//���΃p�X�Ńt�@�C�����w��
	FileStream^ fs = gcnew FileStream(fileName, FileMode::Create);	//�t�@�C����V�K�쐬
	BinaryWriter^ w = gcnew BinaryWriter(fs);						//�o�C�i�����[�h�ŏ�������

	try{
		for (int i = 0; i < p->Length; i++){						//�l�����J��Ԃ�
			w->Write(p[i]->name);
			w->Write((p[i]->age).ToString());
			w->Write(p[i]->job);
		}
	}
	catch (Exception^){												//�G���[����
		Console::WriteLine("ERROR!!");
		fs->Close();
		return -1;
	}

	fs->Close();	//�t�@�C�������

	return 0;
}