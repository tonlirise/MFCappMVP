#include "stdafx.h"

#include "PersonListPresenterImpl.h"

CPersonListPresenterImpl::CPersonListPresenterImpl(IPersonListView* i_IPersonListView, IPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListView = i_IPersonListView;
	m_IPersonListView->SetPresenter(this);

	m_IPersonListRepository = i_IPersonListRepository;
}

CPersonListPresenterImpl::~CPersonListPresenterImpl() {}


void CPersonListPresenterImpl::UpdateUser(CPerson objPerson)
{
	auto user = m_IPersonListRepository->FindbyName(objPerson.GetName());

	user.SetName(objPerson.GetName());
	user.SetAge(objPerson.GetAge());
	user.SetAddress(objPerson.GetAddress());

	m_IPersonListRepository->UpdateUser(user);
}

void CPersonListPresenterImpl::UpdateUserListView()
{
	std::map<long, CPerson> allUserLIst = m_IPersonListRepository->GetAllUsers();

	m_IPersonListView->SetUserListBox(allUserLIst);
}

void CPersonListPresenterImpl::SaveUser(CPerson objPerson)
{
	bool validate = ValidateDuplicationUser(objPerson);

	if (validate == false)
		m_IPersonListRepository->SaveUser(objPerson);
	else
		m_IPersonListRepository->UpdateUser(objPerson);

	UpdateUserListView();
}

void CPersonListPresenterImpl::SelectItem(int nSelectedUserID)
{
	CPerson user = m_IPersonListRepository->FindbyID(nSelectedUserID);

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