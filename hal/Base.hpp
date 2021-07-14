/* *****************************************************************************************
 *    File Name   :base.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef frameworl_hal_base_hpp_
#define frameworl_hal_base_hpp_

#include <stdbool.h>
#include <stdint.h>

namespace framework{
	namespace hal{
		namespace Base{
			
			
			class Base{
				/**
				 *  initialze hardware;
				 */
				public: virtual bool init(void);
				
				/**
				 *  uninitialze hardware.
				 */
				public: virtual bool deinit(void);
				
				/**
				 *  get hardware initialzed status.
				 * 
				 * @return false = not init, true = initd
				 */
				public: virtual bool isInit(void);
			};
			
			
		}
	}
}


/* *****************************************************************************************
 *    Inline function
 */ 


#endif //frameworl_hal_base_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
