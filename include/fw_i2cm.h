/* *****************************************************************************************
 *    File Name   :fw_i2cm.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-24
 *    Information :
 */

#ifndef FW_I2CM_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"
#include "version.h"



/* *****************************************************************************************
 *    Macro
 */ 

/*----------------------------------------
 *  FW_ADC_REQ_FW_ADC_CHANNEL_VERSION
 *----------------------------------------*/
#define FW_ADC_REQ_FW_BASE_VERSION VERSION_DEFINEE(1,0,0)
#if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION)
  #if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION) == 2
      #error "FW_BASE_VERSION under 1.0.x"
  #else
    #warning "FW_BASE_VERSION revision under 1.0.0"
  #endif
#endif



/*----------------------------------------
 *  FW_I2CM_VERSION
 *----------------------------------------*/
#define FW_I2CM_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_I2CM_API_LINK
 *----------------------------------------*/
#define FW_I2CM_API_LINK(profix)   \
{                                  \
  .FW_API_LINK(profix, init),      \
  .FW_API_LINK(profix, deinit),    \
  .FW_API_LINK(profix, isEnable),  \
  .FW_API_LINK(profix, write),     \
  .FW_API_LINK(profix, read),      \
  .FW_API_LINK(profix, isBusy),    \
  .support = {                     \
    .taskScheduler = FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix), \
    .fifo = FW_SUPPORT_FIFO_API_LINK(profix),                    \
  }                                                              \
}



/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_i2cm_handle_t fw_i2cm_handle_t;
typedef struct _fw_i2cm_xfer_t fw_i2cm_xfer_t;
typedef enum _fw_i2cm_status_t fw_i2cm_status_t;



/* *****************************************************************************************
 *    Typedef Function
 */ 

/*----------------------------------------
 *  fw_i2cm_execute_t
 *----------------------------------------*/
typedef void (*fw_i2cm_execute_t)(fw_i2cm_handle_t* _this, fw_i2cm_status_t status, fw_i2cm_xfer_t* xfer ,void* attachment);



/* *****************************************************************************************
 *    Struct/Union/Enum
 */

/*----------------------------------------
 *  fw_i2cm_api_t
 *----------------------------------------*/
struct fw_i2cm_api_t{
  bool  (*init)        (fw_i2cm_handle_t* _this);
  bool  (*deinit)      (fw_i2cm_handle_t* _this);
  bool  (*isEnable)    (fw_i2cm_handle_t* _this);
  bool  (*write)       (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*read)        (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*isBusy)      (fw_i2cm_handle_t* _this);
  
  struct{
    FW_STRUCT_TASK_SCHEDULER(fw_i2cm_handle_t*) taskScheduler;
    FW_STRUCT_FIFO(fw_i2cm_handle_t*) fifo;
  }support;
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
typedef enum _fw_i2cm_status_t{
  fw_i2cm_status_successful,
  fw_i2cm_status_nack,
}fw_i2cm_status_t;
 


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



#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_I2CM_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
