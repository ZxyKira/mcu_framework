/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2020-03-16
 *    Information :
 */
 
#ifndef fw_ioint_H
#define fw_ioint_H

#include <stdbool.h>
#include <stdint.h>
#include "fw_base.h"

typedef struct _fw_ioint_api_t fw_ioint_api_t;

typedef void (*fw_ioint_execute)(void* userData);

typedef struct _fw_ioint_handle_t{
  void* memory;
  const fw_ioint_api_t *API;
}fw_ioint_handle_t;

typedef struct _fw_ioint_api_t{
	bool	(*init)        (fw_ioint_handle_t handle);
	bool	(*deinit)      (fw_ioint_handle_t handle);
	bool  (*edgeMode)    (fw_ioint_handle_t handle, bool enable);
	bool  (*enableRise)  (fw_ioint_handle_t handle, fw_ioint_execute execute, void* attachment);
	bool  (*enableFall)  (fw_ioint_handle_t handle, fw_ioint_execute execute, void* attachment);
	bool  (*disableRise) (fw_ioint_handle_t handle);
	bool  (*disableFall) (fw_ioint_handle_t handle);
	bool  (*disableAll)  (fw_ioint_handle_t handle);
}fw_ioint_api_t;


#endif
/* *****************************************************************************************
 *    End of file
 */ 
