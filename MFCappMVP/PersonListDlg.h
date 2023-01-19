#pragma once
#include "MFCappMVP.h"
#include "IPersonListView.h"
#include "PersonListViewModelImpl.h"
#include "Observer.h"

#include "Person.h"

class NameEditBoxObserver;

class CPersonListDlg : public CDialogEx, public IPersonListView
{
	CPersonListViewModelImpl* m_PersonListPresenter{ nullptr };

	CPerson GetPersonUiData();
	long GetSelectedUserID();
public:
	CPersonListDlg(IPersonListViewModel* presenter, CWnd* pParent = nullptr);
	enum { IDD = IDD_DIALOG_PERSON_LIST };

protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	CListBox m_UserListBox;
	CEdit m_NameEditBox;
	CEdit m_AgeEditBox;
	CEdit m_AddressEditBox;
	CButton m_SaveButton;
	CButton m_UpdateBtn;

	afx_msg void OnLbnSelchangeListAll();
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonSave();

	virtual void SetUserListBox(std::map<long, CPerson> data) override;
	virtual void SetName(std::string value) override;
	virtual void SetAge(int value) override;
	virtual void SetAddress(std::string value) override;
};

class NameEditBoxObserver : public IObserver<std::string>
{
	CPersonListDlg* m_pDlg{ nullptr };
public:
	NameEditBoxObserver(CPersonListDlg* dlg) { m_pDlg = dlg; }

	virtual void Update(std::string* value) override
	{
		std::wstring wstr((*value).begin(), (*value).end());
		m_pDlg->m_NameEditBox.SetWindowText(wstr.c_str());
	}
};

class AgeEditBoxObserver : public IObserver<int>
{
	CPersonListDlg* m_pDlg{ nullptr };
public:
	AgeEditBoxObserver(CPersonListDlg* dlg) { m_pDlg = dlg; }

	virtual void Update(int* value) override
	{
		CString str;
		str.Format(_T("%d"), *value);
		m_pDlg->m_AgeEditBox.SetWindowText(str);
	}
};

class AddressEditBoxObserver : public IObserver<std::string>
{
	CPersonListDlg* m_pDlg{ nullptr };
public:
	AddressEditBoxObserver(CPersonListDlg* dlg) { m_pDlg = dlg; }

	virtual void Update(std::string* value) override
	{
		std::wstring wstr((*value).begin(), (*value).end());
		m_pDlg->m_AddressEditBox.SetWindowText(wstr.c_str());
	}
};

class UserListEditBoxObserver : public IObserver<std::map<long, CPerson>>
{
	CPersonListDlg* m_pDlg{ nullptr };
public:
	UserListEditBoxObserver(CPersonListDlg* dlg) { m_pDlg = dlg; }

	virtual void Update(std::map<long, CPerson>* data) override
	{
		m_pDlg->m_UserListBox.ResetContent();
		for each (auto i in *data)
		{
			std::string val = i.second.GetName() + " | " + i.second.GetAddress();
			std::wstring path_wstr(val.begin(), val.end());
			m_pDlg->m_UserListBox.InsertString(-1, path_wstr.c_str());
		}
	}
};