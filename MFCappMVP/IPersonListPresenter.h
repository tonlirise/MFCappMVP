#pragma once

class IPersonListPresenter
{
public:
	virtual void SelectItem(int nSelectedUserID) = 0;

	virtual void UpdateUser(CPerson objPerson) = 0;

	virtual void SaveUser(CPerson objPerson) = 0;

};