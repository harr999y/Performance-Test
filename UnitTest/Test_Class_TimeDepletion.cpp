/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/19
***********************************************************************/

#include "TestCommonHeader.h"

//////////////////////////////////////////////////////////////////////////
namespace
{
	bool perfCountTestWarp(size_t count)
	{
		Profile::PerfCountWithWin32API perfCount;
		perfCount.beginTest();
		{
			TestAlgorithm::timeDepletion(count);
		}
		perfCount.endTest();

		return perfCount.getPerfCount() >= 0;
	}

	//////////////////////////////////////////////////////////////////////////

	class PerfCountTestWithParam : public testing::TestWithParam<std::tr1::tuple<size_t, size_t, size_t>> 
	{};

	TEST_P(PerfCountTestWithParam, PerCount1)
	{	
		size_t testCount = std::tr1::get<0>(GetParam());

		EXPECT_PRED1(perfCountTestWarp, testCount);
	}

	TEST_P(PerfCountTestWithParam, PerCount2)
	{
		size_t testCount = std::tr1::get<1>(GetParam());

		EXPECT_PRED1(perfCountTestWarp, testCount);
	}

	TEST_P(PerfCountTestWithParam, PerCount3)
	{	
		size_t testCount = std::tr1::get<2>(GetParam());

		EXPECT_PRED1(perfCountTestWarp, testCount);
	}

	INSTANTIATE_TEST_CASE_P(TestPerfCountParameters,
		PerfCountTestWithParam,
		testing::Combine(testing::Values(100, 200, 100000),
		testing::Values(100, 200, 100000),
		testing::Values(100, 200, 1000000)));

	//////////////////////////////////////////////////////////////////////////

	class PerfCountTestWithParam2 : public testing::TestWithParam<int>
	{};

	TEST_P(PerfCountTestWithParam2, PerfCount4)
	{
		size_t testCount = GetParam();

		EXPECT_PRED1(perfCountTestWarp, testCount);
	}

	INSTANTIATE_TEST_CASE_P(TestPerfCountParameters2,
		PerfCountTestWithParam2,
		testing::Range(10000, 100000, 20));

}

//////////////////////////////////////////////////////////////////////////
