#pragma once
#include "CPerson.h"
#include "CPersonListPresenter.h"

#include <string>
#include <map>

class CPersonListView
{
public:
	virtual void SetUserListBox(std::map<long, CPerson> data) = 0;
	virtual void SetName(std::string value) = 0;
	virtual std::string GetName() = 0;
	virtual long getSelectedUserID() = 0;

	virtual void SetAge(int value) = 0;
	virtual int GetAge() = 0;

	virtual void SetAddress(std::string value) = 0;
	virtual std::string GetAddress() = 0;

	virtual void SetPresenter(CPersonListPresenter* presenter) = 0;
};