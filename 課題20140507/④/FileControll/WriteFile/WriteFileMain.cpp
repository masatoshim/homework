#include<iostream>
#using <mscorlib.dll>
using namespace System;
using namespace System::IO;

//�l���N���X
public ref class Person{
	String^ name;
	int age;
	String^ job;
public:
	Person(){}
	//�R���X�g���N�^�Œl��ݒ�
	Person(String^ n, int a, String^ j)
	{
		name = n;
		age = a;
		job = j;
	}
	//�Q�b�^�[���\�b�h
	String^ get_name(){ return name; }
	int get_age(){ return age; }
	String^ get_job(){ return job; }
};

int main(){
	//�l���z��̏����ݒ�
	array<Person^>^ p = gcnew array<Person^>{
				gcnew Person("john", 21, "aaaaa"),
				gcnew Person("david", 22, "bbbbb"),
				gcnew Person("leon", 23, "ccccc"),
				gcnew Person("elam", 24, "ddddd")
	};

	String^ fileName = "../sample.txt";					//���΃p�X�Ńt�@�C�����w��
	StreamWriter^ sw = gcnew StreamWriter(fileName);	//�������ݏ���

	for (int i = 0; i < p->Length; i++){				//�l�����J��Ԃ�
		sw->Write(p[i]->get_name());					//���O�̏�������
		sw->Write(',');
		sw->Write((p[i]->get_age()).ToString());		//�N��̏�������	*int�^����String�^�ɕϊ�
		sw->Write(',');
		sw->Write(p[i]->get_job());						//�E�Ƃ̏�������
		sw->Write('\n');
	}
	sw->Close();										//�t�@�C�������

	return 0;
}
