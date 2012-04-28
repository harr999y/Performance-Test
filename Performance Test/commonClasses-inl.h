/**
**********************************************************************
*	@addtogroup CommonHeader
***********************************************************************
@{ */

#pragma once

#include "common.h"

namespace CommonClasses
{
	/** The common singleton class. */
	template <class T> class Singleton
	{
	public:
		/// return singletonPtr.
	    static T * getSingletonPtr()
		{
			static T instance;
			return &instance;
		}
		/// return singleton.
		static T & getSingleton()
		{
			return *getSingletonPtr();
		}

	protected:
		/// Constructor
		Singleton() {}

	private:		
		DISALLOW_COPY_AND_ASSIGN(Singleton);
	};

}
/** @} */