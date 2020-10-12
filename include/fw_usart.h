/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_usart.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-13
 *    Modufy Date :2020-10/07
 *    Information :
 */
#ifndef fw_usart_H_
#define fw_usart_H_
#include "fw_io.h"

#include "fw_usart_entity.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 
typedef struct _fw_usart_api_t{
	
  /*! @name   fw_usart_api_t.init
   *  @brief  Initialized UART.
   *  @param  hwBase   : MCU Hardware base address.
   *  @param  hwMemory : MCU Hardware handle memory pointer.
   *  @return success  : fw_usart_base_t
   */	
  bool    (*init)         (uint8_t ch);
	
  /*! @name   fw_usart_api_t.deinit
   *  @brief  Initialized UART.
   *  @param  hwBase   : MCU Hardware base address.
   *  @param  hwMemory : MCU Hardware handle memory pointer.
   *  @return success  : fw_usart_base_t
   */	
  void              (*deinit)       (uint8_t ch);
  fw_usart_entity_t  (*getEntity)    (uint8_t ch);
  bool              (*reciver)      (uint8_t ch, fw_usart_xfer_t *xfer);
  bool              (*send)         (uint8_t ch, fw_usart_xfer_t *xfer);
  void              (*abortReceive) (uint8_t ch);
  void              (*abortSend)    (uint8_t ch);
  //--------Setting--------
  struct{
    bool  (*setBaudrate)(uint8_t ch, uint32_t baudrate);
		void  (*ringBufferEnable)(uint8_t ch, void* buffer, uint32_t size);
		void  (*ringBufferDisable)(uint8_t ch);
		
  }Setting;
}fw_usart_api_t;

/*-----------------------------------------------------------------------------------------
 *    Function
 */ 

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_usart_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */ 
