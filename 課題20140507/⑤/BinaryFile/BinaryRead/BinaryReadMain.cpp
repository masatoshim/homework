#include<iostream>
using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Diagnostics;

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

//�o�C�i���t�@�C������ǂݍ��񂾒l���l���z��ɑ��
//�l���z��̃f�[�^��\��
int main()
{
	//�l���z��̐錾
	Generic::List<Person^>^ p = gcnew Generic::List<Person^>();

	String^ fileName = "../data.bin";									//���΃p�X�Ńt�@�C�����w��
	try
	{
		FileStream^ fs = gcnew FileStream(fileName, FileMode::Open);	//�t�@�C���I�[�v��
		BinaryReader^ br = gcnew BinaryReader(fs);						//�o�C�i���f�[�^�Ƃ��ēǂݎ��
		
		while (br->BaseStream->Position < br->BaseStream->Length){		//���ׂēǂݎ��܂ŌJ��Ԃ�

			String^ pName = br->ReadString();							//���Ԃɓǂݍ��݁@(name��age��job�̏��œǂݍ���)
			int pAge = int::Parse(br->ReadString());					
			String^ pJob = br->ReadString();							

			p->Add(gcnew Person(pName, pAge, pJob));					//�l���̒ǉ�

		}

		fs->Close();													//�t�@�C�������
	}
	catch (Exception^ e)													//�G���[����
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("File '{0}' not found", fileName);
		else
			Console::WriteLine("Exception: ({0})", e);
		return -1;
	}

	//�擾�����l���̕\��
	for (int i = 0; i < p->Count; i++){
		Console::Write(p[i]->name);
		Console::Write(p[i]->age);
		Console::Write(p[i]->job);
		Console::Write("\n");
	}

	getchar(); 
	return 0;
}