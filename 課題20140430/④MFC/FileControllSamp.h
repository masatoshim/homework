
// FileControllSamp.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CFileControllSampApp:
// このクラスの実装については、FileControllSamp.cpp を参照してください。
//

class CFileControllSampApp : public CWinApp
{
public:
	CFileControllSampApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CFileControllSampApp theApp;