#pragma once
#include "CPersonListView.h"
#include "CPersonListRepository.h"


class CPersonListPresenterImpl : public CPersonListPresenter
{
private:
	CPersonListView* m_IPersonListView {nullptr};
	CPersonListRepository* m_IPersonListRepository {nullptr};

	bool ValidateDuplicationUser(CPerson user);

public:
	CPersonListPresenterImpl(CPersonListView* i_IPersonListView, CPersonListRepository* i_IPersonListRepository);
	~CPersonListPresenterImpl();

	void UpdateUserListView();

	virtual void UpdateUser() override;
	virtual void SaveUser() override;
	virtual void SelectItem() override;
};
