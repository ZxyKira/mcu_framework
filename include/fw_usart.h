/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-04-14
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
  bool  (*send)             (fw_usart_handle_t* _this, fw_memory_t* data, fw_usart_event_send_t execute, void* attachment);
  bool  (*sendByte)         (fw_usart_handle_t* _this, uint8_t data);
  bool  (*read)             (fw_usart_handle_t* _this, fw_memory_t* buffer, fw_usart_event_read_t execute, void* attachment);
  bool  (*readByte)         (fw_usart_handle_t* _this, uint8_t* buffer);
  bool  (*abortSend)        (fw_usart_handle_t* _this);
  bool  (*abortread)        (fw_usart_handle_t* _this);
  bool  (*setBaudrate)      (fw_usart_handle_t* _this, uint32_t baudrate);
  bool  (*isSendBusy)       (fw_usart_handle_t* _this);
  bool  (*isReadBusy)       (fw_usart_handle_t* _this);

  struct{
    bool (*taskSchedulerEnable)   (fw_usart_handle_t* _this, void* schedulerMemory);
    bool (*taskSchedulerDisable)  (fw_usart_handle_t* _this);
  }support;
}fw_usart_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_usart_H_
/* *****************************************************************************************
 *    End of file
 */ 
