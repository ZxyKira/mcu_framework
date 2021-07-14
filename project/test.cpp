#include "framework.h"

using namespace framework::hal::Timer;
using namespace framework::util::TimerScheduler;


void foo(){
	Timer timer = Timer();
	
	TimerScheduler timerScheduler = TimerScheduler(&timer);
	
	
}

