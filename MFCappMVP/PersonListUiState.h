#pragma once
#include "afxwin.h"

#include <string>
#include <map>

#include "Person.h"

class IPersonListUiState
{
public:
	virtual void Apply(CListBox* pUserListBox
		, CEdit* pNameEditBox
		, CEdit* pAgeEditBox
		, CEdit* pAddressEditBox) = 0;
};


class CPersonListUiStateMain : public IPersonListUiState
{
	std::shared_ptr<std::map<long, CPerson>> m_ptrMapPersonsList;
	
	std::shared_ptr<std::string> m_ptrName;

	std::shared_ptr<long> m_ptrAge;

	std::shared_ptr<std::string> m_ptrAddress;

public:
	CPersonListUiStateMain() = default;
	
#define SETTER(name) \
void Set##name##(const decltype(m_ptr##name##)::element_type &val){ \
m_ptr##name## = std::make_shared<decltype(m_ptr##name##)::element_type>(val);\
}; 

	SETTER(MapPersonsList);
	SETTER(Name);
	SETTER(Age);
	SETTER(Address);

#undef SETTER

	virtual void Apply(CListBox* pUserListBox,
		CEdit* pNameEditBox,
		CEdit* pAgeEditBox,
		CEdit* pAddressEditBox) override
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

class CPersonListUiStateShowMessage : public IPersonListUiState
{
	std::string m_sValue;
public:
	CPersonListUiStateShowMessage(std::string sValue) 
	{
		m_sValue = sValue;
	}

	virtual void Apply(CListBox* pUserListBox,
		CEdit* pNameEditBox,
		CEdit* pAgeEditBox,
		CEdit* pAddressEditBox) override 
	{
		std::wstring sda(m_sValue.begin(), m_sValue.end());
		pUserListBox->MessageBox(sda.c_str(), nullptr, MB_OK);
	}
};
