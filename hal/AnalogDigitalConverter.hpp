/* *****************************************************************************************
 *    File Name   :AnalogDigitalConverter.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_AnalogDigitalConverter_hpp_
#define framework_hal_AnalogDigitalConverter_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"
#include "AnalogDigitalConverterChannel.hpp"

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
		namespace AnalogDigitalConverter{
			
			
			class AnalogDigitalConverter : public framework::hal::Base::Base{
				public: virtual bool enableChannel(uint32_t channel);
				public: virtual bool disableChannel(uint32_t channel);
				public: virtual uint32_t read(uint32_t channel);
				public: virtual framework::hal::AnalogDigitalConverterChannel::AnalogDigitalConverterChannel getChannel(uint32_t channel);
			};
			
			
		}
	}
}



#endif //fw_adc_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
