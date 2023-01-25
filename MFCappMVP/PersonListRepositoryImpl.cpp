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

bool CPersonListRepositoryImpl::SaveUser(CPerson objPerson)
{
	if (!m_pPersonsDataSource->FindbyName(objPerson.GetName()))
	{
		m_pPersonsDataSource->SaveUser(objPerson);
		return true;
	}
	return false;
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