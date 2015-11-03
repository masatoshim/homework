#include<iostream>
using namespace std;

#define NAME		40									//氏名文字数
#define JOB			40									//職業文字数
#define ELEM(array) (sizeof(array)/sizeof *(array))		//配列要素数

//個人情報
class person{
	char name[NAME];
	int age;
	char job[JOB];
public:
	person(){}
	person(char *n,int a,char *j)
	{
		strcpy_s(name, n);
		age = a;
		strcpy_s(job, j);
	}
	char *get_name(){ return name; }
	int get_age(){ return age; }
	char *get_job(){ return job; }
	
	//氏名検索
	bool name_judge(char *n)
	{
		for (int i = 0; name[i] == n[i]; i++)
			if (i + 1 == strlen(name))return true;
		return false;
	}
};

//動作確認用
int main()
{
	//個人情報のオブジェクト配列
	person p[] = {
		person("john", 21, "aaaaa"),
		person("david", 22, "bbbbb"),
		person("leon", 23, "ccccc"),
		person("elam", 23, "ccccc"),
	};

	char in[NAME];	

	cout << "input name:";				//検索する氏名を入力
	cin >> in;

	person p1;							//個人情報格納用
	bool flg = false;					//name_judge()の返り値格納用
	for (int i = 0; i < ELEM(p); i++){	//個人情報から氏名が一致するものを検索
		if (p[i].name_judge(in)){
			p1 = p[i];					//氏名が一致する個人情報があれば代入
			flg = true;					//フラグを立てる
		}
	}

	if (flg){							//個人情報から氏名が一致するものがあればデータを表示
		cout << p1.get_name() << "\n";
		cout << p1.get_age() << "\n";
		cout << p1.get_job() << "\n";
	}
	

	return 0;


}