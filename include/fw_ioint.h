/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-03-24
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
typedef void (*fw_ioint_execute_t)(fw_ioint_handle_t handle, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_ioint_handle_t
 */ 
typedef struct _fw_ioint_handle_t{
  void* const memory;
  const fw_ioint_api_t* const api;
}fw_ioint_handle_t;

/* *****************************************************************************************
 *    Struct - fw_ioint_api_t
 */ 
typedef struct _fw_ioint_api_t{
  bool  (*init)        (fw_ioint_handle_t handle);
  bool  (*deinit)      (fw_ioint_handle_t handle);
  bool  (*edgeMode)    (fw_ioint_handle_t handle, bool enable);
  bool  (*enableRise)  (fw_ioint_handle_t handle, fw_ioint_execute_t execute, void* attachment);
  bool  (*enableFall)  (fw_ioint_handle_t handle, fw_ioint_execute_t execute, void* attachment);
  bool  (*disableRise) (fw_ioint_handle_t handle);
  bool  (*disableFall) (fw_ioint_handle_t handle);
  bool  (*disableAll)  (fw_ioint_handle_t handle);
}fw_ioint_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
