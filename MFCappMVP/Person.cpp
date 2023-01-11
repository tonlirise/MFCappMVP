#include "pch.h"
#include "Person.h"

long CPerson::GetID()
{
    return m_id;
}

std::string CPerson::GetName()
{
    return m_name;
}

int CPerson::GetAge()
{
    return m_age;
}

std::string CPerson::GetAddress()
{
    return m_address;
}

void CPerson::SetID(long id)
{
    m_id = id;
}

void CPerson::SetName(std::string name)
{
    m_name = name;
}

void CPerson::SetAge(int age)
{
    m_age = age;
}

void CPerson::SetAddress(std::string address)
{
    m_address = address;
}
