#include "pch.h"

#include "CPersonListRepositoryImpl.h"

void CPersonListRepositoryImpl::SaveUser(CPerson user)
{
    ++sequence;
    user.SetID(sequence);
    m_mapMemoryStorage.insert(std::make_pair(sequence, user));
}

CPerson CPersonListRepositoryImpl::GetUser(long id)
{
    CPerson user;

    for each (auto i in m_mapMemoryStorage)
    {
        if (id == i.first)
        {
            user.SetID(i.first);
            user.SetName(i.second.GetName());
            user.SetAge(i.second.GetAge());
            user.SetAddress(i.second.GetAddress());

            return i.second;
        }
    }
    return user;
}

std::map<long, CPerson> CPersonListRepositoryImpl::GetAllUsers()
{
    return m_mapMemoryStorage;
}

CPerson CPersonListRepositoryImpl::FindbyName(std::string name)
{
    CPerson user;
    for each (auto i in m_mapMemoryStorage)
    {
        if (i.second.GetName() == name)
        {
            user.SetID(i.second.GetID());
            user.SetName(i.second.GetName());
            user.SetAge(i.second.GetAge());
            user.SetAddress(i.second.GetAddress());
        }
    }
    return user;
}

CPerson CPersonListRepositoryImpl::FindbyID(long id)
{
    CPerson user;
    for each (auto i in m_mapMemoryStorage)
    {
        if (i.first == id)
        {
            user.SetID(i.first);
            user.SetName(i.second.GetName());
            user.SetAge(i.second.GetAge());
            user.SetAddress(i.second.GetAddress());
        }
    }
    return user;
}

void CPersonListRepositoryImpl::UpdateUser(CPerson user)
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