#include<iostream>

/* 
*	strstr�̃R�s�[
*	s1:�����Ώە�����
*	s2:����������
*/
char *search(const char *s1, const char *s2)
{
	int i = 0;							//�J�E���^
	int length = 0;						//����������̕�����
	
	while (*s1 != '\0'){									//�����J�n
		while (s1[i] == s2[i]){								//�����������1��������v���邩�m�F
			if ((i + 1) == strlen(s2)) return (char *)s1;	//���������񂪌����Ώە�����ɂ��ׂĊ܂܂��ꍇ�A�擪�|�C���^��Ԃ�
			i++;											//���̌������������r
		}
		i = 0;												//���̌����Ώە��������r
		s1++;
	}
	return NULL;						//�����Ώە�����Ɍ��������񂪊܂܂�Ȃ��ꍇ�ANULL��Ԃ�
}

/*
*	����m�F�p�R�[�h
*/
int main()
{
	char letter[] = "abcde";	//�����Ώە�����
	
	printf("%s \n", search(letter, "ab"));	//����������"ab" => �܂܂��
	printf("%s \n", search(letter, "bc"));	//����������"bc" => �܂܂��
	printf("%s \n", search(letter, "cb"));	//����������"cb" => �܂܂�Ȃ�
	
	getchar();
	return 0;
}