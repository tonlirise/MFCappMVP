#pragma once
#include "IPersonListView.h"
#include "IPersonListRepository.h"
#include "Observable.h"


class CPersonListPresenterImpl : public IPersonListPresenter
{
private:
	IPersonListRepository* m_IPersonListRepository {nullptr};

	IObservable<std::string>* m_pObsName {nullptr};
	IObservable<int>* m_pObsAge {nullptr};
	IObservable<std::string>* m_pObsAddress {nullptr};
	IObservable<std::map<long, CPerson>>* m_pObsUserList{nullptr};

	bool ValidateDuplicationUser(CPerson user);

	void UpdateUserListView();

public:
	CPersonListPresenterImpl(IPersonListRepository* i_IPersonListRepository);

	~CPersonListPresenterImpl();

	void UpdateObservers(IObserver<std::string>* m_obsName, 
		IObserver<int>* m_obsAge,
		IObserver<std::string>* m_obsAddress,
		IObserver<std::map<long, CPerson>>* m_obsUserList
		);

	virtual void UpdateUser() override;
	virtual void SaveUser() override;
	virtual void SelectItem() override;
};

