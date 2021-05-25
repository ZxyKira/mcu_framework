/* *****************************************************************************************
 *    File Name   :fw_spim.h
 *    Create Date :2020-08-13
 *    Modufy Date :2021-04-25
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
#include "version.h"



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
 *  FW_SPIM_VERSION
 *----------------------------------------*/
#define FW_SPIM_VERSION VERSION_DEFINEE(1, 1, 0)



/*----------------------------------------
 *  FW_SPIM_API_LINK
 *----------------------------------------*/
#define FW_SPIM_API_LINK(profix)      \
{                                     \
  .FW_API_LINK(profix, init),         \
  .FW_API_LINK(profix, deinit),       \
  .FW_API_LINK(profix, isEnable),     \
  .FW_API_LINK(profix, isBusy),       \
  .FW_API_LINK(profix, xfer),         \
  .FW_API_LINK(profix, xferSync),     \
  .FW_API_LINK(profix, setCpha),      \
  .FW_API_LINK(profix, setCpol),      \
  .FW_API_LINK(profix, setLsb),       \
  .FW_API_LINK(profix, setBaudrate),  \
  .support = {                        \
    .taskScheduler = FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix), \
    .fifo = FW_SUPPORT_FIFO_API_LINK(profix),                    \
  }                                                              \
}



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
  
  struct{
    FW_STRUCT_FIFO(fw_spim_handle_t*) fifo;
    FW_STRUCT_TASK_SCHEDULER(fw_spim_handle_t*) taskScheduler;
  }support;
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

