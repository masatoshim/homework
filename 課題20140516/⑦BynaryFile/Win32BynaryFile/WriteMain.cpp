#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define ELEM(array) (sizeof(array)/sizeof *(array))		//�\���̗v�f��

//�l���̍\����
typedef struct
{
	TCHAR *name;
	int age;
	TCHAR *job;
}person_t;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR lpCmdLine, int nCmdShow) {

	//�l���̏�����
	person_t p[]{
		{ _T("barski"), 25, _T("fffffff") },
		{ _T("john"), 23, _T("ccccccc") },
		{ _T("david"), 24, _T("ddddddd") }
	};

	HANDLE hFile;

	// �������ݗp�Ƃ��ăt�@�C�����J��
	hFile = CreateFile(_T("../test.dat"), GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD writesize;					//�������߂��T�C�Y�͎󂯎��

	if (hFile != INVALID_HANDLE_VALUE)  // �{���ɊJ�����Ƃ��ł�����
	{
		//�l���̐l�����J��Ԃ�	*�f�[�^�̒���'\0'�����荞�܂Ȃ��悤���ӂ���
		for (int i = 0; i < ELEM(p); i++){
			
			WriteFile(hFile, p[i].name, _tcslen(p[i].name) , &writesize, NULL);	//���O�̏�������
			WriteFile(hFile, ",", 1, &writesize, NULL);							//��؂�

			WriteFile(hFile, &p[i].age, 1, &writesize, NULL);					//�N��̏�������
			WriteFile(hFile, ",", 1, &writesize, NULL);							//��؂�

			WriteFile(hFile, p[i].job, _tcslen(p[i].job) , &writesize, NULL);	//�E�Ƃ̏�������
			WriteFile(hFile, _T("\r\n"), 2, &writesize, NULL);					//���s
		}
	}
	//�t�@�C���n���h�������
	CloseHandle(hFile);

	return 0;
	
}