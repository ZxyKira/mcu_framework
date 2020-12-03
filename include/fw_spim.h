/* *****************************************************************************************
 *    File Name   :fw_spi.h
 *    Create Date :2020-08-13
 *    Modufy Date :2020-11-30
 *    Information :
 */
 
#ifndef fw_spim_H_
#define fw_spim_H_

#include <stdint.h>
#include <stdbool.h>

#include "fw_spim_entity.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_spim_api_t fw_spim_api_t;
typedef struct _fw_spim_handle_t fw_spim_handle_t;
/* *****************************************************************************************
 *    Function Type
 */ 
 
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
  bool                      (*init)        (fw_spim_handle_t handle);
  bool                      (*deinit)      (fw_spim_handle_t handle);
  bool                      (*isBusy)      (fw_spim_handle_t handle);
  fw_spim_entity_handle_t   (*getEntity)   (fw_spim_handle_t handle, void* memory, uint32_t ssel);
  uint32_t                  (*getMaxSsel)  (fw_spim_handle_t handle);
}fw_spim_api_t;



/* *****************************************************************************************
 *    Function
 */

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_spim_H_
/* *****************************************************************************************
 *    End of file
 */

