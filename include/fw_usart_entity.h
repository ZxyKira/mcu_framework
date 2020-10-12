/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_usart_entity.h
 *    Version     :V1.0.0
 *    Create Date :2020-10-07
 *    Modufy Date :
 *    Information :
 */
#ifndef FW_USART_ENTITY_H_
#define FW_USART_ENTITY_H_
#include <stdint.h>
#include <stdbool.h>

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */
typedef struct _fw_usart_callback_t fw_usart_callback_t;
typedef struct _fw_usart_xfer_t fw_usart_xfer_t;
typedef struct _fw_usart_entity_api_t fw_usart_entity_api_t;
typedef struct _fw_usart_entity_t fw_usart_entity_t;

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 
typedef struct _fw_usart_entity_t{
	const fw_usart_entity_api_t* pAPI;
  uint8_t ch;
}fw_usart_entity_t; 

typedef struct _fw_usart_callback_t{
  void (*foo)(fw_usart_entity_t entity, void* userData);
  void *userData;
}fw_usart_callback_t;

typedef struct _fw_usart_xfer_t{
  void* data;
  uint32_t len;
  fw_usart_callback_t callback;
}fw_usart_xfer_t;
 
typedef struct _fw_usart_entity_api_t{
	bool (*reciver)(fw_usart_entity_t entity, fw_usart_xfer_t *xfer);
	bool (*send)(fw_usart_entity_t entity, fw_usart_xfer_t *xfer);
	void (*abortReceive)(fw_usart_entity_t entity);
	void (*abortSend)(fw_usart_entity_t entity);
	bool (*setBaudrate)(fw_usart_entity_t entity, uint32_t baudrate);
}fw_usart_entity_api_t;
/*-----------------------------------------------------------------------------------------
 *    Function
 */

/*-----------------------------------------------------------------------------------------
 *    Variable
 */

#endif //FW_USART_ENTITY_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */
