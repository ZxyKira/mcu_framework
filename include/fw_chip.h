/* *****************************************************************************************
 *    File Name   :fw_chip.h
 *    Create Date :2020-08-12
 *    Modufy Date :2020-11-30
 *    Information :
 */
#ifndef fw_chip_H_
#define fw_chip_H_

#include <stdint.h>
#include <stdbool.h>

#include "fw_io.h"
#include "fw_spim.h"
#include "fw_usart.h"


#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/* *****************************************************************************************
 *    Function Type
 */ 

/* *****************************************************************************************
 *    Struct - fw_usart_handle_t
 */ 
typedef struct _fw_chip_api_t{
  void (*chipInit)(void);
  bool (*setClock)(uint32_t clock);
  
  struct{
    fw_io_handle_t     (*io)    (uint32_t ch, void* memory);
    fw_spim_handle_t   (*spim)  (uint32_t ch, void* memory);
    fw_usart_handle_t  (*usart) (uint32_t ch, void* memory);
  }Construct;
}fw_chip_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_chip_H_
/* *****************************************************************************************
 *    End of file
 */ 
