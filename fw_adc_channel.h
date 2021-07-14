/* *****************************************************************************************
 *    File Name   :fw_adc_channel.h
 *    Create Date :2021-04-24
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_adc_channel_h_
#define fw_adc_channel_h_
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
#endif //fw_adc_channel_h_
/* *****************************************************************************************
 *    End of file
 */ 
