/* *****************************************************************************************
 *    File Name   :fw_adc_channel.h
 *    Create Date :2021-04-24
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_ADC_CHANNEL_VERSION
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
 *  FW_ADC_CHANNEL_VERSION
 *----------------------------------------*/
#define FW_ADC_CHANNEL_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_ADC_PIN_API_LINK
 *----------------------------------------*/
#define FW_ADC_CHANNEL_API_LINK(profix, name) \
{                                             \
  .FW_API_LINK(profix, enable),               \
  .FW_API_LINK(profix, disable),              \
  .FW_API_LINK(profix, value),                \
}



/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_adc_pin_handle_t fw_adc_pin_handle_t;



/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_adc_api_t
 *----------------------------------------*/
struct fw_adc_pin_api_t{
  bool               (*enable)   (fw_adc_pin_handle_t* _this);
  bool               (*disable)  (fw_adc_pin_handle_t* _this);
  uint32_t           (*value)    (fw_adc_pin_handle_t* _this);
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_adc_pin_handle_t
 *----------------------------------------*/
typedef struct _fw_adc_pin_handle_t{
  void* memory;
  const struct fw_adc_api_t* api;
}fw_adc_pin_handle_t;



/* *****************************************************************************************
 *    Inline Function
 */ 



#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_ADC_CHANNEL_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
