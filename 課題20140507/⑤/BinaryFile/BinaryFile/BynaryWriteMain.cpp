#include<iostream>
using namespace System;
using namespace System::IO;


//個人情報の構造体
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

//個人情報配列の情報をバイナリモードでファイルに書き込み
int main()
{
	//個人情報の初期化
	array<Person^>^ p = gcnew array<Person^>{
			gcnew Person("john", 21, "aaaaa"),
			gcnew Person("david", 22, "bbbbb"),
			gcnew Person("leon", 23, "ccccc"),
			gcnew Person("elam", 24, "ddddd")
	};
	
	String^ fileName = "../data.bin";								//相対パスでファイルを指定
	FileStream^ fs = gcnew FileStream(fileName, FileMode::Create);	//ファイルを新規作成
	BinaryWriter^ w = gcnew BinaryWriter(fs);						//バイナリモードで書き込み

	try{
		for (int i = 0; i < p->Length; i++){						//人数分繰り返し
			w->Write(p[i]->name);
			w->Write((p[i]->age).ToString());
			w->Write(p[i]->job);
		}
	}
	catch (Exception^){												//エラー処理
		Console::WriteLine("ERROR!!");
		fs->Close();
		return -1;
	}

	fs->Close();	//ファイルを閉じる

	return 0;
}