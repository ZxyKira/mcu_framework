/* *****************************************************************************************
 *    File Name   :fw_timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2020-03-16
 *    Information :
 */
 
#ifndef fw_timer_H
#define fw_timer_H

#include <stdbool.h>
#include <stdint.h>
#include "fw_base.h"

typedef struct _fw_timer_api_t fw_timer_api_t;

typedef struct _fw_timer_handle_t{
  void* memory;
  const fw_timer_api_t *API;
}fw_timer_handle_t;

typedef void (*fw_timer_execute_t)(fw_timer_handle_t handle, void* attachment);

typedef struct _fw_timer_api_t{
	bool	(*init)          (fw_timer_handle_t handle);
	bool	(*deinit)        (fw_timer_handle_t handle);
	bool  (*set)           (fw_timer_handle_t handle, fw_timer_execute_t execute, void* attachment); 
	bool  (*startAtTick)   (fw_timer_handle_t handle, uint32_t tick);
	bool  (*startAtTime)   (fw_timer_handle_t handle, uint32_t us);
	bool  (*stop)          (fw_timer_handle_t handle);
}fw_timer_api_t;

#endif
/* *****************************************************************************************
 *    End of file
 */ 
