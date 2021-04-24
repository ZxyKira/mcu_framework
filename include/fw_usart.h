/* *****************************************************************************************
 *    File Name   :fw_usart.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_USART_VERSION
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
 *  FW_USART_VERSION
 *----------------------------------------*/
#define FW_USART_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_USART_API_LINK
 *----------------------------------------*/
#define FW_USART_API_LINK(profix)    \
{                                    \
  .FW_API_LINK(profix, init),        \
  .FW_API_LINK(profix, deinit),      \
  .FW_API_LINK(profix, isEnable),    \
  .FW_API_LINK(profix, send),        \
  .FW_API_LINK(profix, sendByte),    \
  .FW_API_LINK(profix, read),        \
  .FW_API_LINK(profix, readByte),    \
  .FW_API_LINK(profix, setBaudrate), \
  .FW_API_LINK(profix, isSendBusy),  \
  .FW_API_LINK(profix, isReadBusy),  \
  .FW_API_LINK(profix, abortSend),   \
  .FW_API_LINK(profix, abortRead),   \
  .support = {                       \
    .taskScheduler = FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix), \
    .ringBuffer = FW_SUPPORT_RING_BUFFER_API_LINK(profix),       \
    .fifo = FW_SUPPORT_FIFO_API_LINK(profix),                    \
  },                                                             \
}



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
