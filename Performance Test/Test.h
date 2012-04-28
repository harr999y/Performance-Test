/**
****************************************************************************
*	@defgroup Test header for test application 
*	@author Li Suyong
*	@version 1.0
*	@date 2011/10/12
*****************************************************************************
@{ */

#pragma once

#include "common.h"

/** This is the TestApp namespace. */
namespace TestApp
{
	/** Test application base class. */
	class PERFORMANCE_TEST_API TestApplication_Interface
	{
	public:
		/// do the work.
		void execute();

	protected:
		/** Destructor.
		@note The rule set it to be virtual.
		*/
		virtual ~TestApplication_Interface() {}

		/** virtual function for test algorithm implementation.
		@note
			Every derived class should implement this function as thier own way.
		*/
		virtual void execute_impl() = 0;
	};

	/** Test class : TimeDepletion. */
	class PERFORMANCE_TEST_API TestApplication_TimeDepletion :
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : CycleSum1. */
	class PERFORMANCE_TEST_API TestApplication_CycleSum1 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : CycleSum2. */
	class PERFORMANCE_TEST_API TestApplication_CycleSum2 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine1. */
	class PERFORMANCE_TEST_API TestApplication_Combine1 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine2. */
	class PERFORMANCE_TEST_API TestApplication_Combine2 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine3. */
	class PERFORMANCE_TEST_API TestApplication_Combine3 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine4. */
	class PERFORMANCE_TEST_API TestApplication_Combine4 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine5. */
	class PERFORMANCE_TEST_API TestApplication_Combine5 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine6. */
	class PERFORMANCE_TEST_API TestApplication_Combine6 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : Combine7. */
	class PERFORMANCE_TEST_API TestApplication_Combine7 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : MinMax1. */
	class PERFORMANCE_TEST_API TestApplication_MinMax1 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : MinMax2. */
	class PERFORMANCE_TEST_API TestApplication_MinMax2 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : AboutMemory1. */
	class PERFORMANCE_TEST_API TestApplication_AboutMemory1 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : AboutMemory2. */
	class PERFORMANCE_TEST_API TestApplication_AboutMemory2 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

	/** Test class : AboutMemory3. */
	class PERFORMANCE_TEST_API TestApplication_AboutMemory3 : 
		public TestApplication_Interface
	{
	private:
		/// execute implementation.
		virtual void execute_impl();
	};

}

/** @} */