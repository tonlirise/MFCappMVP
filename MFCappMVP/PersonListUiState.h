#pragma once
#include "afxwin.h"

#include <string>
#include <map>

#include "Person.h"

class CPersonListUiState
{
	std::shared_ptr<std::map<long, CPerson>> m_ptrMapPersonsList;
	
	std::shared_ptr<std::string> m_ptrName;

	std::shared_ptr<long> m_ptrAge;

	std::shared_ptr<std::string> m_ptrAddress;

public:
	CPersonListUiState() = default;

	void SetPersonList(std::map<long, CPerson>* mapPersonsList)
	{
		m_ptrMapPersonsList = std::make_shared<std::map<long, CPerson>>(*mapPersonsList);
	}

	void SetName(std::string* sName)
	{
		m_ptrName = std::make_shared<std::string>(*sName);
	}

	void SetAge(long nAge)
	{
		m_ptrAge = std::make_shared<long>(nAge);
	}

	void SetAddress(std::string* sAddress)
	{
		m_ptrAddress = std::make_shared<std::string>(*sAddress);
	}

	void Apply(CListBox* pUserListBox,
		CEdit* pNameEditBox,
		CEdit* pAgeEditBox,
		CEdit* pAddressEditBox)
	{
		if (pUserListBox && m_ptrMapPersonsList)
		{
			pUserListBox->ResetContent();
			for each (auto i in *m_ptrMapPersonsList)
			{
				std::string val = i.second.GetName() + " | " + i.second.GetAddress();
				std::wstring path_wstr(val.begin(), val.end());
				pUserListBox->InsertString(-1, path_wstr.c_str());
			}
		}

		if (pNameEditBox && m_ptrName)
		{
			std::wstring wstr(m_ptrName->begin(), m_ptrName->end());
			pNameEditBox->SetWindowText(wstr.c_str());
		}

		if (pAgeEditBox && m_ptrAge)
		{
			CString str;
			str.Format(_T("%d"), *m_ptrAge);
			pAgeEditBox->SetWindowText(str);
		}

		if (pAddressEditBox && m_ptrAddress)
		{
			std::wstring wstr(m_ptrAddress->begin(), m_ptrAddress->end());
			pAddressEditBox->SetWindowText(wstr.c_str());
		}
	} 

	void ResetAllPtr()
	{
		m_ptrMapPersonsList = nullptr;
		m_ptrName = nullptr;
		m_ptrAge = nullptr;
		m_ptrAddress = nullptr;
	}
};