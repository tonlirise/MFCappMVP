#include "stdafx.h"

#include "PersonListViewModelImpl.h"

CPersonListViewModelImpl::CPersonListViewModelImpl(IPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListRepository = i_IPersonListRepository;

	m_pObsName = new CUiObservable<std::string>();
	m_pObsAge = new CUiObservable<int>();
	m_pObsAddress = new CUiObservable<std::string>();
	m_pObsUserList = new CUiObservable<std::map<long, CPerson>>();
}

CPersonListViewModelImpl::~CPersonListViewModelImpl() {}

void CPersonListViewModelImpl::UpdateObservers(std::function<void(std::string)> obsName,
	std::function<void(int)> obsAge,
	std::function<void(std::string)> obsAddress,
	std::function<void(std::map<long, CPerson>)> obsUserList)
{
	m_pObsName->UpdateObserver(obsName);
	m_pObsAge->UpdateObserver(obsAge);
	m_pObsAddress->UpdateObserver(obsAddress);
	m_pObsUserList->UpdateObserver(obsUserList);

}

void CPersonListViewModelImpl::UpdateUser(CPerson objPerson)
{
	m_pObsUserList->NotifyChanges();

	auto user = m_IPersonListRepository->FindbyName(objPerson.GetName());

	user.SetName(objPerson.GetName());
	user.SetAge(objPerson.GetAge());
	user.SetAddress(objPerson.GetAddress());

	m_IPersonListRepository->UpdateUser(user);
}

void CPersonListViewModelImpl::UpdateUserListView()
{
	std::map<long, CPerson> allUserLIst = m_IPersonListRepository->GetAllUsers();
	m_pObsUserList->UpdateValue(std::make_shared<std::map<long, CPerson>>(allUserLIst));
}

void CPersonListViewModelImpl::SaveUser(CPerson objPerson)
{
	bool validate = ValidateDuplicationUser(objPerson);
	if (validate == false)
		m_IPersonListRepository->SaveUser(objPerson);
	else
		m_IPersonListRepository->UpdateUser(objPerson);

	UpdateUserListView();
}

void CPersonListViewModelImpl::SelectItem(int nSelectedUserID)
{
	CPerson user = m_IPersonListRepository->FindbyID(nSelectedUserID);

	m_pObsName->UpdateValue(std::make_shared<std::string>(user.GetName()));

	int nAge = (user.GetAge());
	m_pObsAge->UpdateValue(std::make_shared<int>(nAge));

	m_pObsAddress->UpdateValue(std::make_shared<std::string>(user.GetAddress()));
}

bool CPersonListViewModelImpl::ValidateDuplicationUser(CPerson user)
{
	CPerson existUser = m_IPersonListRepository->FindbyName(user.GetName());

	bool result = user.GetName() == existUser.GetName() ? true : false;

	return result;
}