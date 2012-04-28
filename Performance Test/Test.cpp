/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/12
***********************************************************************/

#include "Test.h"
#include "TestAlgorithm-inl.h"

namespace TestApp
{
	//---------------------------------------------------------------------
	//TestApplication_Interface
	//---------------------------------------------------------------------
	void TestApplication_Interface::execute()
	{
		execute_impl();
	}
	//---------------------------------------------------------------------
	//TestApplication_TimeDepletion
	//---------------------------------------------------------------------
	void TestApplication_TimeDepletion::execute_impl()
	{
		size_t testCount = 100000;
		TestAlgorithm::timeDepletion(testCount);
	}
	//---------------------------------------------------------------------
	//TestApplication_CycleSum1-2
	//---------------------------------------------------------------------
#define CYCLE_SUM_TEST_COUNT 100000

	void TestApplication_CycleSum1::execute_impl()
	{
		const size_t count = CYCLE_SUM_TEST_COUNT;
		float a[count];
		memset((void *)a, 11, sizeof(a[0]) * count);
		float b[count];

		TestAlgorithm::cycleSum1(a, b, count);
	}
	//---------------------------------------------------------------------
	void TestApplication_CycleSum2::execute_impl()
	{
		const size_t count = CYCLE_SUM_TEST_COUNT;
		float a[count];
		memset((void *)a, 11, sizeof(a[0]) * count);
		float b[count];

		TestAlgorithm::cycleSum2(a, b, count);
	}
	//---------------------------------------------------------------------
	//TestApplication_Combine1-7
	//---------------------------------------------------------------------
#define COMBINE_TEST_COUNT 1000000

	TestAlgorithm::vec_ptr gVecPtr = TestAlgorithm::createVec(COMBINE_TEST_COUNT);

	void TestApplication_Combine1::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine1(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	void TestApplication_Combine2::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine2(gVecPtr, &data);
	}

	//---------------------------------------------------------------------
	void TestApplication_Combine3::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine3(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	void TestApplication_Combine4::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine4(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	void TestApplication_Combine5::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine5(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	void TestApplication_Combine6::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine6(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	void TestApplication_Combine7::execute_impl()
	{
		IF_NULL_RETURN(gVecPtr);

		TestAlgorithm::data_t data = 1;

		TestAlgorithm::combine7(gVecPtr, &data);
	}
	//---------------------------------------------------------------------
	//TestApplication_MinMax1-2
	//---------------------------------------------------------------------
#define MINMAX_TEST_COUNT 10000000

	int a[MINMAX_TEST_COUNT];
	int b[MINMAX_TEST_COUNT];

	void TestApplication_MinMax1::execute_impl()
	{
		TestAlgorithm::minmax1(a, b, MINMAX_TEST_COUNT);
	}
	//---------------------------------------------------------------------
	void TestApplication_MinMax2::execute_impl()
	{
		TestAlgorithm::minmax2(a, b, MINMAX_TEST_COUNT);
	}
	//---------------------------------------------------------------------
	//TestApplication_AboutMemory1-2
	//---------------------------------------------------------------------
#define ABOUT_MEMORY_TEST_COUNT 800

	void TestApplication_AboutMemory1::execute_impl()
	{
		TestAlgorithm::aboutMemory1(ABOUT_MEMORY_TEST_COUNT);
	}
	//---------------------------------------------------------------------
	void TestApplication_AboutMemory2::execute_impl()
	{
		TestAlgorithm::aboutMemory2(ABOUT_MEMORY_TEST_COUNT);
	}
	//---------------------------------------------------------------------
	void TestApplication_AboutMemory3::execute_impl()
	{
		TestAlgorithm::aboutMemory3(ABOUT_MEMORY_TEST_COUNT);
	}
	//---------------------------------------------------------------------

}