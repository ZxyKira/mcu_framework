/* *****************************************************************************************
 *    File Name   :fw_io_pin.h
 *    Create Date :2020-08-12
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_io_pin_h_
#define fw_io_pin_h_
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "fw_base.h"


/* *****************************************************************************************
 *    Macro
 */ 

/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_io_pin_handle_t fw_io_pin_handle_t;


/* *****************************************************************************************
 *    Typedef Function
 */ 

/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_io_pin_api_t
 *----------------------------------------*/
struct fw_io_pin_api_t{
  void (*setValue)  (fw_io_pin_handle_t* _this, bool val);
  void (*setHigh)   (fw_io_pin_handle_t* _this);
  void (*setLow)    (fw_io_pin_handle_t* _this);
  void (*setToggle) (fw_io_pin_handle_t* _this);  
  void (*setDir)    (fw_io_pin_handle_t* _this, bool dir);
  void (*setInput)  (fw_io_pin_handle_t* _this);
  void (*setOutput) (fw_io_pin_handle_t* _this);
  bool (*getValue)  (fw_io_pin_handle_t* _this);
  bool (*getDir)    (fw_io_pin_handle_t* _this);
};


/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_io_pin_handle_t
 *----------------------------------------*/
typedef struct _fw_io_pin_handle_t{
  void* memory;
  const struct fw_io_pin_api_t* api;
  fw_pin_t pin;
}fw_io_pin_handle_t;



/* *****************************************************************************************
 *    Inline Function
 */ 

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_IO_PIN_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
