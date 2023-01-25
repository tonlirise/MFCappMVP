#include "stdafx.h"

#include "PersonListViewModel.h"

CPersonListViewModel::CPersonListViewModel(IPersonListRepository* i_IPersonListRepository)
{
	m_IPersonListRepository = i_IPersonListRepository;

	m_pObsUiState = new CUiObservable<IPersonListUiState>();
}

CPersonListViewModel::~CPersonListViewModel() {}

void CPersonListViewModel::UpdateObserver(std::function<void(IPersonListUiState*)> obsUiState)
{
	m_pObsUiState->UpdateObserver(obsUiState);

}

void CPersonListViewModel::UpdateUser(CPerson objPerson)
{
	m_IPersonListRepository->UpdateUser(objPerson);

	auto allUsers = m_IPersonListRepository->GetAllUsers();
	m_uiCurrState.SetPersonList(allUsers);
	PushMainStateToUI();
}

void CPersonListViewModel::SaveUser(CPerson objPerson)
{
	if (m_IPersonListRepository->SaveUser(objPerson))
	{
		auto allUsers = m_IPersonListRepository->GetAllUsers();
		m_uiCurrState.SetPersonList(allUsers);
		PushMainStateToUI();
		return;
	}
	std::string sError = "Unable to save record!";
	auto showMessageUi = CPersonListUiStateShowMessage(sError);
	m_pObsUiState->UpdateValue(&showMessageUi);
}

void CPersonListViewModel::SelectItem(int nSelectedUserID)
{
	CPerson* pUser = m_IPersonListRepository->SelectItem(nSelectedUserID);
	if (!pUser) return;

	m_uiCurrState.SetName(pUser->GetName());
	m_uiCurrState.SetAge(pUser->GetAge());
	m_uiCurrState.SetAddress(pUser->GetAddress());
	PushMainStateToUI();
}

void CPersonListViewModel::PushMainStateToUI()
{
	m_pObsUiState->UpdateValue(&m_uiCurrState);
	m_uiCurrState.ResetAllPtr();
}
