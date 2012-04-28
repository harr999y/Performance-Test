/**
****************************************************************************
*	@author Li Suyong
*	@version 1.0
*	@date 2011/11/10
*****************************************************************************
@{ */

#ifndef TEST_CLASS_FACTORY_H_
#define TEST_CLASS_FACTORY_H_

#include "common.h"
#include "CommonClasses-inl.h"
#include "ForwardDeclarations.h"

namespace TestApp
{
	/** Define the test kinds. */
	typedef enum TestKind
	{
		TIME_DEPLETION,  /**< TIME_DEPLETION. */
		CYCLE_SUM_1,		    /**< CYCLE_SUM_1 */
		CYCLE_SUM_2,			/**< CYCLE_SUM_2 */
		COMBINE_1,				/**< COMBINE_1 */
		COMBINE_2,				/**< COMBINE_2 */
		COMBINE_3,				/**< COMBINE_3 */	
		COMBINE_4,				/**< COMBINE_4 */
		COMBINE_5,				/**< COMBINE_5 */
		COMBINE_6,				/**< COMBINE_6 */
		COMBINE_7,				/**< COMBINE_7 */
		MIN_MAX_1,			/**< MIN_MAX_1 */
		MIN_MAX_2,			/**< MIN_MAX_2 */
		ABOUT_MEMORY_1,  /**< ABOUT_MEMORY_1 */
		ABOUT_MEMORY_2,  /**< ABOUT_MEMORY_2 */
		ABOUT_MEMORY_3,  /**< ABOUT_MEMORY_3 */
		MAX_CASE               /**< Max kinds num. */
	};

	/** Type for shared_ptr. */
	typedef std::tr1::shared_ptr<TestApplication_Interface> TestApplicationPtr;

	/** The test application implementation factory. */
	class PERFORMANCE_TEST_API TestApplicationFactory :
		public CommonClasses::Singleton<TestApplicationFactory>
	{
		/**
		@note 
		    I really don't want to add this to friend,but as u know,I have no choice.
		*/
		friend class CommonClasses::Singleton<TestApplicationFactory>;

	public:
		/** This is the factory method to create app which kind is needed.
		@remark It has many ways to implement.
		*/
		TestApplicationPtr getTestApp(TestKind testKind) const;

	private:
		/// Private constructor
		TestApplicationFactory() {}

		DISALLOW_COPY_AND_ASSIGN(TestApplicationFactory);
	};
}

#endif
/** @} */