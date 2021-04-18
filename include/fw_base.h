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

/* *****************************************************************************************
 *    Macro
 */ 
#define FW_API_LINK(profix, func) .func = profix##_##func


#define FW_STRUCT_TASK_SCHEDULER(handle)                \
struct{                                                 \
  bool (*enable) (handle _this, void* schedulerMemory); \
  bool (*disable)(handle _this);                        \
}

#define FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix, name) name = {  \
  .enable  = profix##_support_taskScheduler_enable,                \
  .disable = profix##_support_taskScheduler_disable,               \
}

#define FW_STRUCT_RING_BUFFER(handle)                                      \
struct{                                                                    \
  bool     (*enable)    (handle _this, void* buffer, uint32_t bufferSize); \
  bool     (*disable)   (handle _this);                                    \
  uint32_t (*getCount)  (handle _this);                                    \
  uint32_t (*getFree)   (handle _this);                                    \
  bool     (*flush)     (handle _this);                                    \
}

#define FW_SUPPORT_RING_BUFFER_API_LINK(profix, name) name = {   \
  .enable   = profix##_support_ringBuffer_enable,                \
  .disable  = profix##_support_ringBuffer_disable,               \
  .getCount = profix##_support_ringBuffer_getCount,              \
  .getFree  = profix##_support_ringBuffer_getFree,               \
  .flush    = profix##_support_ringBuffer_flush,                 \
}

#define FW_STRUCT_FIFO(handle)                                              \
struct{                                                                     \
  bool     (*enable)    (handle _this, void* buffer, uint32_t bufferSize);  \
  bool     (*disable)   (handle _this);                                     \
}

#define FW_SUPPORT_FIFO_API_LINK(profix, name) name = {  \
  .enable  = profix##_support_fifo_enable,               \
  .disable = profix##_support_fifo_disable,              \
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif
/* *****************************************************************************************
 *    End of file
 */ 
