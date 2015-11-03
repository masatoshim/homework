#include<stdio.h>
#include<iostream>

#define NAME		40									//����������
#define JOB			40									//�E�ƕ�����
#define ELEM(array) (sizeof(array)/sizeof *(array))		//�\���̗v�f��

//�l���̍\����
typedef struct 
{
	char name[NAME];
	int age;
	char job[JOB];
}person_t;

/*
*	name_search:��������
*		�l��񂩂玁�������S��v������̂���������
*		��v������̂�����΂��̃A�h���X��Ԃ�.�Ȃ����NULL��Ԃ�
*	const person_t *p1	:�����ΏۂɂȂ�l���z��̐擪�A�h���X
*	char *n				:��������
*	int num				:�����Ώۂ̗v�f��(�z��̗v�f��)
*/
person_t *name_search(const person_t *p1, char *n,int num)
{
	int i, j;											//�J�E���^
	
	for (i = 0; i < num; i++){							//�����J�n
		j = 0;
		while (p1->name[j] == n[j]){					//������������v���邩1�������m�F
			if ((j + 1) == strlen(p1->name)){
				return (person_t *)p1;					//�������������ׂĈ�v�����ꍇ�A�h���X��Ԃ�
			}
			j++;										//���̕������r
		}
		p1++;											//���̌l�����Q��
	}
	return NULL;										//��v���鎁�����Ȃ����NULL��Ԃ�
}

//����m�F�p
int main()
{
	//�l���\���̔z��̒l��ݒ�
	person_t people[]{
		{ "barski", 25, "fffffff" },
		{ "john", 23, "ccccccc" },
		{ "david", 24, "ddddddd" },
	};

	person_t *p;

	p = name_search(people, "barski", ELEM(people)); //�f�[�^�L��
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "john", ELEM(people));	//�f�[�^�L��
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "david", ELEM(people));	//�f�[�^�L��
	printf("%s \n", p->name);
	printf("%d \n", p->age);
	printf("%s \n\n", p->job);

	p = name_search(people, "bars", ELEM(people)); //�f�[�^����
	if (p == NULL)printf("null data");

	getchar();
	return 0;
}