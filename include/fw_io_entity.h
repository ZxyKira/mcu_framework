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
  const fw_io_entity_api_t* API;
}fw_io_entity_handle_t;

/* *****************************************************************************************
 *    Struct - fw_io_entity_api_t
 */ 
typedef struct _fw_io_entity_api_t{
  void (*setValue)  (const fw_io_entity_handle_t handle, bool val);
  void (*setHigh)   (const fw_io_entity_handle_t handle);
  void (*setLow)    (const fw_io_entity_handle_t handle);
  void (*setToggle) (const fw_io_entity_handle_t handle);  
  void (*setDir)    (const fw_io_entity_handle_t handle, bool dir);
  void (*setInput)  (const fw_io_entity_handle_t handle);
  void (*setOutput) (const fw_io_entity_handle_t handle);
  bool (*getValue)  (const fw_io_entity_handle_t handle);
  bool (*getDir)    (const fw_io_entity_handle_t handle);
}fw_io_entity_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //fw_io_entity_H_
/* *****************************************************************************************
 *    End of file
 */ 