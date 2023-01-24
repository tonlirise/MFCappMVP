#pragma once

#include "IPersonListRepository.h"
#include "PersonsDataSource.h"
#include "Person.h"

#include <map>

class CPersonListRepositoryImpl : public IPersonListRepository
{
	IPersonsDataSource* m_pPersonsDataSource{ nullptr };
public:

	CPersonListRepositoryImpl(IPersonsDataSource* pPersonsDataSource);

	virtual CPerson* SelectItem(int nSelectedUserID) override;

	virtual std::map<long, CPerson> GetAllUsers() override;

	virtual void UpdateUser(CPerson objPerson) override;

	virtual void SaveUser(CPerson objPerson) override;

};