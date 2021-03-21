/* *****************************************************************************************
 *    File Name   :fw_spi.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-13
 *    Modufy Date :2020-11-25
 *    Information :
 */
 
#ifndef fw_spim_entity_H_
#define fw_spim_entity_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_spim_api_t fw_spim_api_t;
typedef struct _fw_spim_handle_t fw_spim_handle_t;
typedef struct _fw_spim_entity_xfer_t fw_spim_entity_xfer_t;

/* *****************************************************************************************
 *    Function Type
 */ 
typedef void (*fw_spim_execute_t)(fw_spim_handle_t handle, void* attachment);

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_spim_handle_t{
  void* memory;
  const fw_spim_api_t *API;
}fw_spim_handle_t;

/* *****************************************************************************************
 *    Type/Structure
 */ 
typedef struct _fw_spim_api_t{
  bool (*init)              (fw_spim_handle_t handle);
  bool (*deinit)            (fw_spim_handle_t handle);	
  bool (*isBusy)            (fw_spim_handle_t handle);
  bool (*xfer)              (fw_spim_handle_t handle, fw_spim_entity_xfer_t *xfer, fw_spim_execute_t execute, void* attachment);
  void (*setCpha)           (fw_spim_handle_t handle, bool enable);
  void (*setCpol)           (fw_spim_handle_t handle, bool enable);
  void (*setLsb)            (fw_spim_handle_t handle, bool enable);
  void (*setLoop)           (fw_spim_handle_t handle, bool enable);  
  void (*setPreDelay)       (fw_spim_handle_t handle, uint8_t val);
  void (*setPostDelay)      (fw_spim_handle_t handle, uint8_t val);  
  void (*setFrameDelay)     (fw_spim_handle_t handle, uint8_t val);  
  void (*setTransferDelay)  (fw_spim_handle_t handle, uint8_t val);
  bool (*setBaudrate)       (fw_spim_handle_t handle, uint32_t baudrate);
}fw_spim_api_t;


typedef struct _fw_spim_entity_xfer_t{
  const void* tx;
  void* rx;
  uint32_t len;
  uint32_t dummy;
  uint32_t point;
}fw_spim_entity_xfer_t;

/* *****************************************************************************************
 *    Function
 */

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_spim_entity_H_
/* *****************************************************************************************
 *    End of file
 */

