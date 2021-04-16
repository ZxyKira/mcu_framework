/* *****************************************************************************************
 *    File Name   :fw_i2cm.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-16
 *    Information :
 */
 
#ifndef fw_i2cm_H_
#define fw_i2cm_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_i2cm_api_t fw_i2cm_api_t;
typedef struct _fw_i2cm_handle_t fw_i2cm_handle_t;
typedef enum _fw_i2cm_status_t fw_i2cm_status_t;
typedef struct _fw_i2cm_xfer_t fw_i2cm_xfer_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_i2cm_execute_t)(fw_i2cm_handle_t* _this, fw_i2cm_status_t status, fw_i2cm_xfer_t* xfer ,void* attachment);

/* *****************************************************************************************
 *    Struct - fw_ioint_handle_t
 */ 
typedef enum _fw_i2cm_status_t{
  fw_i2cm_status_successful,
  fw_i2cm_status_nack,
}fw_i2cm_status_t;
 
typedef struct _fw_i2cm_handle_t{
  void* memory;
  const fw_i2cm_api_t* api;
}fw_i2cm_handle_t;

typedef struct _fw_i2cm_xfer_t{
  fw_memory_t data;
  uint32_t baudrate;
  uint8_t address;
  uint8_t reserved[3];
}fw_i2cm_xfer_t;

/* *****************************************************************************************
 *    Struct - fw_ioint_api_t
 */ 
typedef struct _fw_i2cm_api_t{
  bool  (*init)        (fw_i2cm_handle_t* _this);
  bool  (*deinit)      (fw_i2cm_handle_t* _this);
  bool  (*isEnable)    (fw_i2cm_handle_t* _this);
  bool  (*write)       (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*read)        (fw_i2cm_handle_t* _this, fw_i2cm_xfer_t* xfer, fw_i2cm_execute_t execute, void* attachment);
  bool  (*isBusy)      (fw_i2cm_handle_t* _this);
	
  struct{
    struct{
      bool (*enable)   (fw_i2cm_handle_t* _this, void* schedulerMemory);
      bool (*disable)  (fw_i2cm_handle_t* _this);
    }taskScheduler;
    struct{
      bool (*enable)   (fw_i2cm_handle_t* _this, void* buffer, uint32_t bufferSize);
      bool (*disable)  (fw_i2cm_handle_t* _this);
    }fifo;
  }support;
}fw_i2cm_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_i2cm_H_
/* *****************************************************************************************
 *    End of file
 */ 
