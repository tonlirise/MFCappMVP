#pragma once
#include "IUserFormRepository.h"
#include <map>

class CMemoryRepository : public IUserFormRepository
{
public:

	void SaveUser(CUser user) override;
	virtual CUser GetUser(long id) override;
	virtual std::map<long, CUser> GetAllUsers() override;
	virtual CUser FindbyName(std::string name) override;
	virtual CUser FindbyID(long id) override;
	virtual void UpdateUser(CUser user) override;

private:
	long sequence = 0;
	std::map<long, CUser> m_mapMemoryStorage;
};