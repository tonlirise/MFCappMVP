#pragma once
#include "afxwin.h"

#include <string>
#include <map>

#include "Person.h"

class CPersonListUiState
{
	bool m_bChangedPersonList{ false };
	std::map<long, CPerson> m_mapPersonsList;

	bool m_bChangedName{ false };
	std::string m_sName;

	bool m_bChangedAge{ false };
	long m_nAge{ -1 };

	bool m_bChangedAddress{ false };
	std::string m_sAddress;

public:
	CPersonListUiState() = default;

	void SetPersonList(std::map<long, CPerson> mapPersonsList)
	{
		m_bChangedPersonList = true;
		m_mapPersonsList = mapPersonsList;
	}

	void SetName(std::string sName)
	{
		m_bChangedName = true;
		m_sName = sName;
	}

	void SetAge(long nAge)
	{
		m_bChangedAge = true;
		m_nAge = nAge;
	}

	void SetAddress(std::string sAddress)
	{
		m_bChangedAddress = true;
		m_sAddress = sAddress;
	}

	void Apply(CListBox* pUserListBox, 
		CEdit* pNameEditBox,
		CEdit* pAgeEditBox, 
		CEdit* pAddressEditBox)
	{
		if (pUserListBox && m_bChangedPersonList)
		{
			pUserListBox->ResetContent();
			for each (auto i in m_mapPersonsList)
			{
				std::string val = i.second.GetName() + " | " + i.second.GetAddress();
				std::wstring path_wstr(val.begin(), val.end());
				pUserListBox->InsertString(-1, path_wstr.c_str());
			}
		}

		if (pNameEditBox && m_bChangedName)
		{
			std::wstring wstr(m_sName.begin(), m_sName.end());
			pNameEditBox->SetWindowText(wstr.c_str());
		}

		if (pAgeEditBox && m_bChangedAge)
		{
			CString str;
			str.Format(_T("%d"), m_nAge);
			pAgeEditBox->SetWindowText(str);
		}

		if (pAddressEditBox && m_bChangedAddress)
		{
			std::wstring wstr(m_sAddress.begin(), m_sAddress.end());
			pAddressEditBox->SetWindowText(wstr.c_str());
		}
	}

	void ClearAllChangedMask()
	{
		m_bChangedPersonList = false;
		m_bChangedName = false;
		m_bChangedAge = false;
		m_bChangedAddress = false;
	}
};