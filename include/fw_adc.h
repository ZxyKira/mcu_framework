/* *****************************************************************************************
 *    File Name   :fw_adc.h
 *    Create Date :2021-04-24
 *    Modufy Date :2021-04-25
 *    Information :
 */

#ifndef FW_ADC_VERSION
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdint.h>
#include <stdbool.h>

#include "fw_base.h"
#include "fw_adc_channel.h"
#include "version.h"



/* *****************************************************************************************
 *    Macro
 */ 

/*----------------------------------------
 *  FW_ADC_REQ_FW_ADC_CHANNEL_VERSION
 *----------------------------------------*/
#define FW_ADC_REQ_FW_ADC_CHANNEL_VERSION VERSION_DEFINEE(1,0,0)
#if VERSION_CHECK_COMPATIBLE(FW_ADC_CHANNEL_VERSION, FW_ADC_REQ_FW_ADC_CHANNEL_VERSION)
  #if VERSION_CHECK_COMPATIBLE(FW_ADC_CHANNEL_VERSION, FW_ADC_REQ_FW_ADC_CHANNEL_VERSION) == 2
      #error "FW_ADC_CHANNEL_VERSION under 1.0.x"
  #else
    #warning "FW_ADC_CHANNEL_VERSION revision under 1.0.0"
  #endif
#endif



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
 *  FW_ADC_VERSION
 *----------------------------------------*/
#define FW_ADC_VERSION VERSION_DEFINEE(1, 0, 0)



/*----------------------------------------
 *  FW_ADC_API_LINK
 *----------------------------------------*/
#define FW_ADC_API_LINK(profix)     \
{                                   \
  .FW_API_LINK(profix, init),       \
  .FW_API_LINK(profix, deinit),     \
  .FW_API_LINK(profix, isEnable),   \
  .FW_API_LINK(profix, getChannel), \
}



/* *****************************************************************************************
 *    Typedef List
 */ 

typedef struct _fw_adc_handle_t fw_adc_handle_t;



/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_adc_api_t
 *----------------------------------------*/
struct fw_adc_api_t{
  bool                 (*init)           (fw_adc_handle_t* _this);
  bool                 (*deinit)         (fw_adc_handle_t* _this);
  bool                 (*isEnable)       (fw_adc_handle_t* _this);
  fw_adc_pin_handle_t  (*getChannel)     (fw_adc_handle_t* _this, uint32_t channel);
};



/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_adc_handle_t
 *----------------------------------------*/
typedef struct _fw_adc_handle_t{
  void* memory;
  const struct fw_adc_api_t* api;
  uint32_t pin;
}fw_adc_handle_t;



/* *****************************************************************************************
 *    Inline Function
 */ 



#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_ADC_VERSION
/* *****************************************************************************************
 *    End of file
 */ 
