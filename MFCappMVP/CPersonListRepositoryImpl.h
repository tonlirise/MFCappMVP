#pragma once
#include "CPerson.h"
#include "CPersonListRepository.h"

#include <map>

class CPersonListRepositoryImpl : public CPersonListRepository
{
public:

	void SaveUser(CPerson user) override;
	virtual CPerson GetUser(long id) override;
	virtual std::map<long, CPerson> GetAllUsers() override;
	virtual CPerson FindbyName(std::string name) override;
	virtual CPerson FindbyID(long id) override;
	virtual void UpdateUser(CPerson user) override;

private:
	long sequence = 0;
	std::map<long, CPerson> m_mapMemoryStorage;
};