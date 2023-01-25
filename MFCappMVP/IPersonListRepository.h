#pragma once

#include "Person.h"

#include <map>

class IPersonListRepository
{
public:
	virtual CPerson* SelectItem(int nSelectedUserID) = 0;

	virtual std::map<long, CPerson> GetAllUsers() = 0;

	virtual void UpdateUser(CPerson objPerson) = 0;

	virtual bool SaveUser(CPerson objPerson) = 0;
};