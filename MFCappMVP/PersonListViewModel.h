#pragma once
#include "IPersonListRepository.h"
#include "External/MvvmCore/Observable.h"

#include "PersonListUiState.h"

#include <map>

class CPersonListViewModel : public IUpdateObserver<CPersonListUiState>
{
private:
	IPersonListRepository* m_IPersonListRepository {nullptr};

	IObservable<CPersonListUiState>* m_pObsUiState{nullptr};

public:
	CPersonListViewModel(IPersonListRepository* i_IPersonListRepository);

	~CPersonListViewModel();

	void UpdateObserver(std::function<void(CPersonListUiState)> m_obsName) override;
	void NotifyChanges() override;

	void UpdateUser(CPerson objPerson);
	void SaveUser(CPerson objPerson);
	void SelectItem(int nSelectedUserID);
};

