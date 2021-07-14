/* *****************************************************************************************
 *    File Name   :Timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_Timer_hpp_
#define framework_hal_Timer_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "Base.hpp"


namespace framework{
	namespace hal{
		namespace Timer{
			
			
			class Timer : public framework::hal::Base::Base{
				public: bool startAtTick(uint32_t tick, void* attachment,  void(execute)(Timer*, void*));
				public: bool startAtTime(uint32_t ms, void* attachment, void(execute)(Timer*, void*));
				public: void cancel(void);
				public: bool isBusy(void);
				public: int getRemaining(void);
			};
			
			
		}
	}
}



#endif //framework_hal_Timer_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
