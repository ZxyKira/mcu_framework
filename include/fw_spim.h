/* *****************************************************************************************
 *    File Name   :fw_spi.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-03-24
 *    Information :
 */
 
#ifndef fw_spim_entity_H_
#define fw_spim_entity_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include <stdint.h>
#include <stdbool.h>

#include "fw_base.h"

/* *****************************************************************************************
 *    Type define list
 */ 
typedef struct _fw_spim_api_t fw_spim_api_t;
typedef struct _fw_spim_handle_t fw_spim_handle_t;
typedef struct _fw_spim_xfer_t fw_spim_xfer_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_spim_event_xfer_t)(fw_spim_handle_t handle, fw_spim_xfer_t *xfer, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_spim_handle_t{
  void* memory;
  const fw_spim_api_t* api;
}fw_spim_handle_t;

/* *****************************************************************************************
 *    Struct - fw_spim_xfer_t
 */ 
typedef struct _fw_spim_xfer_t{
  fw_memory_t tx;
	fw_memory_t rx;
	uint32_t dummy;
	uint32_t clock;
}fw_spim_xfer_t;

/* *****************************************************************************************
 *    Struct - fw_spim_api_t
 */ 
typedef struct _fw_spim_api_t{
  bool (*init)              (fw_spim_handle_t* handle);
  bool (*deinit)            (fw_spim_handle_t* handle);  
  bool (*isBusy)            (fw_spim_handle_t* handle);
  bool (*xfer)              (fw_spim_handle_t* handle, fw_spim_xfer_t *xfer, fw_spim_event_xfer_t execute, void* attachment);
  bool (*setCpha)           (fw_spim_handle_t* handle, bool enable);
  bool (*setCpol)           (fw_spim_handle_t* handle, bool enable);
  bool (*setLsb)            (fw_spim_handle_t* handle, bool enable);
  bool (*setLoop)           (fw_spim_handle_t* handle, bool enable);
  bool (*setPreDelay)       (fw_spim_handle_t* handle, uint8_t val);
  bool (*setPostDelay)      (fw_spim_handle_t* handle, uint8_t val);
  bool (*setFrameDelay)     (fw_spim_handle_t* handle, uint8_t val);
  bool (*setTransferDelay)  (fw_spim_handle_t* handle, uint8_t val);
}fw_spim_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_spim_entity_H_
/* *****************************************************************************************
 *    End of file
 */

