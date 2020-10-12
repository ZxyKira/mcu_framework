/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_io_entity.h
 *    Version     :V1.0.0
 *    Create Date :2020-10-07
 *    Modufy Date :
 *    Information :
 */
#ifndef FW_IO_ENTITY_H_
#define FW_IO_ENTITY_H_
#include <stdint.h>
#include <stdbool.h>

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */
typedef struct _fw_io_entity_api_t fw_io_entity_api_t;

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 
 
/*! @name   fw_io_api_t
 *  @brief  Framework io api structure.
 */
typedef struct _fw_io_entity_t{
	const fw_io_entity_api_t* pAPI;
  uint8_t ch;
  uint8_t port;
  uint8_t pin;
} fw_io_entity_t;

/*! @name   fw_io_entity_api_t
 *  @brief  Framework io entity api structure.
 */
typedef struct _fw_io_entity_api_t{ 
  /*! @name   fw_io_api_t.setValue
   *  @brief  Set pin output value.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @param  val      : false = Set pin out low; true = Set pin out high
   *  @return value    : fw_io_entity_t
   */
  void (*setValue)(const fw_io_entity_t entity, bool val);
  
  /*! @name   fw_io_api_t.setHigh
   *  @brief  Set pin output high.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setHigh)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.setLow
   *  @brief  Set pin output low.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setLow)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.setToggle
   *  @brief  Set pin output toggle
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setToggle)(const fw_io_entity_t entity);  
  
  /*! @name   fw_io_api_t.setDir
   *  @brief  Set pin direction.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @param  dir       : false = Set pin input; true = Set pin output
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setDir)(const fw_io_entity_t entity, bool dir);
  
  /*! @name   fw_io_api_t.setInput
   *  @brief  Set pin to input.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setInput)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.setOutput
   *  @brief  Set pin to output.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setOutput)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.getValue
   *  @brief  Get pin read value
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return value    : false = Pin is low; true = Pin is high
   */
  bool (*getValue)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.getDir
   *  @brief  Get pin direction.
   *  @param  pEntity  : Framework IO base Entity structure pointer.
   *  @return boolean  : false = Pin is input; true = Pin is output
   */
  bool (*getDir)(const fw_io_entity_t entity);
  
  /*! @name   fw_io_api_t.Func
   *  @brief  About pin function setting.
   */
}fw_io_entity_api_t;
/*-----------------------------------------------------------------------------------------
 *    Function
 */

/*-----------------------------------------------------------------------------------------
 *    Variable
 */

#endif //FW_IO_ENTITY_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */
