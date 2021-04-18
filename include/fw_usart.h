/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-04-16
 *    Information :
 */

#ifndef fw_usart_H_
#define fw_usart_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus
  
#include <stdint.h>
#include <stdbool.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_usart_api_t fw_usart_api_t;
typedef struct _fw_usart_handle_t fw_usart_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_usart_event_send_t)(fw_usart_handle_t* _this, fw_memory_t* data, void* attachment);
typedef void (*fw_usart_event_read_t)(fw_usart_handle_t* _this, fw_memory_t* buffer, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_usart_handle_t{
  void* memory;
  const fw_usart_api_t* api;
}fw_usart_handle_t;
 
/* *****************************************************************************************
 *    Struct - fw_usart_api_t
 */ 
typedef struct _fw_usart_api_t{
  bool  (*init)             (fw_usart_handle_t* _this);
  bool  (*deinit)           (fw_usart_handle_t* _this);
  bool  (*isEnable)         (fw_usart_handle_t* _this);
  bool  (*send)             (fw_usart_handle_t* _this, fw_memory_t* data, fw_usart_event_send_t execute, void* attachment);
  bool  (*sendByte)         (fw_usart_handle_t* _this, uint8_t data);
  bool  (*read)             (fw_usart_handle_t* _this, fw_memory_t* buffer, fw_usart_event_read_t execute, void* attachment);
  bool  (*readByte)         (fw_usart_handle_t* _this, uint8_t* buffer);
  bool  (*abortSend)        (fw_usart_handle_t* _this);
  bool  (*abortRead)        (fw_usart_handle_t* _this);
  bool  (*setBaudrate)      (fw_usart_handle_t* _this, uint32_t baudrate);
  bool  (*isSendBusy)       (fw_usart_handle_t* _this);
  bool  (*isReadBusy)       (fw_usart_handle_t* _this);

  struct{
    FW_STRUCT_FIFO(fw_usart_handle_t*) fifo;
    FW_STRUCT_RING_BUFFER(fw_usart_handle_t*) ringBuffer;
    FW_STRUCT_TASK_SCHEDULER(fw_usart_handle_t*) taskScheduler;
  }support;
}fw_usart_api_t;

/* *****************************************************************************************
 *    Macro
 */ 
#define FW_USART_API_LINK(profix, name) \
fw_usart_api_t name = {                 \
  .FW_API_LINK(profix, init),           \
  .FW_API_LINK(profix, deinit),         \
  .FW_API_LINK(profix, isEnable),       \
  .FW_API_LINK(profix, send),           \
  .FW_API_LINK(profix, sendByte),       \
  .FW_API_LINK(profix, read),           \
  .FW_API_LINK(profix, readByte),       \
  .FW_API_LINK(profix, setBaudrate),    \
  .FW_API_LINK(profix, isSendBusy),     \
  .FW_API_LINK(profix, isReadBusy),     \
  .FW_API_LINK(profix, abortSend),      \
  .FW_API_LINK(profix, abortRead),      \
  .support = {                          \
    .FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix, taskScheduler), \
    .FW_SUPPORT_RING_BUFFER_API_LINK(profix, ringBuffer),       \
    .FW_SUPPORT_FIFO_API_LINK(profix, fifo),                    \
  },                                                            \
}

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_usart_H_
/* *****************************************************************************************
 *    End of file
 */ 
