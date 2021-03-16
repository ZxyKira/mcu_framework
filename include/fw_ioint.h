/* *****************************************************************************************
 *    File Name   :fw_ioint.h
 *    Create Date :2021-03-16
 *    Modufy Date :2020-03-16
 *    Information :
 */
 
#ifndef fw_ioint_H
#define fw_ioint_H

#include <stdbool.h>
#include <stdint.h>

typedef struct _fw_inint_handle_t{

}fw_inint_handle_t;


typedef struct _fw_ioint_api_t{
	bool	(*init)(fw_inint_handle_t handle);
	bool	(*deinit)(fw_inint_handle_t handle);
}fw_ioint_api_t;


#endif
/* *****************************************************************************************
 *    End of file
 */ 
