/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_spi.h
 *    Version     :V1.0.0
 *    Create Date :2020-08-13
 *    Modufy Date :2020-10/07
 *    Information :
 */
#ifndef FW_SPI_H_
#define FW_SPI_H_
#include "fw_io.h"
#include "fw_spi_entity.h"

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 
 
/*! @name   fw_spim_api_t
 *  @brief  Framework SPI master api structure.
 */
typedef struct _fw_spim_api_t{

  /*! @name   fw_spim_api_t.init
   *  @brief  Initialized SPIM.
   *  @param  hwBase   : MCU Hardware base address.
   *  @param  hwMemory : MCU Hardware handle memory pointer.
   *  @return success  : fw_spim_base_t
   */	
  bool (*init)(uint8_t ch);
	
  /*! @name   fw_spim_api_t.deinit
   *  @brief  deinitialized SPIM.
   *  @param  pBase    : Framework SPIM base structure pointer.
   *  @return void
   */ 
  void (*deinit)(uint8_t ch);
	
  /*! @name   fw_spim_api_t.getEntity
   *  @brief  Set SPIM entity.
   *  @param  pBase    : Framework SPIM base structure pointer.
   *  @param  ssel     : Slave select number.
   *  @return struct   : fw_spim_entity_t
   */	
  fw_spim_entity_t (*getEntity)(uint8_t ch, uint8_t ssel);
	
  /*! @name   fw_spim_api_t.xfer
   *  @brief  SPIM transfer.
   *  @param  pBase    : Framework SPIM base structure pointer.
   *  @param  ssel     : Slave select number.
	 *  @param  pXfer	   : Transfer Structure pointer.
   *  @return boolean  : false = FIFO full or SPIM busy; true = success
   */		
  bool (*xfer)(uint8_t ch, uint8_t ssel, fw_spim_xfer_t *pXfer);
	
  /*! @name   fw_spim_api_t.isBusy
   *  @brief  SPIM transfer.
   *  @param  pBase    : Framework SPIM base structure pointer.
   *  @return boolean  : false = Is not busy; true = Is busy.
   */		
  bool (*isBusy)(uint8_t ch);
  
  /*! @name   fw_spim_api_t.getDefaultConfig
   *  @brief  SPIM transfer.
   *  @param  pBase    : Framework SPIM base structure pointer.
   *  @return struct   : fw_spim_config_t default config structure.
   */		
  fw_spim_config_t (*getDefaultConfig)(uint8_t ch);
	
  /*! @name   fw_spim_api_t.Config
   *  @brief  Framework SPI master Config setting api structure.
   */
	struct{
		
		/*! @name   fw_spim_api_t.Config.cpha
		 *  @brief  SPIM Config CPHA.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  enagble  : Enable function.
     *  @return success  : true
     *  @return fail     : false
		 */	
		void (*cpha)(fw_spim_config_t* pConfig, bool enable);
		
		/*! @name   fw_spim_api_t.Config.cpol
		 *  @brief  SPIM Config CPOL.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  enable  : Enable function.
     *  @return success  : true
     *  @return fail     : false
		 */			
		void (*cpol)(fw_spim_config_t* pConfig, bool enable);
		
		/*! @name   fw_spim_api_t.Config.lsb
		 *  @brief  SPIM Config Low bit transfer first.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  enable  : Enable function.
     *  @return success  : true
     *  @return fail     : false
		 */			
		void (*lsb) (fw_spim_config_t* pConfig, bool enable);
		
		/*! @name   fw_spim_api_t.Config.loop
		 *  @brief  SPIM Config, setting transfer loopback.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  enable  : Enable function.
     *  @return success  : true
     *  @return fail     : false
		 */			
		void (*loop)(fw_spim_config_t* pConfig, bool enable);
		
		/*! @name   fw_spim_api_t.Config.preDelay
		 *  @brief  SPIM Config, setting delay between SSEL assertion and the beginning of transfer.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  val      : Number of delay frame.
     *  @return success  : true
     *  @return fail     : false
		 */					
		void (*preDelay)(fw_spim_config_t* pConfig, uint8_t val);
		
		/*! @name   fw_spim_api_t.Config.postDelay
		 *  @brief  SPIM Config, setting delay between the end of transfer and SSEL deassertion.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  val      : Number of delay frame.
     *  @return success  : true
     *  @return fail     : false
		 */					
		void (*postDelay)(fw_spim_config_t* pConfig, uint8_t val);
		
		/*! @name   fw_spim_api_t.Config.frameDelay
		 *  @brief  SPIM Config, setting delay between frame to frame.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  val      : Number of delay frame.
     *  @return success  : true
     *  @return fail     : false
		 */					
		void (*frameDelay)(fw_spim_config_t* pConfig, uint8_t val);
		
		/*! @name   fw_spim_api_t.Config.transferDelay
		 *  @brief  SPIM Config, setting delay between transfer to transfer.
		 *  @param  pBase    : Framework SPIM base structure pointer.
		 *  @param  pConfig  : Framework SPIM config structure pointer.
		 *  @param  val      : Number of delay frame.
     *  @return success  : true
     *  @return fail     : false
		 */					
		void (*transferDelay)(fw_spim_config_t* pConfig, uint8_t val);
		
	}Config;
}fw_spim_api_t;

/*-----------------------------------------------------------------------------------------
 *    Function
 */

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //FW_SPI_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */

