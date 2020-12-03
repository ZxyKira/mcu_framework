/* *****************************************************************************************
 *    File Name   :fw_io_entity.h
 *    Create Date :2020-08-12
 *    Modufy Date :2020-11-30
 *    Information :
 */
#ifndef fw_io_entity_H_
#define fw_io_entity_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

typedef struct _fw_io_entity_api_t fw_io_entity_api_t;

/* *****************************************************************************************
 *    Function Type
 */ 

/* *****************************************************************************************
 *    Struct - fw_io_entity_handle_t
 */ 
typedef struct _fw_io_entity_handle_t{
  void* memory;
  void* base;
  const fw_io_entity_api_t* API;
}fw_io_entity_handle_t;

/* *****************************************************************************************
 *    Struct - fw_io_entity_api_t
 */ 
typedef struct _fw_io_entity_api_t{
  void (*setValue)  (fw_io_entity_handle_t handle, bool val);
  void (*setHigh)   (fw_io_entity_handle_t handle);
  void (*setLow)    (fw_io_entity_handle_t handle);
  void (*setToggle) (fw_io_entity_handle_t handle);  
  void (*setDir)    (fw_io_entity_handle_t handle, bool dir);
  void (*setInput)  (fw_io_entity_handle_t handle);
  void (*setOutput) (fw_io_entity_handle_t handle);
  bool (*getValue)  (fw_io_entity_handle_t handle);
  bool (*getDir)    (fw_io_entity_handle_t handle);
}fw_io_entity_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_entity_H_
/* *****************************************************************************************
 *    End of file
 */ 