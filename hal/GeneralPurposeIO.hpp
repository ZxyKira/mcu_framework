/* *****************************************************************************************
 *    File Name   :io.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_GeneralPurposeIO_hpp_
#define framework_hal_GeneralPurposeIO_hpp_

/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"
#include "Pin.hpp"
#include "GeneralPurposePin.hpp"

/* *****************************************************************************************
 *    Macro
 */ 

/* *****************************************************************************************
 *    Typedef List
 */ 

/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/* *****************************************************************************************
 *    Inline Function
 */ 

/* *****************************************************************************************
 *    Class
 */ 
namespace framework{
	namespace hal{
		namespace GeneralPurposeIO{
			
			/**
			 * class FrameworkGpio
			 */
			class GeneralPurposeIO : public framework::hal::Base::Base{
				/**
				 *  
				 * @param port GPIO port.
				 */
				public: virtual uint32_t read(uint32_t port);
				
				/**
				 *
				 * @param port GPIO port.
				 * @param value GPIO write value.
				 */
				public: virtual void set(uint32_t port, uint32_t value);
				
				/**
				 *  
				 */
				public: virtual void clear(uint32_t port, uint32_t mask);
				
				/**
				 *  
				 */
				public: virtual void toggle(uint32_t port, uint32_t mask);
				
				/**
				 *  
				 */
				public: virtual void dir(uint32_t port, uint32_t value);
				
				/**
				 *  
				 */
				public: virtual void dirClear(uint32_t port, uint32_t mask);
				
				/**
				 *  
				 */
				public: virtual void dirSet(uint32_t port, uint32_t mask);
				
				/**
				 *  
				 */
				public: virtual framework::hal::GeneralPurposePin::GeneralPurposePin getPin(uint32_t port, uint32_t pin);
				
				/**
				 *  
				 */
				public: virtual framework::hal::GeneralPurposePin::GeneralPurposePin getPin(framework::hal::Pin::Pin pin);
			};			

		}
	}
}



#endif //framework_hal_GeneralPurposeIO_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
