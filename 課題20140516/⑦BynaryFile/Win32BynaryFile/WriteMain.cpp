#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define ELEM(array) (sizeof(array)/sizeof *(array))		//構造体要素数

//個人情報の構造体
typedef struct
{
	TCHAR *name;
	int age;
	TCHAR *job;
}person_t;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR lpCmdLine, int nCmdShow) {

	//個人情報の初期化
	person_t p[]{
		{ _T("barski"), 25, _T("fffffff") },
		{ _T("john"), 23, _T("ccccccc") },
		{ _T("david"), 24, _T("ddddddd") }
	};

	HANDLE hFile;

	// 書き込み用としてファイルを開く
	hFile = CreateFile(_T("../test.dat"), GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD writesize;					//書き込めたサイズは受け取る

	if (hFile != INVALID_HANDLE_VALUE)  // 本当に開くことができたか
	{
		//個人情報の人数分繰り返し	*データの中に'\0'が入り込まないよう注意する
		for (int i = 0; i < ELEM(p); i++){
			
			WriteFile(hFile, p[i].name, _tcslen(p[i].name) , &writesize, NULL);	//名前の書き込み
			WriteFile(hFile, ",", 1, &writesize, NULL);							//区切り

			WriteFile(hFile, &p[i].age, 1, &writesize, NULL);					//年齢の書き込み
			WriteFile(hFile, ",", 1, &writesize, NULL);							//区切り

			WriteFile(hFile, p[i].job, _tcslen(p[i].job) , &writesize, NULL);	//職業の書き込み
			WriteFile(hFile, _T("\r\n"), 2, &writesize, NULL);					//改行
		}
	}
	//ファイルハンドルを閉じる
	CloseHandle(hFile);

	return 0;
	
}