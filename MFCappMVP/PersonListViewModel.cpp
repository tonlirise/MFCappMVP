#include "stdafx.h"

#include "PersonListViewModel.h"

CPersonListViewModel::CPersonListViewModel(IPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListRepository = i_IPersonListRepository;

	m_pObsUiState = new CUiObservable<CPersonListUiState>();
}

CPersonListViewModel::~CPersonListViewModel() {}

void CPersonListViewModel::UpdateObserver(std::function<void(CPersonListUiState)> obsUiState)
{
	m_pObsUiState->UpdateObserver(obsUiState);

}

void CPersonListViewModel::NotifyChanges()
{
	m_pObsUiState->NotifyChanges();
}

void CPersonListViewModel::UpdateUser(CPerson objPerson)
{
	m_IPersonListRepository->UpdateUser(objPerson);

	auto allUsers = m_IPersonListRepository->GetAllUsers();
	m_pObsUiState->UpdateValue(new CPersonListUiState(allUsers));
}

void CPersonListViewModel::SaveUser(CPerson objPerson)
{
	m_IPersonListRepository->SaveUser(objPerson);

	auto allUsers = m_IPersonListRepository->GetAllUsers();
	m_pObsUiState->UpdateValue(new CPersonListUiState(allUsers));
}

void CPersonListViewModel::SelectItem(int nSelectedUserID)
{
	CPerson* pUser = m_IPersonListRepository->SelectItem(nSelectedUserID);
	if (!pUser) return;

	long nAge = (pUser->GetAge());
	m_pObsUiState->UpdateValue(new CPersonListUiState
		(std::map<long, CPerson>(), pUser->GetName(), nAge, pUser->GetAddress()));
}
