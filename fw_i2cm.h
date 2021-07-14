/* *****************************************************************************************
 *    File Name   :fw_i2cm.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_i2cm_h_
#define fw_i2cm_h_
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"


/* *****************************************************************************************
 *    Macro
 */ 


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
#endif //fw_i2cm_h_
/* *****************************************************************************************
 *    End of file
 */ 
