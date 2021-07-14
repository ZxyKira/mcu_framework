/* *****************************************************************************************
 *    File Name   :iic.hpp
 *    Create Date :2021-07-14
 *    Modufy Date :
 *    Information :
 */

#ifndef framework_hal_iic_hpp_
#define framework_hal_iic_hpp_


/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "base.hpp"

namespace framework{ 
	namespace hal{ 
		namespace iic{
			
			
			typedef enum {
				FRAMEWORK_HAL_IIC_SUCCESSFUL,
				FRAMEWORK_HAL_IIC_NACK,
			}InterIntegratedCircuitStatus;
			
			template <class T, class R>
			class InterIntegratedCircuitMaster : public framework::hal::base::Base{
				public: virtual void hash(T* t);
			};
			
			class TT{
			
			};
			
			
			//typedef void (*fw_i2cm_execute_t)(InterIntegratedCircuitMaster* _this, InterIntegratedCircuitStatus status, void* attachment);

			
			void foo(){
				InterIntegratedCircuitMaster<TT, TT> ff;
				ff.hash(new TT());
			}	
		}
	}
}




	
struct fw_i2cm_api_t{
  bool  (*init)        (fw_i2cm_handle_t* _this);
  bool  (*deinit)      (fw_i2cm_handle_t* _this);
  bool  (*isEnable)    (fw_i2cm_handle_t* _this);
  bool  (*write)       (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*read)        (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*isBusy)      (fw_i2cm_handle_t* _this);
};


/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_i2cm_handle_t
 *----------------------------------------*/
typedef struct _fw_i2cm_handle_t{
  void* memory;
  const struct fw_i2cm_api_t* api;
}fw_i2cm_handle_t;


/*----------------------------------------
 *  fw_i2cm_status_t
 *----------------------------------------*/

 

/*----------------------------------------
 *  fw_i2cm_xfer_t
 *----------------------------------------*/
typedef struct _fw_i2cm_xfer_t{
  fw_memory_t data;
  uint32_t baudrate;
  uint8_t address;
  uint8_t reserved[3];
}fw_i2cm_xfer_t;


/* *****************************************************************************************
 *    Inline Function
 */ 



#endif //framework_hal_iic_hpp_
/* *****************************************************************************************
 *    End of file
 */ 
