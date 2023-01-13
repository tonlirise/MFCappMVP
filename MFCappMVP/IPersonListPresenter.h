#pragma once

class IPersonListPresenter
{
public:
	virtual void SelectItem() = 0;

	virtual void UpdateUser() = 0;

	virtual void SaveUser() = 0;

};