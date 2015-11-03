#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>

#define ELEM 10	//�\���̗v�f��

//�l���̍\����
typedef struct
{
	TCHAR *name;
	int age;
	TCHAR *job;
}person_t;
enum MEMB { NAME, AGE, JOB };//�����o�ϐ��̗�


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {

/**************************�t�@�C���̃f�[�^���擾*****************************/

	HANDLE hFile;

	// �ǂݍ��ݗp�Ƃ��ăt�@�C�����J��
	hFile = CreateFile(_T("../test.dat"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	TCHAR buf[256];		//�t�@�C���̃f�[�^���󂯎��
	DWORD readsize;		//�ǂݎ�����T�C�Y�͎󂯎��

	if (hFile != INVALID_HANDLE_VALUE)						 // �{���ɊJ�����Ƃ��ł�����
	{	
		ReadFile(hFile, buf, sizeof(buf), &readsize, NULL);	 // buf�ɓǂݍ���

		buf[readsize] = _T('\0');							 // ������'\0'�t��
	}
	CloseHandle(hFile);										 // �t�@�C���n���h�������
		
/**************************�t�@�C���̃f�[�^���\���̔z��Ƀ��[�h*****************************/

	char *delim = ",\r\n";					//�f���~�^�̎w��(�����n����)
	char *ctx;								//�����I�ɗ��p
	char *tp = strtok_s(buf, delim, &ctx);	//delim�Ŏw�肵���L�����Ƃɋ�؂蕶����𒊏o

	person_t p[ELEM] = { NULL };			//�f�[�^�i�[�p
	MEMB memb = NAME;						//�f�[�^�������郁���o���w��
	int num = 0;							//�l���̃f�[�^�����J�E���g

	while (tp){								//�f�[�^���Ȃ��Ȃ�܂ŌJ��Ԃ�

		switch (memb){						//�f�[�^���ǂ̃����o�ɑ�����邩�w��
			case NAME:
				p[num].name = tp;
				memb = AGE;					//���ɑ�����郁���o���w��
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
		tp = strtok_s(0, delim, &ctx);		//���̃f�[�^���擾
	}
	return 0;
}