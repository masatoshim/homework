#include<iostream>

/* 
*	strstrのコピー
*	s1:検索対象文字列
*	s2:検索文字列
*/
char *search(const char *s1, const char *s2)
{
	int i = 0;							//カウンタ
	int length = 0;						//検索文字列の文字数
	
	while (*s1 != '\0'){									//検索開始
		while (s1[i] == s2[i]){								//検索文字列を1文字ずつ一致するか確認
			if ((i + 1) == strlen(s2)) return (char *)s1;	//検索文字列が検索対象文字列にすべて含まれる場合、先頭ポインタを返す
			i++;											//次の検索文字から比較
		}
		i = 0;												//次の検索対象文字から比較
		s1++;
	}
	return NULL;						//検索対象文字列に検索文字列が含まれない場合、NULLを返す
}

/*
*	動作確認用コード
*/
int main()
{
	char letter[] = "abcde";	//検索対象文字列
	
	printf("%s \n", search(letter, "ab"));	//検索文字列"ab" => 含まれる
	printf("%s \n", search(letter, "bc"));	//検索文字列"bc" => 含まれる
	printf("%s \n", search(letter, "cb"));	//検索文字列"cb" => 含まれない
	
	getchar();
	return 0;
}