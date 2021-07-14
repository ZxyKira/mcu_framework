/* *****************************************************************************************
 *    File Name   :io.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef fw_io_hpp_
#define fw_io_hpp_

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
		namespace gpio{
			
			class GeneralPurposePin{
				
				/**
				 * Set io pin to high or low.
				 *
				 * @param value false = low, true = true.
				 */
				public: void setValue(bool value);
				
				/**
				 * Set io pin to high.
				 */
				public: void setHigh(void);
				
				/**
				 * Set io pin to low.
				 */
				public: void setLow(void);
				
				/**
				 * Set io not logic.
				 */
				public: void setToggle(void);
				
				/**
				 * Set io direction.
				 * 
				 * @param dir false = input, true = output.
				 */
				public: void setDir(bool dir);
				
				/**
				 * Set io direction to input.
				 */
				public: void setInput(void);
				
				/**
				 * Set io direction to output.
				 */
				public: void setOutput(void);
				
				/**
				 * Get io read value.
				 *
				 * @return false = low, true = high.
				 */
				public: bool getValue(void);
				
				/**
				 * Get io ditrction.
				 *
				 * @return false = input, true = output.
				 */
				public: bool getDir(void);
			};
			
			
			
			/**
			 * class FrameworkGpio
			 */
			class GeneralPurposeIO{
				/**
				 *  initialzed hardware;
				 */
				public: virtual bool init(void);
				
				/**
				 *  uninitialzed hardware.
				 */
				public: virtual bool deinit(void);
				
				/**
				 *  get hardware initialzed status.
				 * 
				 * @return false = not init, true = initd
				 */
				public: virtual bool isEnable(void);
				
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
				public: virtual GeneralPurposePin getPin(uint32_t port, uint16_t pin);
				
				/**
				 *  
				 */
				public: virtual GeneralPurposePin getPin(framework::hal::base::Pin pin);
			};			

		}
	}
}



#endif //fw_io_hpp_
/* *****************************************************************************************
 *    End of file
 */ 