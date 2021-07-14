/* *****************************************************************************************
 *    File Name   :SerialPort.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef framework_hal_SerialPort_hpp_
#define framework_hal_SerialPort_hpp_

#include "stdint.h"
#include "stdbool.h"

#include "Base.hpp"
#include "..\io\InputStream.hpp"
#include "..\io\OutputStream.hpp"


namespace framework{
	namespace hal{
		namespace SerialPort{
			
			class SerialPort : public framework::hal::Base::Base, 
												 public framework::io::InputStream::InputStream, 
												 public framework::io::OutputStream::OutputStream{
				
				
				public: virtual bool setBaudrate(int baudrate);
				public: virtual int setBaudrate(void);
				public: virtual bool setDatabit(int dataBit);
				public: virtual int getDatabit(void);
				public: virtual bool open(void);
				public: virtual void close(void);
				
				
			};
				
		}
	}
}



#endif //framework_hal_SerialPort_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
