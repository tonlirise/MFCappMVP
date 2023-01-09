#include "pch.h"
#include "CMemoryRepository.h"

void CMemoryRepository::SaveUser(CUser user)
{
    ++sequence;
    user.SetID(sequence);
    m_mapMemoryStorage.insert(std::make_pair(sequence, user));
}

CUser CMemoryRepository::GetUser(long id)
{
    CUser user;

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

std::map<long, CUser> CMemoryRepository::GetAllUsers()
{
    return m_mapMemoryStorage;
}

CUser CMemoryRepository::FindbyName(std::string name)
{
    CUser user;
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

CUser CMemoryRepository::FindbyID(long id)
{
    CUser user;
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

void CMemoryRepository::UpdateUser(CUser user)
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
