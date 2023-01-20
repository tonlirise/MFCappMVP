#include "StdAfx.h"
#include <gtest/gtest.h>

#include "..\MFCappMVP\PersonListViewModelImpl.h"

namespace Middle
{
	class CPersonListRepositoryTestIml : public IPersonListRepository
	{
	public:
		int m_nCountSaveUser{ 0 };
		int m_nCountUpdateUser{ 0 };

		std::string m_sFindedTestName;
		int m_nFindedTestAge{ -1 };
		std::string m_sFindedTestAddress;

		CPersonListRepositoryTestIml() {};
		~CPersonListRepositoryTestIml() {};

		void SaveUser(CPerson user) { m_nCountSaveUser++; };
		CPerson GetUser(long id) { return CPerson(); };
		std::map<long, CPerson> GetAllUsers() { return std::map<long, CPerson>(); };
		CPerson FindbyName(std::string name) { return CPerson(); };
		CPerson FindbyID(long id) { return CPerson(); };
		void UpdateUser(CPerson user) { m_nCountUpdateUser++; };

	};

	class CPersonListTest : public testing::Test
	{
	public:
		CPersonListTest() = default;
		virtual ~CPersonListTest() = default;
	};

	TEST_F(CPersonListTest, SaveButtonClickTestSucces)
	{
		CPersonListRepositoryTestIml testRepository;
		CPersonListViewModelImpl personListPresenterTest(&testRepository);

		int nCountSetUserListBox{ 0 };

		auto nameUpdater = [](std::string sVal){};

		auto ageUpdater = [](int nVal){};

		auto addressUpdater = [&](std::string sVal){};

		auto userListUpdater = [&nCountSetUserListBox](std::map<long, CPerson> data)
		{
			nCountSetUserListBox++;
		};

		personListPresenterTest.UpdateObservers(nameUpdater, ageUpdater, addressUpdater, userListUpdater);

		CPerson person;
		person.SetName("Ivan");
		person.SetAge(35);
		person.SetAddress("Lenina street");

		personListPresenterTest.SaveUser(person);

		EXPECT_EQ(1, nCountSetUserListBox);
		EXPECT_EQ(1, testRepository.m_nCountSaveUser);
	}
	TEST_F(CPersonListTest, SaveButtonClickTestError)
	{
		CPersonListRepositoryTestIml testRepository;
		CPersonListViewModelImpl personListPresenterTest(&testRepository);

		int nCountSetUserListBox{ 0 };

		auto nameUpdater = [](std::string sVal){};

		auto ageUpdater = [](int nVal){};

		auto addressUpdater = [](std::string sVal){};

		auto userListUpdater = [&nCountSetUserListBox](std::map<long, CPerson> data)
		{
			nCountSetUserListBox++;
		};

		personListPresenterTest.UpdateObservers(nameUpdater, ageUpdater, addressUpdater, userListUpdater);

		CPerson person;
		person.SetAge(35);
		person.SetAddress("Lenina street");

		personListPresenterTest.SaveUser(person);

		EXPECT_EQ(1, nCountSetUserListBox);
		EXPECT_EQ(0, testRepository.m_nCountSaveUser);
	}
}