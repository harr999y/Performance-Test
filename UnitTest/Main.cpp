/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/18
***********************************************************************/
#include "TestCommonHeader.h"

int main(int argc, char * argv)
{
	// Test settings.
	{
		testing::GTEST_FLAG(repeat) = 1;
		testing::GTEST_FLAG(output) = "xml:result.xml";
		testing::GTEST_FLAG(catch_exceptions) = 0;
	}

	testing::InitGoogleTest(&argc, &argv);
	return RUN_ALL_TESTS();
}