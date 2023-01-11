#include "StdAfx.h"
#include <gtest/gtest.h>

namespace Middle
{
	class CPersonListTest : public testing::Test
	{
	public:
		CPersonListTest() = default;
		virtual ~CPersonListTest() = default;
	};

	TEST_F(CPersonListTest, AddButtonClickTest)
	{
		EXPECT_EQ(0, 0);
	}
}