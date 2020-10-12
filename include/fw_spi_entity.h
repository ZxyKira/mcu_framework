/*-----------------------------------------------------------------------------------------
 *    File Name   :fw_spi_entity.h
 *    Version     :V1.0.0
 *    Create Date :2020-10-07
 *    Modufy Date :
 *    Information :
 */
#ifndef FW_SPI_ENTITY_H_
#define FW_SPI_ENTITY_H_
#include <stdint.h>
#include <stdbool.h>

/*-----------------------------------------------------------------------------------------
 *    Extern Function/Variable
 */
typedef struct _fw_spim_base_t fw_spim_base_t;
typedef struct _fw_spim_callback_t fw_spim_callback_t;
typedef struct _fw_spim_xfer_t fw_spim_xfer_t;
typedef struct _fw_spim_entity_api_t fw_spim_entity_api_t;
typedef struct _fw_spim_entity_t fw_spim_entity_t;

/*-----------------------------------------------------------------------------------------
 *    Type/Structure
 */ 
 
 /*! @name   fw_spim_callback_t
 *  @brief  Framework SPI master handle callback structure.
 */
typedef struct _fw_spim_callback_t{
  void (*foo)(const fw_spim_entity_t entity, void* userData);
  void *userData;
}fw_spim_callback_t;


/*! @name   fw_spim_config_t
 *  @brief  Framework SPI master hardware configuration structure.
 */
typedef struct _fw_spim_config_t{
	
	/*! @name   fw_spim_config_t.Delay
   *  @brief  About SPIM Transfer frame delay.
   */
  struct{
		/* Delay between SSEL assertion and the beginning of transfer. */
    uint8_t preDelay;
		
		/* Delay between the end of transfer and SSEL deassertion. */
    uint8_t postDelay; 
		
		/* Delay between frame to frame. */
    uint8_t frameDelay; 
		
		/* Delay between transfer to transfer. */
    uint8_t transferDelay ; 
  }Delay;
	
	/* Hardware registor setting. */
	uint32_t hwSetting;
	
	/* SPIM transfer speed. */
  uint32_t baudrate;
}fw_spim_config_t;


/*! @name   fw_spim_xfer_t
 *  @brief  Framework SPI master transfer structure.
 */
typedef struct _fw_spim_xfer_t{
	
	/* SPIM config structure. */
  fw_spim_config_t config;
	
	/* SPIM Handle callback structure. */
  fw_spim_callback_t callback;
	
	/*! @name   fw_spim_xfer_t.Data
   *  @brief  SPIM data.
   */	
  struct{
		
		/* Transfer data pointer */
		const void* pTx;

		/* Receiver buffer pointer */
		void* pRx;
			
		/* size */
		uint32_t len;
  }Data;
}fw_spim_xfer_t;


/*! @name   fw_spim_entity_t
 *  @brief  Framework SPI master entity structure.
 */
typedef struct _fw_spim_entity_t{
	const fw_spim_entity_api_t* pAPI;
	uint8_t ch;
  uint8_t ssel;
}fw_spim_entity_t;
 
/*! @name   fw_spim_entity_api_t
 *  @brief  Framework SPI master entity api structure.
 */
typedef struct _fw_spim_entity_api_t{

  /*! @name   fw_spim_api_t.xfer
   *  @brief  SPIM transfer.
   *  @param  pEntity  : Framework SPIM entity structure pointer.
   *  @param  pXfer    : Transfer Structure pointer.
   *  @return boolean  : false = FIFO full or SPIM busy; true = success
   */    
  bool (*xfer)(const fw_spim_entity_t entity, fw_spim_xfer_t *pXfer);
  
  /*! @name   fw_spim_api_t.isBusy
   *  @brief  SPIM transfer.
   *  @param  pEntity  : Framework SPIM entity structure pointer.
   *  @return boolean  : false = Is not busy; true = Is busy.
   */    
  bool (*isBusy)(const fw_spim_entity_t entity);
  
  /*! @name   fw_spim_api_t.getDefaultConfig
   *  @brief  SPIM transfer.
   *  @param  pEntity  : Framework SPIM entity structure pointer.
   *  @return struct   : fw_spim_config_t default config structure.
   */    
  fw_spim_config_t (*getDefaultConfig)(const fw_spim_entity_t entity);
	
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
}fw_spim_entity_api_t;
/*-----------------------------------------------------------------------------------------
 *    Function
 */

/*-----------------------------------------------------------------------------------------
 *    Variable
 */

#endif //FW_SPI_ENTITY_H_
/*-----------------------------------------------------------------------------------------
 *    End of file
 */
