
// FileControllSampDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "FileControllSamp.h"
#include "FileControllSampDlg.h"
#include "afxdialogex.h"
#include "person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CFileControllSampDlg ダイアログ



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


// CFileControllSampDlg メッセージ ハンドラー

BOOL CFileControllSampDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CFileControllSampDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CFileControllSampDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//----------------------------------------------------------------------------------------------------------

//ファイルから1行読み込む
void CFileControllSampDlg::OpenSelectFile()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CWnd::UpdateData(TRUE);
	CStdioFile cSelectFile;
	cSelectFile.Open(filePath, CFile::modeRead);//filePathに指定したテキストファイルを読み取り専用で開く
	CString read;
	cSelectFile.ReadString(read);				//テキストファイルを1行読み込み
	AfxMessageBox(read);						//メッセージボックスに読み込んだ文字列を表示
	cSelectFile.Close();
		
	
}

void CFileControllSampDlg::OnClickedBtnWriterFile()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CWnd::UpdateData(TRUE);
	CStdioFile cSelectFile;

	//filePathに指定したテキストファイルを書き込み専用で開く.ファイスが存在しなければ新規作成
	cSelectFile.Open(filePath, CStdioFile::modeWrite | CStdioFile::modeCreate | CStdioFile::modeNoTruncate);
	
	//個人情報の初期化
	person p[] = {
		person("john", 21, "aaaaa"),
		person("david", 22, "bbbbb"),
		person("leon", 23, "ccccc"),
		person("elam", 23, "ccccc"),
	};
	int elem = sizeof(p) / sizeof(p[0]);		//要素数の取得

	for (int i = 0; i < elem; i++){				//ファイルに個人情報の書き込みを開始	
		
		//メンバの値を取得
		char *name = p[i].get_name();					
		int age = p[i].get_age();
		char *job = p[i].get_job();
		
		//メンバの値をCString型に変換
		CString str_name = NULL;						
		str_name = name;
		CString str_age = NULL;
		str_age.Format(_T("%d"), age);
		CString str_job = NULL;
		str_job = job;
		
		//メンバの値をカンマ区切りで連結し最後に改行を入れる
		CString personalDate = str_name + "," + str_age + "," + str_job + "\n";

		cSelectFile.WriteString(personalDate);	//ファイルに書き込む

	}

	cSelectFile.Close();
}
