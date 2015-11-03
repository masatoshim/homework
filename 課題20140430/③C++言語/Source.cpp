#include<iostream>
using namespace std;

#define NAME		40									//����������
#define JOB			40									//�E�ƕ�����
#define ELEM(array) (sizeof(array)/sizeof *(array))		//�z��v�f��

//�l���
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
	
	//��������
	bool name_judge(char *n)
	{
		for (int i = 0; name[i] == n[i]; i++)
			if (i + 1 == strlen(name))return true;
		return false;
	}
};

//����m�F�p
int main()
{
	//�l���̃I�u�W�F�N�g�z��
	person p[] = {
		person("john", 21, "aaaaa"),
		person("david", 22, "bbbbb"),
		person("leon", 23, "ccccc"),
		person("elam", 23, "ccccc"),
	};

	char in[NAME];	

	cout << "input name:";				//�������鎁�������
	cin >> in;

	person p1;							//�l���i�[�p
	bool flg = false;					//name_judge()�̕Ԃ�l�i�[�p
	for (int i = 0; i < ELEM(p); i++){	//�l��񂩂玁������v������̂�����
		if (p[i].name_judge(in)){
			p1 = p[i];					//��������v����l��񂪂���Α��
			flg = true;					//�t���O�𗧂Ă�
		}
	}

	if (flg){							//�l��񂩂玁������v������̂�����΃f�[�^��\��
		cout << p1.get_name() << "\n";
		cout << p1.get_age() << "\n";
		cout << p1.get_job() << "\n";
	}
	

	return 0;


}