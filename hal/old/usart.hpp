/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_usart_h_
#define fw_usart_h_
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


/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_usart_handle_t fw_usart_handle_t;


/* *****************************************************************************************
 *    Typedef Function
 */ 

/*----------------------------------------
 *  fw_usart_event_send_t
 *----------------------------------------*/
typedef void (*fw_usart_event_send_t)(fw_usart_handle_t* _this, fw_memory_t* data, void* attachment);


/*----------------------------------------
 *  fw_usart_event_read_t
 *----------------------------------------*/
typedef void (*fw_usart_event_read_t)(fw_usart_handle_t* _this, fw_memory_t* buffer, void* attachment);


/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_usart_api_t
 *----------------------------------------*/
struct fw_usart_api_t{
  bool  (*init)             (fw_usart_handle_t* _this);
  bool  (*deinit)           (fw_usart_handle_t* _this);
  bool  (*isEnable)         (fw_usart_handle_t* _this);
  bool  (*send)             (fw_usart_handle_t* _this, fw_memory_t* data, fw_usart_event_send_t execute, void* attachment);
  bool  (*sendSync)         (fw_usart_handle_t* _this, fw_memory_t* data);
  bool  (*sendByte)         (fw_usart_handle_t* _this, uint8_t data);
  bool  (*read)             (fw_usart_handle_t* _this, fw_memory_t* buffer, fw_usart_event_read_t execute, void* attachment);
  bool  (*readSync)         (fw_usart_handle_t* _this, fw_memory_t* buffer);
  bool  (*readByte)         (fw_usart_handle_t* _this, uint8_t* buffer);
  bool  (*abortSend)        (fw_usart_handle_t* _this);
  bool  (*abortRead)        (fw_usart_handle_t* _this);
  bool  (*setBaudrate)      (fw_usart_handle_t* _this, uint32_t baudrate);
  bool  (*isSendBusy)       (fw_usart_handle_t* _this);
  bool  (*isReadBusy)       (fw_usart_handle_t* _this);
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_usart_handle_t
 *----------------------------------------*/
typedef struct _fw_usart_handle_t{
  void* memory;
  const struct fw_usart_api_t* api;
}fw_usart_handle_t;




#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_USART_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
