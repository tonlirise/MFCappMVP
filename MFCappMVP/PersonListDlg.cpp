#include "stdafx.h"
#include "framework.h"
#include "MFCappMVP.h"
#include "afxdialogex.h"

#include "PersonListDlg.h"

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPersonListDlg::CPersonListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CPersonListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPersonListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ALL, m_UserListBox);
	DDX_Control(pDX, IDC_EDIT_NAME, m_NameEditBox);
	DDX_Control(pDX, IDC_EDIT_AGE, m_AgeEditBox);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, m_AddressEditBox);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_SaveButton);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_UpdateBtn);
}

BEGIN_MESSAGE_MAP(CPersonListDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST_ALL, &CPersonListDlg::OnLbnSelchangeListAll)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CPersonListDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CPersonListDlg::OnBnClickedButtonSave)
END_MESSAGE_MAP()

void CPersonListDlg::SetPresenter(IPersonListPresenter* presenter)
{
	m_PersonListPresenter = presenter;
}

BOOL CPersonListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	return TRUE;  
}

CPerson CPersonListDlg::GetPersonUiData()
{
	auto getStr = [this](CEdit* editText)
	{
		CString cstr = _T("");
		editText->GetWindowText(cstr);
		return cstr;
	};

	CPerson resPerson;
	std::string tmpValue;

	tmpValue = CT2CA(getStr(&m_NameEditBox));
	resPerson.SetName(tmpValue);

	int nAge = _ttoi(getStr(&m_AgeEditBox));
	resPerson.SetAge(nAge);

	tmpValue = CT2CA(getStr(&m_AddressEditBox));
	resPerson.SetAddress(tmpValue);

	return resPerson;
}

long CPersonListDlg::GetSelectedUserID()
{
	return m_UserListBox.GetCurSel();
}

void CPersonListDlg::SetUserListBox(std::map<long, CPerson> data)
{
	m_UserListBox.ResetContent();
	for each (auto i in data)
	{
		std::string val = i.second.GetName() + " | " + i.second.GetAddress();
		std::wstring path_wstr(val.begin(), val.end());
		m_UserListBox.InsertString(-1, path_wstr.c_str());
		std::cout << "user id : " + i.second.GetID() << std::endl;
	}
}

void CPersonListDlg::SetName(std::string value)
{
	std::wstring wstr(value.begin(), value.end());
	m_NameEditBox.SetWindowText(wstr.c_str());
}

void CPersonListDlg::SetAge(int value)
{
	CString str;
	str.Format(_T("%d"), value);
	m_AgeEditBox.SetWindowText(str);
}

void CPersonListDlg::SetAddress(std::string value)
{
	std::wstring wstr(value.begin(), value.end());
	m_AddressEditBox.SetWindowText(wstr.c_str());
}

void CPersonListDlg::OnLbnSelchangeListAll()
{
	m_PersonListPresenter->SelectItem(GetSelectedUserID() + 1);
}

void CPersonListDlg::OnBnClickedButtonUpdate()
{
	m_PersonListPresenter->UpdateUser(GetPersonUiData());
}

void CPersonListDlg::OnBnClickedButtonSave()
{
	m_PersonListPresenter->SaveUser(GetPersonUiData());
}
