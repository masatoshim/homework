#include<iostream>
#using <mscorlib.dll>
using namespace System;
using namespace System::IO;

//個人情報クラス
public ref class Person{
	String^ name;
	int age;
	String^ job;
public:
	Person(){}
	//コンストラクタで値を設定
	Person(String^ n, int a, String^ j)
	{
		name = n;
		age = a;
		job = j;
	}
	//ゲッターメソッド
	String^ get_name(){ return name; }
	int get_age(){ return age; }
	String^ get_job(){ return job; }
};

int main(){
	//個人情報配列の初期設定
	array<Person^>^ p = gcnew array<Person^>{
				gcnew Person("john", 21, "aaaaa"),
				gcnew Person("david", 22, "bbbbb"),
				gcnew Person("leon", 23, "ccccc"),
				gcnew Person("elam", 24, "ddddd")
	};

	String^ fileName = "../sample.txt";					//相対パスでファイルを指定
	StreamWriter^ sw = gcnew StreamWriter(fileName);	//書き込み準備

	for (int i = 0; i < p->Length; i++){				//人数分繰り返し
		sw->Write(p[i]->get_name());					//名前の書き込み
		sw->Write(',');
		sw->Write((p[i]->get_age()).ToString());		//年齢の書き込み	*int型からString型に変換
		sw->Write(',');
		sw->Write(p[i]->get_job());						//職業の書き込み
		sw->Write('\n');
	}
	sw->Close();										//ファイルを閉じる

	return 0;
}
