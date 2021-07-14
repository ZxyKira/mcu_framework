/* *****************************************************************************************
 *    File Name   :fw_adc.h
 *    Create Date :2021-04-24
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_adc_h_
#define fw_adc_h_
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


/* *****************************************************************************************
 *    Macro
 */ 

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
	uint32_t             (*read)           (fw_adc_handle_t* _this, uint32_t channel);
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
