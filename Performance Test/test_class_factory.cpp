/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/11/10
***********************************************************************/

#include "test_class_factory.h"
#include "Test.h"

namespace TestApp
{
	//---------------------------------------------------------------------
	//TestApplicationFactory
	//---------------------------------------------------------------------
	TestApplicationPtr TestApplicationFactory::getTestApp(TestKind testKind) const
	{
		switch (testKind)
		{
		case TIME_DEPLETION:
			return TestApplicationPtr(new TestApplication_TimeDepletion);
		case CYCLE_SUM_1:
			return TestApplicationPtr(new TestApplication_CycleSum1);
		case CYCLE_SUM_2:
			return TestApplicationPtr(new TestApplication_CycleSum2);
		case COMBINE_1:
			return TestApplicationPtr(new TestApplication_Combine1);
		case COMBINE_2:
			return TestApplicationPtr(new TestApplication_Combine2);
		case COMBINE_3:
			return TestApplicationPtr(new TestApplication_Combine3);
		case COMBINE_4:
			return TestApplicationPtr(new TestApplication_Combine4);
		case COMBINE_5:
			return TestApplicationPtr(new TestApplication_Combine5);
		case COMBINE_6:
			return TestApplicationPtr(new TestApplication_Combine6);
		case COMBINE_7:
			return TestApplicationPtr(new TestApplication_Combine7);
		case MIN_MAX_1:
			return TestApplicationPtr(new TestApplication_MinMax1);
		case MIN_MAX_2:
			return TestApplicationPtr(new TestApplication_MinMax2);
		case ABOUT_MEMORY_1:
			return TestApplicationPtr(new TestApplication_AboutMemory1);
		case ABOUT_MEMORY_2:
			return TestApplicationPtr(new TestApplication_AboutMemory2);
		case ABOUT_MEMORY_3:
			return TestApplicationPtr(new TestApplication_AboutMemory3);
		}

		return TestApplicationPtr();
	}
}