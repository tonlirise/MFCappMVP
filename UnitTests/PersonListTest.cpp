#include "StdAfx.h"
#include <gtest/gtest.h>

#include "..\MFCappMVP\PersonListPresenterImpl.h"

namespace Middle
{
	class CPersonListViewTestImpl : public CPersonListView
	{
	public:
		CPersonListViewTestImpl();
		~CPersonListViewTestImpl();

		void SetUserListBox(std::map<long, CPerson> data) {};
		void SetName(std::string value) {};
		std::string GetName() {};
		long getSelectedUserID() {};

		void SetAge(int value) {};
		int GetAge() {};

		void SetAddress(std::string value) {};
		std::string GetAddress() {};

		void SetPresenter(CPersonListPresenter* presenter) {};

	};

	CPersonListViewTestImpl::CPersonListViewTestImpl(){}

	CPersonListViewTestImpl::~CPersonListViewTestImpl(){}

	class CPersonListRepositoryTestIml : public CPersonListRepository
	{
	public:
		CPersonListRepositoryTestIml();
		~CPersonListRepositoryTestIml();

		void SaveUser(CPerson user) {};
		CPerson GetUser(long id) {};
		std::map<long, CPerson> GetAllUsers() {};
		CPerson FindbyName(std::string name) {};
		CPerson FindbyID(long id) {};
		void UpdateUser(CPerson user) {};

	};

	CPersonListRepositoryTestIml::CPersonListRepositoryTestIml(){}

	CPersonListRepositoryTestIml::~CPersonListRepositoryTestIml(){}

	class CPersonListTest : public testing::Test
	{
	public:
		CPersonListTest() = default;
		virtual ~CPersonListTest() = default;
	};

	TEST_F(CPersonListTest, AddButtonClickTest)
	{
		CPersonListViewTestImpl testView;
		CPersonListRepositoryTestIml testRepository;

		CPersonListPresenterImpl m_PersonListPresenter
			= CPersonListPresenterImpl(&testView, &testRepository);

		EXPECT_EQ(0, 0);
	}
}