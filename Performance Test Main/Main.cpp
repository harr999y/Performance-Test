/**********************************************************************
	*	@author Li Suyong
	*  @version 1.0
	*  @date 2011/10/12
***********************************************************************/

#include <string>
#include <iostream>

#include "PerformanceTest.h"

int main()
{
	// this thread can only run on cpu 4.
	SetThreadAffinityMask(GetCurrentThread(), 0x00000008);

	std::string input;
	while (std::cin >> input)
	{
		TestApp::TestApplicationPtr testApp;
		testApp = TestApp::TestApplicationFactory::getSingleton()
			.getTestApp(static_cast<TestApp::TestKind>(atoi(input.c_str())));

		IF_NULL_CONTINUE(testApp.get());

		Profile::PROFILE(testApp->execute());
	}

	return 0;
}