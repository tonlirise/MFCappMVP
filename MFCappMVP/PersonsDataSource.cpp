#include "stdafx.h"

#include "PersonsDataSource.h"

void CPersonsDataSourceImpl::SaveUser(CPerson user)
{
	++sequence;
	user.SetID(sequence);
	m_mapMemoryStorage.insert(std::make_pair(sequence, user));
}

std::map<long, CPerson> CPersonsDataSourceImpl::GetAllUsers()
{
	return m_mapMemoryStorage;
}

CPerson* CPersonsDataSourceImpl::FindbyName(std::string name)
{
	CPerson* user = nullptr;
	for each (auto i in m_mapMemoryStorage)
	{
		if (i.second.GetName() == name)
		{
			user = new CPerson();
			user->SetID(i.second.GetID());
			user->SetName(i.second.GetName());
			user->SetAge(i.second.GetAge());
			user->SetAddress(i.second.GetAddress());
		}
	}
	return user;
}

CPerson* CPersonsDataSourceImpl::FindbyID(long id)
{
	CPerson* user = nullptr;
	for each (auto i in m_mapMemoryStorage)
	{
		if (i.first == id)
		{
			user = new CPerson();
			user->SetID(i.first);
			user->SetName(i.second.GetName());
			user->SetAge(i.second.GetAge());
			user->SetAddress(i.second.GetAddress());
		}
	}
	return user;
}

void CPersonsDataSourceImpl::UpdateUser(CPerson user)
{
	for each (auto i in m_mapMemoryStorage)
	{
		if (i.first == user.GetID())
		{
			m_mapMemoryStorage[i.first] = user;
			break;
		}
	}
}