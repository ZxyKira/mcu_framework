/* *****************************************************************************************
 *    File Name   :fw_base.h
 *    Create Date :2021-03-17
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_BASE_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "version.h"



/* *****************************************************************************************
 *    Macro
 */ 

/*----------------------------------------
 *  FW_BASE_VERSION
 *----------------------------------------*/
#define FW_BASE_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_PIN_DEFINE
 *----------------------------------------*/
#define FW_PIN_DEFINE(x, y) {.group.port = x,  .group.pin = y}



/*----------------------------------------
 *  FW_API_LINK
 *----------------------------------------*/
#define FW_API_LINK(profix, func) func = profix##_##func



/*----------------------------------------
 *  FW_STRUCT_TASK_SCHEDULER
 *----------------------------------------*/
#define FW_STRUCT_TASK_SCHEDULER(handle)                \
struct{                                                 \
  bool (*enable) (handle _this, void* schedulerMemory); \
  bool (*disable)(handle _this);                        \
}



/*----------------------------------------
 *  FW_SUPPORT_TASK_SCHEDULER_API_LINK
 *----------------------------------------*/
#define FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix)   \
{                                                    \
  .enable  = profix##_support_taskScheduler_enable,  \
  .disable = profix##_support_taskScheduler_disable, \
}



/*----------------------------------------
 *  FW_STRUCT_RING_BUFFER
 *----------------------------------------*/
#define FW_STRUCT_RING_BUFFER(handle)                                      \
struct{                                                                    \
  bool     (*enable)    (handle _this, void* buffer, uint32_t bufferSize); \
  bool     (*disable)   (handle _this);                                    \
  uint32_t (*getCount)  (handle _this);                                    \
  uint32_t (*getFree)   (handle _this);                                    \
  bool     (*flush)     (handle _this);                                    \
}



/*----------------------------------------
 *  FW_SUPPORT_RING_BUFFER_API_LINK
 *----------------------------------------*/
#define FW_SUPPORT_RING_BUFFER_API_LINK(profix)     \
{                                                   \
  .enable   = profix##_support_ringBuffer_enable,   \
  .disable  = profix##_support_ringBuffer_disable,  \
  .getCount = profix##_support_ringBuffer_getCount, \
  .getFree  = profix##_support_ringBuffer_getFree,  \
  .flush    = profix##_support_ringBuffer_flush,    \
}



/*----------------------------------------
 *  FW_STRUCT_FIFO
 *----------------------------------------*/
#define FW_STRUCT_FIFO(handle)                                        \
struct{                                                               \
  bool (*enable)  (handle _this, void* buffer, uint32_t bufferSize);  \
  bool (*disable) (handle _this);                                     \
}

struct _fw_support_fifo_t{
	bool (*enable)  (void* _this, void* buffer, uint32_t bufferSize);
  bool (*disable) (void* _this);
}fw_support_fifo_t;


/*----------------------------------------
 *  FW_SUPPORT_FIFO_API_LINK
 *----------------------------------------*/
#define FW_SUPPORT_FIFO_API_LINK(profix)    \
{                                           \
  .enable  = profix##_support_fifo_enable,  \
  .disable = profix##_support_fifo_disable, \
}



/* *****************************************************************************************
 *    Typedef List
 */ 

/* *****************************************************************************************
 *    Typedef Function
 */ 

/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_pin_t
 *----------------------------------------*/
typedef union _fw_pin_t{
  struct{
    uint16_t pin  :5;
    uint16_t port :11;
  }group;
  uint16_t portPin;
}fw_pin_t;



/*----------------------------------------
 *  fw_memory_t
 *----------------------------------------*/
typedef struct _fw_memory_t{
  void* ptr;
  uint32_t size;
}fw_memory_t;



/* *****************************************************************************************
 *    Inline function
 */ 

/*----------------------------------------
 *  fw_pin_init
 *----------------------------------------*/
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
#endif //FW_BASE_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
