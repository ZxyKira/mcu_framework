/* *****************************************************************************************
 *    File Name   :fw_base.h
 *    Create Date :2021-03-17
 *    Modufy Date :2020-03-17
 *    Information :
 */
 
#ifndef fw_base_H
#define fw_base_H

#include <stdbool.h>
#include <stdint.h>

typedef union _fw_pin_t{
	struct{
		uint16_t pin  :5;
		uint16_t port :11;
	}Group;
	uint16_t portPin;
}fw_pin_t;


#endif
/* *****************************************************************************************
 *    End of file
 */ 
