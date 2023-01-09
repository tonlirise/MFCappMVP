#pragma once

#include "IUserFormView.h"
#include "UserManagmentPresenter.h"

class UserManagmentDlg : public CDialogEx, public IUserFormView
{

public:
	UserManagmentDlg(CWnd* pParent = nullptr);

	enum { IDD = IDD_MFCAPPMVP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	UserManagmentPresenter* m_UserManagmentPresenter;

	CListBox m_UserListBox;
	CEdit m_NameEditBox;
	CEdit m_AgeEditBox;
	CEdit m_AddressEditBox;
	CButton m_SaveButton;
	CButton m_UpdateBtn;

	virtual void SetUserListBox(std::map<long, CUser> data) override;

	virtual void SetName(std::string value) override;

	virtual std::string GetName() override;

	virtual void SetAge(int value) override;

	virtual int GetAge() override;

	virtual void SetAddress(std::string value) override;

	virtual std::string GetAddress() override;

	virtual void SetPresenter(UserManagmentPresenter* presenter) override;

	virtual long getSelectedUserID() override;
	afx_msg void OnLbnSelchangeListAll();
	afx_msg void OnBnClickedButtonUpdate();
	afx_msg void OnBnClickedButtonSave();
};
