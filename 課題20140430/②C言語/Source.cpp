#include<stdio.h>
#include<iostream>

#define NAME		40									//氏名文字数
#define JOB			40									//職業文字数
#define ELEM(array) (sizeof(array)/sizeof *(array))		//構造体要素数

//個人情報の構造体
typedef struct 
{
	char name[NAME];
	int age;
	char job[JOB];
}person_t;

/*
*	name_search:氏名検索
*		個人情報から氏名が完全一致するものを検索する
*		一致するものがあればそのアドレスを返す.なければNULLを返す
*	const person_t *p1	:検索対象になる個人情報配列の先頭アドレス
*	char *n				:検索氏名
*	int num				:検索対象の要素数(配列の要素数)
*/
person_t *name_search(const person_t *p1, char *n,int num)
{
	int i, j;											//カウンタ
	
	for (i = 0; i < num; i++){							//検索開始
		j = 0;
		while (p1->name[j] == n[j]){					//検索氏名が一致するか1文字ずつ確認
			if ((j + 1) == strlen(p1->name)){
				return (person_t *)p1;					//検索氏名がすべて一致した場合アドレスを返す
			}
			j++;										//次の文字を比較
		}
		p1++;											//次の個人情報を参照
	}
	return NULL;										//一致する氏名がなければNULLを返す
}

//動作確認用
int main()
{
	//個人情報構造体配列の値を設定
	person_t people[]{
		{ "barski", 25, "fffffff" },
		{ "john", 23, "ccccccc" },
		{ "david", 24, "ddddddd" },
	};

	person_t *p;

	p = name_search(people, "barski", ELEM(people)); //データ有り
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "john", ELEM(people));	//データ有り
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "david", ELEM(people));	//データ有り
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "bars", ELEM(people)); //データ無し
	if (p == NULL)printf("null data");

	getchar();
	return 0;
}