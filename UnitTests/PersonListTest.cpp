#include "StdAfx.h"
#include <gtest/gtest.h>

#include "..\MFCappMVP\PersonListPresenterImpl.h"

namespace Middle
{
	class CPersonListViewTestImpl : public IPersonListView
	{
	public:
		int m_nCountSetUserListBox{ 0 };

		std::string m_sTestName;
		int m_nTestAge{-1};
		std::string m_sTestAddress;

		CPersonListViewTestImpl() {};
		~CPersonListViewTestImpl() {};

		void SetUserListBox(std::map<long, CPerson> data) { m_nCountSetUserListBox++; };
		void SetName(std::string value) {};
		std::string GetName() { return m_sTestName; };
		long getSelectedUserID() { return -1; };

		void SetAge(int value) {};
		int GetAge() { return m_nTestAge; };

		void SetAddress(std::string value) {};
		std::string GetAddress() { return m_sTestAddress; };

		void SetPresenter(IPersonListPresenter* presenter) {};

	};


	class CPersonListRepositoryTestIml : public IPersonListRepository
	{
	public:
		int m_nCountSaveUser{ 0 };
		int m_nCountUpdateUser{ 0 };

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
		CPersonListViewTestImpl testView;
		CPersonListRepositoryTestIml testRepository;

		CPersonListPresenterImpl personListPresenterTest
			= CPersonListPresenterImpl(&testView, &testRepository);

		CPerson uiPerson;
		uiPerson.SetName("Ivan");
		uiPerson.SetAge(35);
		uiPerson.SetAddress("Ivan");

		personListPresenterTest.SaveUser(uiPerson);

		EXPECT_EQ(1, testView.m_nCountSetUserListBox);
		EXPECT_EQ(1, testRepository.m_nCountSaveUser);
	}

	TEST_F(CPersonListTest, SaveButtonClickTestError)
	{
		CPersonListViewTestImpl testView;
		CPersonListRepositoryTestIml testRepository;

		CPersonListPresenterImpl personListPresenterTest
			= CPersonListPresenterImpl(&testView, &testRepository);

		CPerson uiPerson;
		personListPresenterTest.SaveUser(uiPerson);
		uiPerson.SetAge(35);
		uiPerson.SetAddress("Ivan");

		EXPECT_EQ(1, testView.m_nCountSetUserListBox);
		EXPECT_EQ(0, testRepository.m_nCountSaveUser);
	}
}