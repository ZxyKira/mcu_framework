/* *****************************************************************************************
 *    File Name   :fw_io_pin.h
 *    Create Date :2020-08-12
 *    Modufy Date :2021-04-16
 *    Information :
 */
#ifndef fw_io_pin_H_
#define fw_io_pin_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdint.h>
#include <stdbool.h>
#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_io_pin_api_t fw_io_pin_api_t;

/* *****************************************************************************************
 *    Function Type
 */ 

/* *****************************************************************************************
 *    Struct - fw_io_pin_handle_t
 */ 
typedef struct _fw_io_pin_handle_t{
  void* memory;
  const fw_io_pin_api_t* api;
  fw_pin_t pin;
}fw_io_pin_handle_t;

/* *****************************************************************************************
 *    Struct - fw_io_pin_api_t
 */ 
typedef struct _fw_io_pin_api_t{
  void (*setValue)  (fw_io_pin_handle_t* _this, bool val);
  void (*setHigh)   (fw_io_pin_handle_t* _this);
  void (*setLow)    (fw_io_pin_handle_t* _this);
  void (*setToggle) (fw_io_pin_handle_t* _this);  
  void (*setDir)    (fw_io_pin_handle_t* _this, bool dir);
  void (*setInput)  (fw_io_pin_handle_t* _this);
  void (*setOutput) (fw_io_pin_handle_t* _this);
  bool (*getValue)  (fw_io_pin_handle_t* _this);
  bool (*getDir)    (fw_io_pin_handle_t* _this);
}fw_io_pin_api_t;

/* *****************************************************************************************
 *    Macro
 */ 
#define FW_IO_PIN_API_LINK(profix, name) \
fw_io_pin_api_t name = {                 \
  .FW_API_LINK(profix, setValue),        \
	.FW_API_LINK(profix, setHigh),         \
	.FW_API_LINK(profix, setLow),          \
	.FW_API_LINK(profix, setToggle),       \
	.FW_API_LINK(profix, setDir),          \
	.FW_API_LINK(profix, setInput),        \
	.FW_API_LINK(profix, setOutput),       \
	.FW_API_LINK(profix, getValue),        \
	.FW_API_LINK(profix, getDir),          \
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_pin_H_
/* *****************************************************************************************
 *    End of file
 */ 