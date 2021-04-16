/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-16
 *    Information :
 */
 
#ifndef fw_ioint_H
#define fw_ioint_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_ioint_api_t fw_ioint_api_t;
typedef struct _fw_ioint_handle_t fw_ioint_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_ioint_execute_t)(fw_ioint_handle_t* _this, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_ioint_handle_t
 */ 
typedef struct _fw_ioint_handle_t{
  void* memory;
  const fw_ioint_api_t* api;
}fw_ioint_handle_t;

/* *****************************************************************************************
 *    Struct - fw_ioint_api_t
 */ 
typedef struct _fw_ioint_api_t{
  bool  (*init)        (fw_ioint_handle_t* _this);
  bool  (*deinit)      (fw_ioint_handle_t* _this);
  bool  (*isEnable)    (fw_ioint_handle_t* _this);
  bool  (*enableRise)  (fw_ioint_handle_t* _this, fw_ioint_execute_t execute, void* attachment);
  bool  (*enableFall)  (fw_ioint_handle_t* _this, fw_ioint_execute_t execute, void* attachment);
  bool  (*disableRise) (fw_ioint_handle_t* _this);
  bool  (*disableFall) (fw_ioint_handle_t* _this);
  bool  (*disableAll)  (fw_ioint_handle_t* _this);
  
  struct{
    struct{
      bool (*enable)   (fw_ioint_handle_t* _this, void* schedulerMemory);
      bool (*disable)  (fw_ioint_handle_t* _this);
    }taskScheduler;
  }support;
}fw_ioint_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
