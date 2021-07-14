/* *****************************************************************************************
 *    File Name   :OutputStream.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_io_OutputStream_hpp_
#define framework_io_OutputStream_hpp_

#include <stdbool.h>
#include <stdint.h>

namespace framework{
	namespace io{
		namespace OutputStream{
			
			
			class OutputStream{
				public: virtual void flush(void);
				public: virtual int write(void* data, int length);
				public: virtual int write(void* data, int lengthl, void* attachment, void(*execute)(OutputStream*, void*));
				
			};
		
			
		}
	}
}



#endif //framework_io_OutputStream_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
