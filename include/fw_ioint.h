/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_IOINT_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

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
 *  FW_IOINT_VERSION
 *----------------------------------------*/
#define FW_IOINT_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_IOINT_API_LINK
 *----------------------------------------*/
#define FW_IOINT_API_LINK(profix)    \
{                                    \
  .FW_API_LINK(profix, init),        \
  .FW_API_LINK(profix, deinit),      \
  .FW_API_LINK(profix, isEnable),    \
  .FW_API_LINK(profix, enableRise),  \
  .FW_API_LINK(profix, enableFall),  \
  .FW_API_LINK(profix, disableRise), \
  .FW_API_LINK(profix, disableFall), \
  .FW_API_LINK(profix, disableAll),  \
  .support = {                       \
    .taskScheduler = FW_SUPPORT_TASK_SCHEDULER_API_LINK(profix), \
  }                                                              \
}



/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_ioint_handle_t fw_ioint_handle_t;



/* *****************************************************************************************
 *    Typedef Function
 */ 

/*----------------------------------------
 *  fw_ioint_execute_t
 *----------------------------------------*/
typedef void (*fw_ioint_execute_t)(fw_ioint_handle_t* _this, void* attachment);



/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_ioint_api_t
 *----------------------------------------*/
struct fw_ioint_api_t{ 
  bool  (*init)        (fw_ioint_handle_t* _this);
  bool  (*deinit)      (fw_ioint_handle_t* _this);
  bool  (*isEnable)    (fw_ioint_handle_t* _this);
  bool  (*enableRise)  (fw_ioint_handle_t* _this, fw_ioint_execute_t execute, void* attachment);
  bool  (*enableFall)  (fw_ioint_handle_t* _this, fw_ioint_execute_t execute, void* attachment);
  bool  (*disableRise) (fw_ioint_handle_t* _this);
  bool  (*disableFall) (fw_ioint_handle_t* _this);
  bool  (*disableAll)  (fw_ioint_handle_t* _this);

  struct{
    FW_STRUCT_TASK_SCHEDULER(fw_ioint_handle_t*) taskScheduler;
  }support;
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_ioint_handle_t
 *----------------------------------------*/
typedef struct _fw_ioint_handle_t{
  void* memory;
  const struct fw_ioint_api_t* api;
}fw_ioint_handle_t;



/* *****************************************************************************************
 *    Inline Function
 */



#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_IOINT_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
