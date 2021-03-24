/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-03-24
 *    Information :
 */

#ifndef fw_usart_H_
#define fw_usart_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus
  
#include <stdint.h>
#include <stdbool.h>

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_usart_api_t fw_usart_api_t;
typedef struct _fw_usart_handle_t fw_usart_handle_t;
typedef struct _fw_usart_send_t fw_usart_send_t;
typedef struct _fw_usart_read_t fw_usart_read_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_usart_event_send_t)(fw_usart_handle_t* handle, fw_usart_send_t data, void* attachment);
typedef void (*fw_usart_event_read_t)(fw_usart_handle_t* handle, fw_usart_read_t buffer, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_usart_handle_t{
  void* memory;
  const fw_usart_api_t* api;
}fw_usart_handle_t;

/* *****************************************************************************************
 *    Struct - fw_usart_send_t
 */ 
typedef struct _fw_usart_send_t{
  const void* data;
  uint32_t len;
}fw_usart_send_t;

/* *****************************************************************************************
 *    Struct - fw_usart_read_t
 */ 
typedef struct _fw_usart_read_t{
  void* buffer;
  uint32_t len;
}fw_usart_read_t;
 
/* *****************************************************************************************
 *    Struct - fw_usart_api_t
 */ 
typedef struct _fw_usart_api_t{
  bool  (*init)        (fw_usart_handle_t* handle);
  bool  (*deinit)      (fw_usart_handle_t* handle);
  bool  (*send)        (fw_usart_handle_t* handle, fw_usart_send_t data, fw_usart_event_send_t execute, void* attachment);
  bool  (*sendByte)    (fw_usart_handle_t* handle, uint8_t data);
  bool  (*read)        (fw_usart_handle_t* handle, fw_usart_read_t buffer, fw_usart_event_read_t execute, void* attachment);
  bool  (*readByte)    (fw_usart_handle_t* handle, uint8_t *buffer);
  bool  (*setBaudrate) (fw_usart_handle_t* handle, uint32_t baudrate);
  bool  (*isBusy)      (fw_usart_handle_t* handle);
}fw_usart_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_usart_H_
/* *****************************************************************************************
 *    End of file
 */ 
