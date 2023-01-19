#pragma once
#include "MFCappMVP.h"
#include "IPersonListView.h"
#include "PersonListViewModelImpl.h"
#include "Observer.h"

#include "Person.h"

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
