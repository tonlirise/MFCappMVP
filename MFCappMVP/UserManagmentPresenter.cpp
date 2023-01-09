#include "pch.h"
#include "UserManagmentPresenter.h"
#include "CUser.h"

UserManagmentPresenter::UserManagmentPresenter()
{
}

UserManagmentPresenter::~UserManagmentPresenter()
{
}

void UserManagmentPresenter::SetIUserForm(IUserFormView* i_IUserForm)
{
	m_IUserForm = i_IUserForm;
	m_IUserForm->SetPresenter(this);
}

void UserManagmentPresenter::SetIUserFormRepository(IUserFormRepository* i_IUserFormRepository)
{
	m_IUserFormRepository = i_IUserFormRepository;
}

void UserManagmentPresenter::UpdateUser()
{
	CUser user = m_IUserFormRepository->FindbyName(m_IUserForm->GetName());

	user.SetName(m_IUserForm->GetName());
	user.SetAge(m_IUserForm->GetAge());
	user.SetAddress(m_IUserForm->GetAddress());

	m_IUserFormRepository->UpdateUser(user);
}

void UserManagmentPresenter::UpdateUserListView()
{
	std::map<long, CUser> allUserLIst = m_IUserFormRepository->GetAllUsers();

	m_IUserForm->SetUserListBox(allUserLIst);
}

void UserManagmentPresenter::SaveUser()
{
	CUser user;
	user.SetName(m_IUserForm->GetName());
	user.SetAge(m_IUserForm->GetAge());
	user.SetAddress(m_IUserForm->GetAddress());

	bool validate = ValidateDuplicationUser(user);
	if (validate == false)
	{
		m_IUserFormRepository->SaveUser(user);
	}
	else
	{
		m_IUserFormRepository->UpdateUser(user);
	}

	UpdateUserListView();
}

void UserManagmentPresenter::SelectItem()
{
	long id = m_IUserForm->getSelectedUserID() + 1;
	CUser user = m_IUserFormRepository->FindbyID(id);

	m_IUserForm->SetName(user.GetName());
	m_IUserForm->SetAge(user.GetAge());
	m_IUserForm->SetAddress(user.GetAddress());
}

bool UserManagmentPresenter::ValidateDuplicationUser(CUser user)
{
	CUser existUser = m_IUserFormRepository->FindbyName(user.GetName());

	bool result = user.GetName() == existUser.GetName() ? true : false;

	return result;
}