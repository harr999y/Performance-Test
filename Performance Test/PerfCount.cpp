/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/12
***********************************************************************/

#include "PerfCount.h"

namespace Profile
{
	//---------------------------------------------------------------------
	//PerfCount
	//---------------------------------------------------------------------
	PerfCount::PerfCount()
		: mLastStamp(0),
		  mCurrentStamp(0)
	{}
	//---------------------------------------------------------------------
	void PerfCount::beginTest()
	{
		// set highest thread ptiority to get more precise time.
		SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

		beginTest_impl();
	}
	//---------------------------------------------------------------------
	void PerfCount::endTest()
	{	
		endTest_impl();

		// set thread ptiority back to normal.
		SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
	}
	//---------------------------------------------------------------------
	long long PerfCount::getPerfCount() const
	{
		return mCurrentStamp - mLastStamp;
	}

	//---------------------------------------------------------------------
	//PerfCountWithWin32API
	//---------------------------------------------------------------------
	void PerfCountWithWin32API::beginTest_impl()
	{
		LARGE_INTEGER beginTime;
		PROCESS_WIN_ERROR(QueryPerformanceCounter(&beginTime));

		mLastStamp = queryPerfCount(beginTime);
	}
	//---------------------------------------------------------------------
	void PerfCountWithWin32API::endTest_impl()
	{
		LARGE_INTEGER endTime;
		PROCESS_WIN_ERROR(QueryPerformanceCounter(&endTime));

		mCurrentStamp = queryPerfCount(endTime);
	}
	//---------------------------------------------------------------------
	/** The time factor. */
#define TF_MICRO 1000000
#define TF_MILLION 1000

	long long PerfCountWithWin32API::queryPerfCount(LARGE_INTEGER time) const
	{
		LARGE_INTEGER perfFreq;
		PROCESS_WIN_ERROR(QueryPerformanceFrequency(&perfFreq));

		return ((time.QuadPart * TF_MICRO) / perfFreq.QuadPart);
	}
}

