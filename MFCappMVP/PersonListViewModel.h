#pragma once
#include "IPersonListRepository.h"
#include "External/MvvmCore/Observable.h"

#include "PersonListUiState.h"

#include <map>

class CPersonListViewModel : public IUpdateObserver<IPersonListUiState>
{
	IPersonListRepository* m_IPersonListRepository {nullptr};
	IObservable<IPersonListUiState>* m_pObsUiState{nullptr};

	CPersonListUiStateMain m_uiCurrState;
	void PushMainStateToUI();

public:
	CPersonListViewModel(IPersonListRepository* i_IPersonListRepository);

	~CPersonListViewModel();

	void UpdateObserver(std::function<void(IPersonListUiState*)> m_obsName) override;

	void UpdateUser(CPerson objPerson);
	void SaveUser(CPerson objPerson);
	void SelectItem(int nSelectedUserID);
};

