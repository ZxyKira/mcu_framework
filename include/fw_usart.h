/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2020-11-30
 *    Information :
 */

#ifndef fw_usart_H_
#define fw_usart_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus
  
typedef struct _fw_usart_api_t fw_usart_api_t;
typedef struct _fw_usart_handle_t fw_usart_handle_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_usart_event_onReceiver)    (fw_usart_handle_t handle);
typedef void (*fw_usart_event_onSendFinish)  (fw_usart_handle_t handle, const void* pData, uint32_t len);
typedef void (*fw_usart_event_onSendByte)    (fw_usart_handle_t handle, uint8_t byte);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_usart_handle_t{
  void* memory;
  const fw_usart_api_t *API;
}fw_usart_handle_t;
 
/* *****************************************************************************************
 *    Struct - fw_usart_api_t
 */ 
typedef struct _fw_usart_api_t{
  bool      (*init)            (fw_usart_handle_t handle);
  bool      (*deinit)          (fw_usart_handle_t handle);
  void      (*beginReciver)    (fw_usart_handle_t handle);
  void      (*abortReciver)    (fw_usart_handle_t handle);
  bool      (*send)            (fw_usart_handle_t handle, const void* pData, uint32_t len);
  uint8_t   (*read)            (fw_usart_handle_t handle);
  uint32_t  (*readMulti)      (fw_usart_handle_t handle, void* pData, uint32_t len);
  bool      (*setBaudrate)    (fw_usart_handle_t handle, uint32_t baudrate);
  bool      (*isEmpty)        (fw_usart_handle_t handle);
  bool      (*isBusy)         (fw_usart_handle_t handle);
  
  // --------Event--------
  struct{
    void (*setOnReceiver)    (fw_usart_handle_t handle, fw_usart_event_onReceiver event);
    void (*setOnSendFinish)  (fw_usart_handle_t handle, fw_usart_event_onSendFinish event);
    void (*setOnSendByte)    (fw_usart_handle_t handle, fw_usart_event_onSendByte event);
  }Event;
}fw_usart_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_usart_H_
/* *****************************************************************************************
 *    End of file
 */ 
