
// FileControllSampDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CFileControllSampDlg �_�C�A���O
class CFileControllSampDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CFileControllSampDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_FILECONTROLLSAMP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OpenSelectFile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OpenSelectFile();
//	CString filePath;
//	LPCTSTR filePath;
	CString filePath;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnClickedBtnWriterFile();
};
