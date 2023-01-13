#pragma once
#include "IPersonListView.h"
#include "IPersonListRepository.h"


class CPersonListPresenterImpl : public IPersonListPresenter
{
private:
	IPersonListView* m_IPersonListView {nullptr};
	IPersonListRepository* m_IPersonListRepository {nullptr};

	bool ValidateDuplicationUser(CPerson user);

public:
	CPersonListPresenterImpl(
		IPersonListView* i_IPersonListView, 
		IPersonListRepository* i_IPersonListRepository
	);

	~CPersonListPresenterImpl();

	void UpdateUserListView();

	virtual void UpdateUser() override;
	virtual void SaveUser() override;
	virtual void SelectItem() override;
};
