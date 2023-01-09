#include "pch.h"
#include "CUser.h"

long CUser::GetID()
{
    return m_id;
}

std::string CUser::GetName()
{
    return m_name;
}

int CUser::GetAge()
{
    return m_age;
}

std::string CUser::GetAddress()
{
    return m_address;
}

void CUser::SetID(long id)
{
    m_id = id;
}

void CUser::SetName(std::string name)
{
    m_name = name;
}

void CUser::SetAge(int age)
{
    m_age = age;
}

void CUser::SetAddress(std::string address)
{
    m_address = address;
}
