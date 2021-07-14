/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2021-07-14
 *    Information :
 */

#ifndef fw_ioint_h_
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
#endif //fw_ioint_h_
/* *****************************************************************************************
 *    End of file
 */ 
