/* *****************************************************************************************
 *    File Name   :fw_i2c.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-14
 *    Information :
 */
 
#ifndef fw_i2c_H_
#define fw_i2c_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_i2c_api_t fw_i2c_api_t;
typedef struct _fw_i2c_handle_t fw_i2c_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_ioint_execute_t)(fw_i2c_handle_t* _this, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_ioint_handle_t
 */ 
typedef struct _fw_i2c_handle_t{
  void* memory;
  const fw_i2c_api_t* api;
}fw_i2c_handle_t;

/* *****************************************************************************************
 *    Struct - fw_ioint_api_t
 */ 
typedef struct _fw_i2c_api_t{
  bool  (*init)        (fw_i2c_handle_t* _this);
  bool  (*deinit)      (fw_i2c_handle_t* _this);
	
	
	
  struct{
    bool (*taskSchedulerEnable)   (fw_i2c_handle_t* _this, void* schedulerMemory);
    bool (*taskSchedulerDisable)  (fw_i2c_handle_t* _this);
  }support;
}fw_i2c_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_i2c_H_
/* *****************************************************************************************
 *    End of file
 */ 
