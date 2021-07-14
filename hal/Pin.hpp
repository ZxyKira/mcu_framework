/* *****************************************************************************************
 *    File Name   :Pin.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_hal_Pin_hpp_
#define frameworl_hal_Pin_hpp_

#include <stdbool.h>
#include <stdint.h>

namespace framework{
	namespace hal{
		namespace Pin{
	
			typedef union {
				struct{
					uint16_t pin  :5;
					uint16_t port :11;
				}group;
				uint16_t portPin;
			}Pin;

		}
	}
}


/* *****************************************************************************************
 *    Inline function
 */ 


#endif //frameworl_hal_Pin_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
