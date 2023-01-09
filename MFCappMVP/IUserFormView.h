#pragma once
#include "framework.h"
#include "CUser.h"

#include <string>
#include <map>

class UserManagmentPresenter;

class IUserFormView
{
public:
	virtual void SetUserListBox(std::map<long, CUser> data) = 0;
	virtual void SetName(std::string value) = 0;
	virtual std::string GetName() = 0;
	virtual long getSelectedUserID() = 0;

	virtual void SetAge(int value) = 0;
	virtual int GetAge() = 0;

	virtual void SetAddress(std::string value) = 0;
	virtual std::string GetAddress() = 0;
	virtual void SetPresenter(UserManagmentPresenter* presenter) = 0;
};
