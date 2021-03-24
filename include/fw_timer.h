/* *****************************************************************************************
 *    File Name   :fw_timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-03-24
 *    Information :
 */
 
#ifndef fw_timer_H
#define fw_timer_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_timer_api_t fw_timer_api_t;
typedef struct _fw_timer_handle_t fw_timer_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_timer_event_execute_t)(fw_timer_handle_t handle, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_timer_handle_t
 */ 
typedef struct _fw_timer_handle_t{
  void* memory;
  const fw_timer_api_t* api;
}fw_timer_handle_t; 
 
/* *****************************************************************************************
 *    Struct - fw_timer_api_t
 */ 
typedef struct _fw_timer_api_t{
  bool  (*init)          (fw_timer_handle_t* handle);
  bool  (*deinit)        (fw_timer_handle_t* handle);
  bool  (*startAtTick)   (fw_timer_handle_t* handle, uint32_t tick, fw_timer_event_execute_t execute, void* attachment);
  bool  (*startAtTime)   (fw_timer_handle_t* handle, uint32_t us, fw_timer_event_execute_t execute, void* attachment);
  bool  (*stop)          (fw_timer_handle_t* handle);
}fw_timer_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
