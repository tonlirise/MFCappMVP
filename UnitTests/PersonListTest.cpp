#include "StdAfx.h"
#include <gtest/gtest.h>

#include "..\MFCappMVP\PersonListPresenterImpl.h"

namespace Middle
{
	class CPersonListViewTestImpl : public CPersonListView
	{
	public:
		int m_nCountSetUserListBox{ 0 };

		int m_nCountNumGetName{ 0 };
		int m_nCountNumGetAge{ 0 };
		int m_nCountNumGetAddress{ 0 };

		std::string m_sTestName;
		int m_nTestAge{-1};
		std::string m_sTestAddress;

		CPersonListViewTestImpl() {};
		~CPersonListViewTestImpl() {};

		void SetUserListBox(std::map<long, CPerson> data) { m_nCountSetUserListBox++; };
		void SetName(std::string value) {};
		std::string GetName() { m_nCountNumGetName++; return m_sTestName; };
		long getSelectedUserID() { return -1; };

		void SetAge(int value) {};
		int GetAge() { m_nCountNumGetAge++; return m_nTestAge; };

		void SetAddress(std::string value) {};
		std::string GetAddress() { m_nCountNumGetAddress++; return m_sTestAddress; };

		void SetPresenter(CPersonListPresenter* presenter) {};

	};


	class CPersonListRepositoryTestIml : public CPersonListRepository
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
		CPersonListViewTestImpl testView;
		CPersonListRepositoryTestIml testRepository;

		CPersonListPresenterImpl personListPresenterTest
			= CPersonListPresenterImpl(&testView, &testRepository);

		testView.m_sTestName = "Ivan";
		testView.m_nTestAge = 35;
		testView.m_sTestAddress = "Lenina street";

		personListPresenterTest.SaveUser();

		EXPECT_EQ(1, testView.m_nCountNumGetName);
		EXPECT_EQ(1, testView.m_nCountNumGetAge);
		EXPECT_EQ(1, testView.m_nCountNumGetAddress);
		EXPECT_EQ(1, testView.m_nCountSetUserListBox);

		EXPECT_EQ(1, testRepository.m_nCountSaveUser);
	}

	TEST_F(CPersonListTest, SaveButtonClickTestError)
	{
		CPersonListViewTestImpl testView;
		CPersonListRepositoryTestIml testRepository;

		CPersonListPresenterImpl personListPresenterTest
			= CPersonListPresenterImpl(&testView, &testRepository);

		personListPresenterTest.SaveUser();

		EXPECT_EQ(1, testView.m_nCountNumGetName);
		EXPECT_EQ(1, testView.m_nCountNumGetAge);
		EXPECT_EQ(1, testView.m_nCountNumGetAddress);
		EXPECT_EQ(1, testView.m_nCountSetUserListBox);

		EXPECT_EQ(0, testRepository.m_nCountSaveUser);
	}
}