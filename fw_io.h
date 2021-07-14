/* *****************************************************************************************
 *    File Name   :fw_io.h
 *    Create Date :2020-08-12
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_io_h_
#define fw_io_h_
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
#endif //fw_io_h_
/* *****************************************************************************************
 *    End of file
 */ 
