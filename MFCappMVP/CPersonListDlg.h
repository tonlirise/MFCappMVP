#pragma once
#include "MFCappMVP.h"
#include "CPersonListView.h"
#include "CPersonListPresenter.h"

#include "CPerson.h"

class CPersonListDlg : public CDialogEx, public CPersonListView
{
	CPersonListPresenter* m_PersonListPresenter {nullptr};

public:
	CPersonListDlg(CWnd* pParent = nullptr);

	enum { IDD = IDD_DIALOG_PERSON_LIST };

protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
	virtual void SetPresenter(CPersonListPresenter* presenter) override;

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
	virtual std::string GetName() override;
	virtual void SetAge(int value) override;
	virtual int GetAge() override;
	virtual void SetAddress(std::string value) override;
	virtual std::string GetAddress() override;
	virtual long getSelectedUserID() override;
};