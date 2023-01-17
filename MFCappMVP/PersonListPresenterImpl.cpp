#include "stdafx.h"

#include "PersonListPresenterImpl.h"

CPersonListPresenterImpl::CPersonListPresenterImpl(IPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListRepository = i_IPersonListRepository;

	m_pObsName = new CUiObservable<std::string>();
	m_pObsAge = new CUiObservable<int>();
	m_pObsAddress = new CUiObservable<std::string>();
	m_pObsUserList = new CUiObservable<std::map<long, CPerson>>();
}

CPersonListPresenterImpl::~CPersonListPresenterImpl() {}

void CPersonListPresenterImpl::UpdateObservers(IObserver<std::string>* obsName,
	IObserver<int>* obsAge,
	IObserver<std::string>* obsAddress,
	IObserver<std::map<long, CPerson>>* obsUserList) 
{
	m_pObsName->UpdateObserver(obsName);
	m_pObsAge->UpdateObserver(obsAge);
	m_pObsAddress->UpdateObserver(obsAddress);
	m_pObsUserList->UpdateObserver(obsUserList);
}


void CPersonListPresenterImpl::UpdateUser()
{
	std::string sName = m_IPersonListView->GetName();

	CPerson user = m_IPersonListRepository->FindbyName(sName);

	user.SetName(sName);
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

	m_pObsName->Update(&user.GetName());

	int nAge = (user.GetAge());
	m_pObsAge->Update(&nAge);

	m_pObsAddress->Update(&user.GetAddress());
}

bool CPersonListPresenterImpl::ValidateDuplicationUser(CPerson user)
{
	CPerson existUser = m_IPersonListRepository->FindbyName(user.GetName());

	bool result = user.GetName() == existUser.GetName() ? true : false;

	return result;
}