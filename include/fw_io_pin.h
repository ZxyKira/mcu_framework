/* *****************************************************************************************
 *    File Name   :fw_io_pin.h
 *    Create Date :2020-08-12
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_IO_PIN_VERSION
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

/*----------------------------------------
 *  FW_ADC_REQ_FW_ADC_CHANNEL_VERSION
 *----------------------------------------*/
#define FW_ADC_REQ_FW_BASE_VERSION VERSION_DEFINEE(1,0,0)
#if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION)
  #if VERSION_CHECK_COMPATIBLE(FW_BASE_VERSION, FW_ADC_REQ_FW_BASE_VERSION) == 2
      #error "FW_BASE_VERSION under 1.0.x"
  #else
    #warning "FW_BASE_VERSION revision under 1.0.0"
  #endif
#endif



/*----------------------------------------
 *  FW_IO_PIN_VERSION
 *----------------------------------------*/
#define FW_IO_PIN_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_IO_PIN_API_LINK
 *----------------------------------------*/
#define FW_IO_PIN_API_LINK(profix) \
{                                  \
  .FW_API_LINK(profix, setValue),  \
  .FW_API_LINK(profix, setHigh),   \
  .FW_API_LINK(profix, setLow),    \
  .FW_API_LINK(profix, setToggle), \
  .FW_API_LINK(profix, setDir),    \
  .FW_API_LINK(profix, setInput),  \
  .FW_API_LINK(profix, setOutput), \
  .FW_API_LINK(profix, getValue),  \
  .FW_API_LINK(profix, getDir),    \
}



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
