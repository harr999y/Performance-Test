/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/21
***********************************************************************/

#include "TestCommonHeader.h"

//////////////////////////////////////////////////////////////////////////
namespace
{
	TEST(TestApps, Test_All)
	{
		int testKind = (int)TestApp::TIME_DEPLETION;

		for (; testKind < (int)TestApp::MAX_CASE; ++testKind)
		{
			TestApp::TestApplicationPtr testAppPtr = TestApp::TestApplicationFactory::getSingleton().
				getTestApp((TestApp::TestKind)testKind);

			Profile::PerfCountWithWin32API perfCount;
			{
				perfCount.beginTest();
				testAppPtr->execute	();
				perfCount.endTest();
			}

			EXPECT_GE(perfCount.getPerfCount(), 1) << testKind << " test failed." << " And unit is micro second";
		}
	}

}