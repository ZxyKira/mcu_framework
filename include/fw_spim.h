/* *****************************************************************************************
 *    File Name   :fw_spi.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-13
 *    Modufy Date :2020-11-25
 *    Information :
 */
 
#ifndef fw_spim_H_
#define fw_spim_H_

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_spim_api_t fw_spim_api_t;
typedef struct _fw_spim_handle_t fw_spim_handle_t;
typedef struct _fw_spim_xfer_t fw_spim_xfer_t;

/* *****************************************************************************************
 *    Function
 */ 
typedef void (*fw_spim_event_onXferFinish)(fw_spim_handle_t *handle);
typedef void (*fw_spim_event_onXferByte)(fw_spim_handle_t *handle);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_spim_handle_t{
	void* memory;
	fw_spim_api_t *API;
}fw_spim_handle_t;

/* *****************************************************************************************
 *    Type/Structure
 */ 
typedef struct _fw_spim_api_t{
  bool (*xfer)							(fw_spim_handle_t* handle, fw_spim_xfer_t *xfer);
  bool (*isBusy)						(fw_spim_handle_t* handle);
	void (*setCpha)						(fw_spim_handle_t* handle, bool enable);
	void (*setCpol)						(fw_spim_handle_t* handle, bool enable);
	void (*setLsb) 						(fw_spim_handle_t* handle, bool enable);
	void (*setLoop)						(fw_spim_handle_t* handle, bool enable);	
	void (*setPreDelay)				(fw_spim_handle_t* handle, uint8_t val);
	void (*setPostDelay)			(fw_spim_handle_t* handle, uint8_t val);	
	void (*setFrameDelay)			(fw_spim_handle_t* handle, uint8_t val);	
	void (*setTransferDelay)	(fw_spim_handle_t* handle, uint8_t val);
	
	//--------Event--------
  struct{
		void (*setOnXferFinish) (fw_spim_handle_t* handle, fw_spim_event_onXferFinish event);
		void (*setOnXferByte)		(fw_spim_handle_t* handle, fw_spim_event_onXferByte event);
  }Event;
}fw_spim_api_t;


typedef struct _fw_spim_xfer_t{
	const void* tx;
	void* rx;
	uint32_t len;
	uint32_t dummy;
	uint32_t point;
}fw_spim_xfer_t;

/*-----------------------------------------------------------------------------------------
 *    Function
 */

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //fw_spim_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */

