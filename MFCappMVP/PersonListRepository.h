#pragma once
#include "Person.h"

#include<map>

class CPersonListRepository
{
public:
	virtual void SaveUser(CPerson user) = 0;
	virtual CPerson GetUser(long id) = 0;
	virtual std::map<long, CPerson> GetAllUsers() = 0;
	virtual CPerson FindbyName(std::string name) = 0;
	virtual CPerson FindbyID(long id) = 0;
	virtual void UpdateUser(CPerson user) = 0;
};