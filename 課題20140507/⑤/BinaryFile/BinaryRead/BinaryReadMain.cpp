#include<iostream>
using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Diagnostics;

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

//バイナリファイルから読み込んだ値を個人情報配列に代入
//個人情報配列のデータを表示
int main()
{
	//個人情報配列の宣言
	Generic::List<Person^>^ p = gcnew Generic::List<Person^>();

	String^ fileName = "../data.bin";									//相対パスでファイルを指定
	try
	{
		FileStream^ fs = gcnew FileStream(fileName, FileMode::Open);	//ファイルオープン
		BinaryReader^ br = gcnew BinaryReader(fs);						//バイナリデータとして読み取る
		
		while (br->BaseStream->Position < br->BaseStream->Length){		//すべて読み取るまで繰り返し

			String^ pName = br->ReadString();							//順番に読み込み　(name→age→jobの順で読み込み)
			int pAge = int::Parse(br->ReadString());					
			String^ pJob = br->ReadString();							

			p->Add(gcnew Person(pName, pAge, pJob));					//個人情報の追加

		}

		fs->Close();													//ファイルを閉じる
	}
	catch (Exception^ e)													//エラー処理
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("File '{0}' not found", fileName);
		else
			Console::WriteLine("Exception: ({0})", e);
		return -1;
	}

	//取得した個人情報の表示
	for (int i = 0; i < p->Count; i++){
		Console::Write(p[i]->name);
		Console::Write(p[i]->age);
		Console::Write(p[i]->job);
		Console::Write("\n");
	}

	getchar(); 
	return 0;
}