/* *****************************************************************************************
 *    File Name   :fw_base.h
 *    Create Date :2021-03-17
 *    Modufy Date :2021-03-24
 *    Information :
 */
 
#ifndef fw_base_H
#define fw_base_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdbool.h>
#include <stdint.h>

/* *****************************************************************************************
 *    Macro
 */ 
#define fw_pin_define(x, y) {.group.port = x,  .group.pin = y}

/* *****************************************************************************************
 *    Union - fw_pin_t
 */ 
typedef union _fw_pin_t{
  struct{
    uint16_t pin  :5;
    uint16_t port :11;
  }group;
  uint16_t portPin;
}fw_pin_t;

typedef struct _fw_memory_t{
  void* ptr;
	uint32_t size;
}fw_memory_t;

/* *****************************************************************************************
 *    Inline function
 */ 
inline fw_pin_t fw_pin_init(uint16_t port, uint16_t pin){
  fw_pin_t result = {
    .group.port = port,
    .group.pin = pin,
  };
  return result;
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
