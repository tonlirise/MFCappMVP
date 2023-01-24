#include "stdafx.h"

#include "PersonListRepositoryImpl.h"

CPersonListRepositoryImpl::CPersonListRepositoryImpl(IPersonsDataSource* pPersonsDataSource)
{
	m_pPersonsDataSource = pPersonsDataSource;
}

CPerson* CPersonListRepositoryImpl::SelectItem(int nSelectedUserID)
{
	return m_pPersonsDataSource->FindbyID(nSelectedUserID);
}

void CPersonListRepositoryImpl::SaveUser(CPerson objPerson)
{
	m_pPersonsDataSource->SaveUser(objPerson);
}

std::map<long, CPerson> CPersonListRepositoryImpl::GetAllUsers()
{
	return m_pPersonsDataSource->GetAllUsers();
}

void CPersonListRepositoryImpl::UpdateUser(CPerson objPerson)
{
	if (auto tmpPers = m_pPersonsDataSource->FindbyName(objPerson.GetName()))
	{
		objPerson.SetID(tmpPers->GetID());
		m_pPersonsDataSource->UpdateUser(objPerson);
	}
	else
		m_pPersonsDataSource->SaveUser(objPerson);
}