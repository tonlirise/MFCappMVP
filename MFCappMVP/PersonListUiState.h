#pragma once
#include "afxwin.h"

#include <string>
#include <map>

#include "Person.h"

class CPersonListUiState
{
	std::map<long, CPerson> m_mapPersonsList;
	std::string m_sName;
	long m_nAge;
	std::string m_sAddress;

public:
	CPersonListUiState(
		std::map<long, CPerson> mapPersonsList = std::map<long, CPerson>()
		, std::string sName = "",
		long nAge = -1,
		std::string sAddress = "")
	{
		m_mapPersonsList = mapPersonsList;
		m_sName = sName;
		m_nAge = nAge;
		m_sAddress = sAddress;
	};

	void Apply(CListBox* pUserListBox, 
		CEdit* pNameEditBox,
		CEdit* pAgeEditBox, 
		CEdit* pAddressEditBox)
	{
		if (pUserListBox)
		{
			pUserListBox->ResetContent();
			for each (auto i in m_mapPersonsList)
			{
				std::string val = i.second.GetName() + " | " + i.second.GetAddress();
				std::wstring path_wstr(val.begin(), val.end());
				pUserListBox->InsertString(-1, path_wstr.c_str());
			}
		}

		if (pNameEditBox)
		{
			std::wstring wstr(m_sName.begin(), m_sName.end());
			pNameEditBox->SetWindowText(wstr.c_str());
		}

		if (pAgeEditBox)
		{
			CString str;
			str.Format(_T("%d"), m_nAge);
			pAgeEditBox->SetWindowText(str);
		}

		if (pAddressEditBox)
		{
			std::wstring wstr(m_sAddress.begin(), m_sAddress.end());
			pAddressEditBox->SetWindowText(wstr.c_str());
		}
	}
};