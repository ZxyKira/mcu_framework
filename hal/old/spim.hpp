/* *****************************************************************************************
 *    File Name   :fw_spim.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef FW_SPIM_VERSION
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
typedef struct _fw_spim_handle_t fw_spim_handle_t;
typedef struct _fw_spim_xfer_t fw_spim_xfer_t;


/* *****************************************************************************************
 *    Typedef Function
 */ 
typedef void (*fw_spim_event_xfer_t)(fw_spim_handle_t* _this, fw_spim_xfer_t *xfer, void* attachment);


/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 
 
/*----------------------------------------
 *  fw_spim_api_t
 *----------------------------------------*/
struct fw_spim_api_t{
  bool (*init)              (fw_spim_handle_t* _this);
  bool (*deinit)            (fw_spim_handle_t* _this);  
  bool (*isEnable)          (fw_spim_handle_t* _this);
  bool (*isBusy)            (fw_spim_handle_t* _this);
  bool (*xfer)              (fw_spim_handle_t* _this, fw_spim_xfer_t *xfer, fw_spim_event_xfer_t execute, void* attachment);
	bool (*xferSync)          (fw_spim_handle_t* _this, fw_spim_xfer_t *xfer);
  bool (*setCpha)           (fw_spim_handle_t* _this, bool enable);
  bool (*setCpol)           (fw_spim_handle_t* _this, bool enable);
  bool (*setLsb)            (fw_spim_handle_t* _this, bool enable);
  bool (*setBaudrate)       (fw_spim_handle_t* _this, uint32_t baudrate);
};


/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 
 
/*----------------------------------------
 *  fw_spim_handle_t
 *----------------------------------------*/
typedef struct _fw_spim_handle_t{
  void* memory;
  const struct fw_spim_api_t* api;
}fw_spim_handle_t;


/*----------------------------------------
 *  fw_spim_xfer_t
 *----------------------------------------*/
typedef struct _fw_spim_xfer_t{
  uint8_t *txData;      /*!< Send buffer */
  uint8_t *rxData;      /*!< Receive buffer */
  uint32_t dataSize;    /*!< Transfer bytes */
}fw_spim_xfer_t;


/* *****************************************************************************************
 *    Inline Function
 */


#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_SPIM_VERSION
/* *****************************************************************************************
 *    End of file
 */

