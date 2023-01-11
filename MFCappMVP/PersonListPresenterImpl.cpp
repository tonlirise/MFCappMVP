#include "pch.h"

#include "PersonListPresenterImpl.h"

CPersonListPresenterImpl::CPersonListPresenterImpl(CPersonListView* i_IPersonListView, CPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListView = i_IPersonListView;
	m_IPersonListView->SetPresenter(this);

	m_IPersonListRepository = i_IPersonListRepository;
}

CPersonListPresenterImpl::~CPersonListPresenterImpl() {}


void CPersonListPresenterImpl::UpdateUser()
{
	CPerson user = m_IPersonListRepository->FindbyName(m_IPersonListView->GetName());

	user.SetName(m_IPersonListView->GetName());
	user.SetAge(m_IPersonListView->GetAge());
	user.SetAddress(m_IPersonListView->GetAddress());

	m_IPersonListRepository->UpdateUser(user);
}

void CPersonListPresenterImpl::UpdateUserListView()
{
	std::map<long, CPerson> allUserLIst = m_IPersonListRepository->GetAllUsers();

	m_IPersonListView->SetUserListBox(allUserLIst);
}

void CPersonListPresenterImpl::SaveUser()
{
	CPerson user;
	user.SetName(m_IPersonListView->GetName());
	user.SetAge(m_IPersonListView->GetAge());
	user.SetAddress(m_IPersonListView->GetAddress());

	bool validate = ValidateDuplicationUser(user);
	if (validate == false)
	{
		m_IPersonListRepository->SaveUser(user);
	}
	else
	{
		m_IPersonListRepository->UpdateUser(user);
	}

	UpdateUserListView();
}

void CPersonListPresenterImpl::SelectItem()
{
	long id = m_IPersonListView->getSelectedUserID() + 1;
	CPerson user = m_IPersonListRepository->FindbyID(id);

	m_IPersonListView->SetName(user.GetName());
	m_IPersonListView->SetAge(user.GetAge());
	m_IPersonListView->SetAddress(user.GetAddress());
}

bool CPersonListPresenterImpl::ValidateDuplicationUser(CPerson user)
{
	CPerson existUser = m_IPersonListRepository->FindbyName(user.GetName());

	bool result = user.GetName() == existUser.GetName() ? true : false;

	return result;
}