/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/21
***********************************************************************/

#include "TestCommonHeader.h"

//////////////////////////////////////////////////////////////////////////
namespace
{
	TEST(TestAppFactory, TestApp_All)
	{
		int testKind = (int)TestApp::TIME_DEPLETION;

		for (; testKind < (int)TestApp::MAX_CASE; ++testKind)
		{
			TestApp::TestApplicationPtr testAppPtr = TestApp::TestApplicationFactory::getSingleton().
				getTestApp((TestApp::TestKind)testKind);

			EXPECT_NE((void *)NULL, testAppPtr.get())  << testKind << " test failed.";
		}
	}

	TEST(TestAppFactory, TestApp_NULL)
	{
		TestApp::TestApplicationPtr testAppPtr = TestApp::TestApplicationFactory::getSingleton().
			getTestApp(TestApp::MAX_CASE);

		EXPECT_EQ((void *)NULL, testAppPtr.get());
	}
}