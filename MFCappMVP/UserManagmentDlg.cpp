
// MFCappMVPDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCappMVP.h"
#include "UserManagmentDlg.h"
#include "afxdialogex.h"

#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно UserManagmentDlg



UserManagmentDlg::UserManagmentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPMVP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void UserManagmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ALL, m_UserListBox);
	DDX_Control(pDX, IDC_EDIT_NAME, m_NameEditBox);
	DDX_Control(pDX, IDC_EDIT_AGE, m_AgeEditBox);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_AddressEditBox);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_SaveButton);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_UpdateBtn);
}

BEGIN_MESSAGE_MAP(UserManagmentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST_ALL, &UserManagmentDlg::OnLbnSelchangeListAll)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &UserManagmentDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &UserManagmentDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()

void UserManagmentDlg::SetPresenter(UserManagmentPresenter* presenter)
{
	m_UserManagmentPresenter = presenter;
}

BOOL UserManagmentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void UserManagmentDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void UserManagmentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR UserManagmentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void UserManagmentDlg::SetUserListBox(std::map<long, CUser> data)
{
	m_UserListBox.ResetContent();
	for each (auto i in data)
	{
		std::string val = i.second.GetName() + " | " + i.second.GetAddress();
		wstring path_wstr(val.begin(), val.end());
		m_UserListBox.InsertString(-1, path_wstr.c_str());
		std::cout << "user id : " + i.second.GetID() << std::endl;
	}
}

void UserManagmentDlg::SetName(string value)
{
	wstring wstr(value.begin(), value.end());
	m_NameEditBox.SetWindowText(wstr.c_str());
}

string UserManagmentDlg::GetName()
{
	CString cstr = _T("");
	m_NameEditBox.GetWindowText(cstr);
	string str = CT2CA(cstr);
	return str;
}

void UserManagmentDlg::SetAge(int value)
{
	CString str;
	str.Format(_T("%d"), value);
	m_AgeEditBox.SetWindowText(str);
}

int UserManagmentDlg::GetAge()
{
	CString cstr;
	m_AgeEditBox.GetWindowText(cstr);
	int value = _ttoi(cstr);
	return value;
}

void UserManagmentDlg::SetAddress(string value)
{
	wstring wstr(value.begin(), value.end());
	m_AddressEditBox.SetWindowText(wstr.c_str());
}

string UserManagmentDlg::GetAddress()
{
	CString cstr = _T("");
	m_AddressEditBox.GetWindowText(cstr);
	string str = CT2CA(cstr);
	return str;
}


void UserManagmentDlg::OnLbnSelchangeListAll()
{
	m_UserManagmentPresenter->SelectItem();
}

long UserManagmentDlg::getSelectedUserID()
{
	long value = m_UserListBox.GetCurSel();
	return value;
}


void UserManagmentDlg::OnBnClickedButtonUpdate()
{
	m_UserManagmentPresenter->UpdateUser();
}


void UserManagmentDlg::OnBnClickedButtonSave()
{
	m_UserManagmentPresenter->SaveUser();
}
