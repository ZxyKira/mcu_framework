/* *****************************************************************************************
 *    File Name   :fw_adc.hpp
 *    Create Date :2021-07-01
 *    Modufy Date :
 *    Information :
 */

#ifndef fw_adc_hpp_
#define fw_adc_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "base.hpp"

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
		namespace adc{
			
			class AnalogDigitalConverterChannel{
				public: virtual bool enable(void);
				public: virtual bool disable(void);
				public: virtual bool read(void);
			};
			
			
			class AnalogDigitalConverter : public framework::hal::base::Base{
				public: virtual bool enableChannel(uint32_t channel);
				public: virtual bool disableChannel(uint32_t channel);
				public: virtual uint32_t read(uint32_t channel);
				public: virtual AnalogDigitalConverterChannel getChannel(uint32_t channel);
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


#endif //fw_adc_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
