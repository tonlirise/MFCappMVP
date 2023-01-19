#pragma once
#include <string>

class CPerson
{
public:

	//getter
	long GetID();
	std::string GetName();
	int GetAge();
	std::string GetAddress();

	//setter
	void SetID(long id);
	void SetName(std::string name);
	void SetAge(int age);
	void SetAddress(std::string address);

private:
	long m_id{-1};
	std::string m_name;
	int m_age{-1};
	std::string m_address;
};
