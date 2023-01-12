
// MFCappMVP.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCappMVPApp:
// Сведения о реализации этого класса: MFCappMVP.cpp
//

class CMFCappMVPApp : public CWinApp
{
public:
	CMFCappMVPApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCappMVPApp theApp;
