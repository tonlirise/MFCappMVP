#pragma once
#include"CUser.h"

#include <map>
#include <string>

class IUserFormRepository
{
public:
	virtual void SaveUser(CUser user) = 0;
	virtual CUser GetUser(long id) = 0;
	virtual std::map<long, CUser> GetAllUsers() = 0;
	virtual CUser FindbyName(std::string name) = 0;
	virtual CUser FindbyID(long id) = 0;
	virtual void UpdateUser(CUser user) = 0;
};