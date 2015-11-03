
// FileControllSampDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "FileControllSamp.h"
#include "FileControllSampDlg.h"
#include "afxdialogex.h"
#include "person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileControllSampDlg �_�C�A���O



CFileControllSampDlg::CFileControllSampDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileControllSampDlg::IDD, pParent)
	, filePath(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileControllSampDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, filePath);
	//DDX_Text(pDX, IDC_EDIT1, filePath);
	DDX_Text(pDX, IDC_EDIT1, filePath);
}

BEGIN_MESSAGE_MAP(CFileControllSampDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFileControllSampDlg::OpenSelectFile)
	ON_BN_CLICKED(IDC_BUTTON2, &CFileControllSampDlg::OnClickedBtnWriterFile)
END_MESSAGE_MAP()


// CFileControllSampDlg ���b�Z�[�W �n���h���[

BOOL CFileControllSampDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

void CFileControllSampDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CFileControllSampDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CFileControllSampDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//----------------------------------------------------------------------------------------------------------

//�t�@�C������1�s�ǂݍ���
void CFileControllSampDlg::OpenSelectFile()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CWnd::UpdateData(TRUE);
	CStdioFile cSelectFile;
	cSelectFile.Open(filePath, CFile::modeRead);//filePath�Ɏw�肵���e�L�X�g�t�@�C����ǂݎ���p�ŊJ��
	CString read;
	cSelectFile.ReadString(read);				//�e�L�X�g�t�@�C����1�s�ǂݍ���
	AfxMessageBox(read);						//���b�Z�[�W�{�b�N�X�ɓǂݍ��񂾕������\��
	cSelectFile.Close();
		
	
}

void CFileControllSampDlg::OnClickedBtnWriterFile()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CWnd::UpdateData(TRUE);
	CStdioFile cSelectFile;

	//filePath�Ɏw�肵���e�L�X�g�t�@�C�����������ݐ�p�ŊJ��.�t�@�C�X�����݂��Ȃ���ΐV�K�쐬
	cSelectFile.Open(filePath, CStdioFile::modeWrite | CStdioFile::modeCreate | CStdioFile::modeNoTruncate);
	
	//�l���̏�����
	person p[] = {
		person("john", 21, "aaaaa"),
		person("david", 22, "bbbbb"),
		person("leon", 23, "ccccc"),
		person("elam", 23, "ccccc"),
	};
	int elem = sizeof(p) / sizeof(p[0]);		//�v�f���̎擾

	for (int i = 0; i < elem; i++){				//�t�@�C���Ɍl���̏������݂��J�n	
		
		//�����o�̒l���擾
		char *name = p[i].get_name();					
		int age = p[i].get_age();
		char *job = p[i].get_job();
		
		//�����o�̒l��CString�^�ɕϊ�
		CString str_name = NULL;						
		str_name = name;
		CString str_age = NULL;
		str_age.Format(_T("%d"), age);
		CString str_job = NULL;
		str_job = job;
		
		//�����o�̒l���J���}��؂�ŘA�����Ō�ɉ��s������
		CString personalDate = str_name + "," + str_age + "," + str_job + "\n";

		cSelectFile.WriteString(personalDate);	//�t�@�C���ɏ�������

	}

	cSelectFile.Close();
}
