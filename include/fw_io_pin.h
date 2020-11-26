/* *****************************************************************************************
 *    File Name   :fw_io_pin.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-12
 *    Modufy Date :2020-11-26
 *    Information :
 */
#ifndef fw_io_pin_H_
#define fw_io_pin_H_

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_io_pin_api_t fw_io_pin_api_t;

/* *****************************************************************************************
 *    Struct - fw_io_pin_handle_t
 */ 
typedef struct _fw_io_pin_handle_t{
	void* memory;
	const fw_io_pin_api_t* API;
}fw_io_pin_handle_t;

/* *****************************************************************************************
 *    Struct - fw_io_pin_api_t
 */ 
typedef struct _fw_io_pin_api_t{
  void (*setValue)	(fw_io_pin_handle_t* pHandle, bool val);
  void (*setHigh)		(fw_io_pin_handle_t* pHandle);
  void (*setLow)		(fw_io_pin_handle_t* pHandle);
  void (*setToggle)	(fw_io_pin_handle_t* pHandle);  
  void (*setDir)		(fw_io_pin_handle_t* pHandle, bool dir);
  void (*setInput)	(fw_io_pin_handle_t* pHandle);
  void (*setOutput)	(fw_io_pin_handle_t* pHandle);
  bool (*getValue)	(fw_io_pin_handle_t* pHandle);
  bool (*getDir)		(fw_io_pin_handle_t* pHandle);
}fw_io_pin_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_pin_H_
/* *****************************************************************************************
 *    End of file
 */ 