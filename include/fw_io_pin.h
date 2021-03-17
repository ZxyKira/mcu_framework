/* *****************************************************************************************
 *    File Name   :fw_io_pin.h
 *    Create Date :2020-08-12
 *    Modufy Date :2020-11-30
 *    Information :
 */
#ifndef fw_io_pin_H_
#define fw_io_pin_H_

#include <stdint.h>
#include <stdbool.h>
#include "fw_base.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_io_pin_api_t fw_io_pin_api_t;

/* *****************************************************************************************
 *    Function Type
 */ 

/* *****************************************************************************************
 *    Struct - fw_io_pin_handle_t
 */ 
typedef struct _fw_io_pin_handle_t{
  uint16_t port;
	uint16_t pin;
	const fw_io_pin_api_t* API;
}fw_io_pin_handle_t;

/* *****************************************************************************************
 *    Struct - fw_io_pin_api_t
 */ 
typedef struct _fw_io_pin_api_t{
  void (*setValue)  (fw_io_pin_handle_t handle, bool val);
  void (*setHigh)   (fw_io_pin_handle_t handle);
  void (*setLow)    (fw_io_pin_handle_t handle);
  void (*setToggle) (fw_io_pin_handle_t handle);  
  void (*setDir)    (fw_io_pin_handle_t handle, bool dir);
  void (*setInput)  (fw_io_pin_handle_t handle);
  void (*setOutput) (fw_io_pin_handle_t handle);
  bool (*getValue)  (fw_io_pin_handle_t handle);
  bool (*getDir)    (fw_io_pin_handle_t handle);
}fw_io_pin_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_pin_H_
/* *****************************************************************************************
 *    End of file
 */ 