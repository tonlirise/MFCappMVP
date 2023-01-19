#pragma once
#include "MFCappMVP.h"
#include "IPersonListViewModel.h"
#include "PersonListViewModelImpl.h"
#include "Observer.h"

#include "Person.h"

class CPersonListDlg : public CDialogEx
{
	CPersonListViewModelImpl* m_pPersonListViewModel{ nullptr };

	CPerson GetPersonUiData();
	long GetSelectedUserID();
public:
	CPersonListDlg(IPersonListViewModel* pViewModel, CWnd* pParent = nullptr);
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
};
