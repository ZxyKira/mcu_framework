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
	}group;
	uint16_t portPin;
}fw_pin_t;

#define fw_pin_define(x, y) {.group.port = x,	.group.pin = y}

inline fw_pin_t fw_pin_init(uint16_t port, uint16_t pin){
	fw_pin_t result = {
		.group.port = port,
		.group.pin = pin,
	};
	return result;
}

#endif
/* *****************************************************************************************
 *    End of file
 */ 
