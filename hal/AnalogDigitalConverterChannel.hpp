/* *****************************************************************************************
 *    File Name   :AnalogDigitalConverterChannel.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_AnalogDigitalConverterChannel_hpp_
#define framework_hal_AnalogDigitalConverterChannel_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

/* *****************************************************************************************
 *    Macro
 */ 

/* *****************************************************************************************
 *    Typedef List
 */ 

/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

namespace framework{
	namespace hal{
		namespace AnalogDigitalConverterChannel{
			
			
			class AnalogDigitalConverterChannel{
				public: virtual bool enable(void);
				public: virtual bool disable(void);
				public: virtual bool read(void);
			};	
			
			
		}
	}
}


/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 


/* *****************************************************************************************
 *    Inline Function
 */ 


#endif //framework_hal_AnalogDigitalConverterChannel_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
