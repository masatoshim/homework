#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>

#define ELEM 10	//構造体要素数

//個人情報の構造体
typedef struct
{
	TCHAR *name;
	int age;
	TCHAR *job;
}person_t;
enum MEMB { NAME, AGE, JOB };//メンバ変数の列挙


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {

/**************************ファイルのデータを取得*****************************/

	HANDLE hFile;

	// 読み込み用としてファイルを開く
	hFile = CreateFile(_T("../test.dat"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	TCHAR buf[256];		//ファイルのデータを受け取る
	DWORD readsize;		//読み取ったサイズは受け取る

	if (hFile != INVALID_HANDLE_VALUE)						 // 本当に開くことができたか
	{	
		ReadFile(hFile, buf, sizeof(buf), &readsize, NULL);	 // bufに読み込み

		buf[readsize] = _T('\0');							 // 末尾に'\0'付加
	}
	CloseHandle(hFile);										 // ファイルハンドルを閉じる
		
/**************************ファイルのデータを構造体配列にロード*****************************/

	char *delim = ",\r\n";					//デリミタの指定(複数渡せる)
	char *ctx;								//内部的に利用
	char *tp = strtok_s(buf, delim, &ctx);	//delimで指定した記号ごとに区切り文字列を抽出

	person_t p[ELEM] = { NULL };			//データ格納用
	MEMB memb = NAME;						//データを代入するメンバを指定
	int num = 0;							//個人情報のデータ数をカウント

	while (tp){								//データがなくなるまで繰り返し

		switch (memb){						//データをどのメンバに代入するか指定
			case NAME:
				p[num].name = tp;
				memb = AGE;					//次に代入するメンバを指定
				break;
			case AGE:
				p[num].age = *tp;
				memb = JOB;
				break;
			case JOB:
				p[num].job = tp;
				memb = NAME;
				num++;						
				break;
		}
		tp = strtok_s(0, delim, &ctx);		//次のデータを取得
	}
	return 0;
}