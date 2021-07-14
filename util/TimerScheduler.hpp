/* *****************************************************************************************
 *    File Name   :TimerScheduler.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_util_TimerScheduler_hpp_
#define framework_util_TimerScheduler_hpp_

#include "..\hal\timer.hpp"

namespace framework{
	namespace util{
		namespace TimerScheduler{

			
			class TimerScheduler{
				private: framework::hal::Timer::Timer* timer;
				
				public:
					TimerScheduler(framework::hal::Timer::Timer* timer){
						this->timer = timer;
					}
				
			};
			
		}
	}
}

 
 
#endif //framework_util_TimerScheduler_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
