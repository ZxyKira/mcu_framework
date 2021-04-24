/* *****************************************************************************************
 *    File Name   :fw_io.h
 *    Create Date :2020-08-12
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_IO_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "fw_base.h"
#include "fw_io_pin.h"



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
 *  FW_IO_REQ_FW_IO_PIN_VERSION
 *----------------------------------------*/
#define FW_IO_REQ_FW_IO_PIN_VERSION VERSION_DEFINEE(1,0,0)

#if VERSION_CHECK_COMPATIBLE(FW_IO_PIN_VERSION, FW_IO_REQ_FW_IO_PIN_VERSION)
  #if VERSION_CHECK_COMPATIBLE(FW_IO_PIN_VERSION, FW_IO_REQ_FW_IO_PIN_VERSION) == 2
      #error "FW_IO_PIN_VERSION under 1.0.x"
  #else
    #warning "FW_IO_PIN_VERSION revision under 1.0.0"
  #endif
#endif



/*----------------------------------------
 *  FW_IO_VERSION
 *----------------------------------------*/
#define FW_IO_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_IO_API_LINK
 *----------------------------------------*/
#define FW_IO_API_LINK(profix)    \
{                                 \
  .FW_API_LINK(profix, init),     \
  .FW_API_LINK(profix, deinit),   \
  .FW_API_LINK(profix, read),     \
  .FW_API_LINK(profix, set),      \
  .FW_API_LINK(profix, clear),    \
  .FW_API_LINK(profix, toggle),   \
  .FW_API_LINK(profix, dir),      \
  .FW_API_LINK(profix, dirClear), \
  .FW_API_LINK(profix, dirSet),   \
  .FW_API_LINK(profix, getPin),   \
  .FW_API_LINK(profix, getFwPin), \
}



/* *****************************************************************************************
 *    Typedef List
 */ 

typedef struct _fw_io_handle_t fw_io_handle_t;



/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_io_api_t
 *----------------------------------------*/
struct fw_io_api_t{
  bool               (*init)     (fw_io_handle_t* _this);
  bool               (*deinit)   (fw_io_handle_t* _this);
  bool               (*isEnable) (fw_io_handle_t* _this);
  uint32_t           (*read)     (fw_io_handle_t* _this, uint16_t port);
  void               (*set)      (fw_io_handle_t* _this, uint16_t port, uint32_t mask);
  void               (*clear)    (fw_io_handle_t* _this, uint16_t port, uint32_t mask);
  void               (*toggle)   (fw_io_handle_t* _this, uint16_t port, uint32_t mask);
  void               (*dir)      (fw_io_handle_t* _this, uint16_t port, uint32_t val);
  void               (*dirClear) (fw_io_handle_t* _this, uint16_t port, uint32_t mask);
  void               (*dirSet)   (fw_io_handle_t* _this, uint16_t port, uint32_t mask);
  fw_io_pin_handle_t (*getPin)   (fw_io_handle_t* _this, uint16_t port, uint16_t pin);
  fw_io_pin_handle_t (*getFwPin) (fw_io_handle_t* _this, const fw_pin_t* pin);
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_io_handle_t
 *----------------------------------------*/
typedef struct _fw_io_handle_t{
  void* memory;
  const struct fw_io_api_t* api;
}fw_io_handle_t;



/* *****************************************************************************************
 *    Inline Function
 */ 

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_IO_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
