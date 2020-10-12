/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_io_entity.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-12
 *    Modufy Date :2020-10-07
 *    Information :
 */
#ifndef FW_IO_H_
#define FW_IO_H_
#include "fw_io_entity.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 

/*! @name   fw_io_api_t
 *  @brief  Framework io api structure.
 */
typedef struct _fw_io_api_t{
  
  /*! @name   fw_io_api_t.init
   *  @brief  Initialized IO.
   *  @param  hwBase   : MCU Hardware base address.
   *  @param  hwMemory : MCU Hardware handle memory pointer.
   *  @return success  :fw_io_base_t
   */
  void (*init)(const uint8_t ch);
  
  /*! @name   fw_io_api_t.deinit
   *  @brief  deinitialized IO.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @return void
   */
  void (*deinit)(const uint8_t ch);
  
  /*! @name   fw_io_api_t.getEntity
   *  @brief  Get io pin entity structure.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return value    : fw_io_entity_t
   */
  fw_io_entity_t (*getEntity)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.setValue
   *  @brief  Set pin output value.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @param  val      : false = Set pin out low; true = Set pin out high
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setValue)(const uint8_t ch, const uint16_t port, const uint16_t pin, bool val);
  
  /*! @name   fw_io_api_t.setHigh
   *  @brief  Set pin output high.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setHigh)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.setLow
   *  @brief  Set pin output low.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setLow)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.setToggle
   *  @brief  Set pin output toggle
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setToggle)(const uint8_t ch, const uint16_t port, const uint16_t pin);  
  
  /*! @name   fw_io_api_t.setDir
   *  @brief  Set pin direction.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @param  dir      : false = Set pin input; true = Set pin output
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setDir)(const uint8_t ch, const uint16_t port, const uint16_t pin, bool dir);
  
  /*! @name   fw_io_api_t.setInput
   *  @brief  Set pin to input.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setInput)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.setOutput
   *  @brief  Set pin to output.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return success  : true
   *  @return fail     : false
   */
  void (*setOutput)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.getValue
   *  @brief  Get pin read value
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return value    : false = Pin is low; true = Pin is high
   */
  bool (*getValue)(const uint8_t ch, const uint16_t port, const uint16_t pin);
  
  /*! @name   fw_io_api_t.getDir
   *  @brief  Get pin direction.
   *  @param  pBase    : Framework IO base structure pointer.
   *  @param  pin      : IO pin select number.
   *  @return boolean  : false = Pin is input; true = Pin is output
   */
  bool (*getDir)(const uint8_t ch, const uint16_t port, const uint16_t pin);

  /*! @name   fw_io_api_t.Port
   *  @brief  About port control.
   */
  struct{
		
		/*! @name   fw_io_api_t.Port.read
     *  @brief  IO Port read.
     *  @param  pBase    : Framework IO base structure pointer.
     *  @param  port     : Port number.
     *  @param  mask     : IO pin select number.
	   *  @return value    : Port value.
     */
    uint32_t (*read)(const uint8_t ch, const uint16_t port);
		
		/*! @name   fw_io_api_t.Port.set
     *  @brief  Set port value mask high.
     *  @param  pBase    : Framework IO base structure pointer.
	   *  @param  port     : Port number.
     *  @param  mask     : IO pin select number.
     *  @return void
     */
    void (*set)(const uint8_t ch, const uint16_t port, const uint32_t mask);
		
		/*! @name   fw_io_api_t.Port.clear
     *  @brief  Set port value mask low.
     *  @param  pBase    : Framework IO base structure pointer.
		 *  @param  port     : Port number.
     *  @param  mask     : IO pin select number.
     *  @return void
     */
    void (*clear)(const uint8_t ch, const uint16_t port, const uint32_t mask);
		
		/*! @name   fw_io_api_t.Port.toggle
     *  @brief  Set port value mask toggle.
     *  @param  pBase    : Framework IO base structure pointer.
		 *  @param  port     : Port number.
     *  @param  mask     : IO pin select number.
     *  @return void
     */
    void (*toggle)(const uint8_t ch, const uint16_t port, const uint32_t mask);
		
		/*! @name   fw_io_api_t.Port.dir
     *  @brief  write port direction.
     *  @param  pBase    : Framework IO base structure pointer.
		 *  @param  port     : Port number.
     *  @param  val      : Direction value.
     *  @return void
     */
    void (*dir)(const uint8_t ch, const uint16_t port, const uint32_t val);
		
		/*! @name   fw_io_api_t.Port.dirClear
     *  @brief  Set port direction mask input.
     *  @param  pBase    : Framework IO base structure pointer.
		 *  @param  port     : Port number.
     *  @param  mask     : Direction clear mask.
     *  @return void
     */
    void (*dirClear)(const uint8_t ch, const uint16_t port, const uint32_t mask);
		
		/*! @name   fw_io_api_t.Port.dirSet
     *  @brief  Set port direction mask output.
     *  @param  pBase    : Framework IO base structure pointer.
		 *  @param  port     : Port number.
     *  @param  mask     : Direction set mask.
     *  @return void
     */
    void (*dirSet)(const uint8_t ch, const uint16_t port, const uint32_t mask);
  }Port;
}fw_io_api_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //FW_IO_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */ 
