#pragma once
#include "pch.h"
#include "IUserFormView.h"
#include "IUserFormRepository.h"

class UserManagmentPresenter
{
public:
	UserManagmentPresenter();
	~UserManagmentPresenter();

	void SetIUserForm(IUserFormView* i_IUserForm);
	void SetIUserFormRepository(IUserFormRepository* i_IUserFormRepository);
	void UpdateUser();
	void UpdateUserListView();
	void SaveUser();
	void SelectItem();


protected:
private:
	IUserFormView* m_IUserForm;
	IUserFormRepository* m_IUserFormRepository;

	bool ValidateDuplicationUser(CUser user);
};