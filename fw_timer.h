/* *****************************************************************************************
 *    File Name   :fw_timer.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */
 
#ifndef fw_timer_h_
#define fw_timer_h_
#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Include
 */ 
#include <stdbool.h>
#include <stdint.h>

#include "fw_base.h"


/* *****************************************************************************************
 *    Macro
 */ 


/* *****************************************************************************************
 *    Typedef List
 */ 
typedef struct _fw_timer_handle_t fw_timer_handle_t;


/* *****************************************************************************************
 *    Typedef Function
 */ 
typedef void (*fw_timer_event_execute_t)(fw_timer_handle_t* _this, void* attachment);


/* *****************************************************************************************
 *    Struct/Union/Enum
 */ 
 
/*----------------------------------------
 *  fw_timer_api_t
 *----------------------------------------*/
struct fw_timer_api_t{
  bool  (*init)             (fw_timer_handle_t* _this);
  bool  (*deinit)           (fw_timer_handle_t* _this);
  bool  (*isEnable)         (fw_timer_handle_t* _this);
  bool  (*startAtTick)      (fw_timer_handle_t* _this, uint32_t tick, fw_timer_event_execute_t execute, void* attachment);
  bool  (*startAtTime)      (fw_timer_handle_t* _this, uint32_t us, fw_timer_event_execute_t execute, void* attachment);
  bool  (*stop)             (fw_timer_handle_t* _this);
};


/* *****************************************************************************************
 *    Typedef Struct/Union/Enum
 */ 

/*----------------------------------------
 *  fw_timer_handle_t
 *----------------------------------------*/
typedef struct _fw_timer_handle_t{
  void* memory;
  const struct fw_timer_api_t* api;
}fw_timer_handle_t; 


/* *****************************************************************************************
 *    Inline Function
 */ 

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_timer_h_
/* *****************************************************************************************
 *    End of file
 */ 
