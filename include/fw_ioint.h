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
	bool	(*init)    (fw_ioint_handle_t handle);
	bool	(*deinit)  (fw_ioint_handle_t handle);
	bool  (*edgeMode)(fw_ioint_handle_t handle, uint8_t ch, bool enable);
	bool  (*enable)  (fw_ioint_handle_t handle, uint8_t ch, fw_pin_t pin);
	bool  (*disable) (fw_ioint_handle_t handle, uint8_t);

  // --------Event--------
  struct{
    void (*setOnRise)  (fw_ioint_handle_t handle, uint8_t ch, fw_ioint_execute event, void* attachment);
    void (*setOnFall)  (fw_ioint_handle_t handle, uint8_t ch, fw_ioint_execute event, void* attachment);
  }Event;
}fw_ioint_api_t;


#endif
/* *****************************************************************************************
 *    End of file
 */ 
