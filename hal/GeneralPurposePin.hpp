/* *****************************************************************************************
 *    File Name   :GeneralPurposePin.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_GeneralPurposePin_hpp_
#define framework_hal_GeneralPurposePin_hpp_

/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "Base.hpp"

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
		namespace GeneralPurposePin{
			
			
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
			
			
		}
	}
}



#endif //framework_hal_GeneralPurposePin_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
