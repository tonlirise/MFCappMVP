#pragma once

#include "Person.h"

#include <map>

class IPersonsDataSource
{
public:
	virtual void SaveUser(CPerson user) = 0;
	virtual std::map<long, CPerson> GetAllUsers() = 0;
	virtual CPerson* FindbyName(std::string name) = 0;
	virtual CPerson* FindbyID(long id) = 0;
	virtual void UpdateUser(CPerson user) = 0;
};

class CPersonsDataSourceImpl : public IPersonsDataSource
{
public:
	void SaveUser(CPerson user) override;
	virtual std::map<long, CPerson> GetAllUsers() override;
	virtual CPerson* FindbyName(std::string name) override;
	virtual CPerson* FindbyID(long id) override;
	virtual void UpdateUser(CPerson user) override;

private:
	long sequence = 0;
	std::map<long, CPerson> m_mapMemoryStorage;
};