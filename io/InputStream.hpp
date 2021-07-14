/* *****************************************************************************************
 *    File Name   :InputStream.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_io_InputStream_hpp_
#define framework_io_InputStream_hpp_

#include <stdbool.h>
#include <stdint.h>

namespace framework{
	namespace io{
		namespace InputStream{
			
			
			class InputStream{
				public: virtual int available(void);
				public: virtual int read(void* data, int length);
				public: virtual int read(void* data, int lengthl, void* attachment, void(*execute)(InputStream*, void*));
				public: virtual int skip(int skip);
				
			};
		
			
		}
	}
}



#endif //framework_io_InputStream_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
