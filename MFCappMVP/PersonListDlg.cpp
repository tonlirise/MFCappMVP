#include "stdafx.h"
#include "framework.h"
#include "MFCappMVP.h"
#include "afxdialogex.h"

#include "PersonListDlg.h"

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPersonListDlg::CPersonListDlg(IPersonListViewModel* pViewModel,
	CWnd* pParent /*=nullptr*/): CDialogEx(CPersonListDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pPersonListViewModel = static_cast<CPersonListViewModelImpl*>(pViewModel);
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

BOOL CPersonListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	auto nameUpdater = [this](std::string sVal)
	{
		std::wstring wstr(sVal.begin(), sVal.end());
		m_NameEditBox.SetWindowText(wstr.c_str());
	};

	auto ageUpdater = [this](int nVal)
	{
		CString str;
		str.Format(_T("%d"), nVal);
		m_AgeEditBox.SetWindowText(str);
	};

	auto addressUpdater = [this](std::string sVal)
	{
		std::wstring wstr(sVal.begin(), sVal.end());
		m_AddressEditBox.SetWindowText(wstr.c_str());
	};

	auto userListUpdater = [this](std::map<long, CPerson> data)
	{
		m_UserListBox.ResetContent();
		for each (auto i in data)
		{
			std::string val = i.second.GetName() + " | " + i.second.GetAddress();
			std::wstring path_wstr(val.begin(), val.end());
			m_UserListBox.InsertString(-1, path_wstr.c_str());
		}
	};

	m_pPersonListViewModel->UpdateObservers(nameUpdater, ageUpdater, addressUpdater, userListUpdater);

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

void CPersonListDlg::OnLbnSelchangeListAll()
{
	m_pPersonListViewModel->SelectItem(GetSelectedUserID()+1);
}

void CPersonListDlg::OnBnClickedButtonUpdate()
{
	m_pPersonListViewModel->UpdateUser(GetPersonUiData());
}

void CPersonListDlg::OnBnClickedButtonSave()
{
	m_pPersonListViewModel->SaveUser(GetPersonUiData());
}
