/**
**********************************************************************
*  Copyreight 2011 Li Suyong.
*  License MIT.
*	@defgroup PerfCount header for perfomance count
*	@author Li Suyong
*  @version 1.0
*  @date 2011/10/12
***********************************************************************
@{ */

#pragma once

#include "common.h"

namespace Profile
{
	/** Base class for profile. */
	class PERFORMANCE_TEST_API PerfCount
	{
	public:
		/// Constructor.
		PerfCount();

	public:
		/// return profile result.
		long long getPerfCount() const;
		/// begin test.
		void beginTest();
		/// end test.
		void endTest();

	protected:
		/** Destructor.
		@note The rule set it to be virtual.
		*/
		virtual ~PerfCount()
		{}

		/** virtual function for profile algorithm implementation.
		@note
			Every derived class should implement this function as thier own way.
		*/
		virtual void beginTest_impl() = 0;

		/** virtual function for profile algorithm implementation.
		@note
			Every derived class should implement this function as thier own way.
		*/
		virtual void endTest_impl() = 0;

	protected:
		/// Last stamp.
		long long mLastStamp;
		/// Current stamp.
		long long mCurrentStamp;
	};

	/** Use Windows API to get cpu clock. */
	class PERFORMANCE_TEST_API PerfCountWithWin32API : 
		public PerfCount
	{
	private:
		/// implement this function to begin test.
		virtual void beginTest_impl();
		/// implement this function to end test.
		virtual void endTest_impl();

		/// private method to call QueryPerformanceFrequency
		long long queryPerfCount(LARGE_INTEGER time) const;

	private:
		/// save begin micro time
		LARGE_INTEGER mBeginMicroTime;
		/// save end micro time
		LARGE_INTEGER mEndMicroTime;
	};

#define PROFILE(x)\
	PerfCountWithWin32API perf;\
	perf.beginTest();\
	x;\
	perf.endTest();\
	long long result = perf.getPerfCount();\
	assert(result >= 0 && "PerfCount error!");\
	printf("%I64d  %s\n", result, "¦Ìs!");

}

/** @} */