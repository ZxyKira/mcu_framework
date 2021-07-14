/* *****************************************************************************************
 *    File Name   :PinEdgeTrigger.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_PinEdgeTrigger_hpp_
#define framework_hal_PinEdgeTrigger_hpp_

#include <stdbool.h>
#include <stdint.h>

#include "Base.hpp"


namespace framework{
	namespace hal{
		namespace PinEdgeTrigger{
			
			class PinEdgeTrigger : public framework::hal::Base::Base{
				public: virtual bool enableRise(void* attachment, void(*execute)(PinEdgeTrigger*, void*));
				public: virtual bool enableFall(void* attachment, void(*execute)(PinEdgeTrigger*, void*));
				public: virtual void disableRise(void);
				public: virtual void disableFall(void);
				public: virtual void disableAll(void);
			};
				
		}
	}
}



#endif //framework_hal_PinEdgeTrigger_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
