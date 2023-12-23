/*
 * SPI_INTERFACE.h
 *
 *  Created on: Oct 30, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_SPI_SPI_HEADER_SPI_INTERFACE_H_
#define MCAL_MCAL_SPI_SPI_HEADER_SPI_INTERFACE_H_
/************************include part********/
#include "SPI_CONFIG.h"
#include "SPI_REGISTER.h"
#include "../../../STD_TYPES.h"
#include "../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"
#include"avr/io.h"


/*********functions *************/
Std_ReturnType SPI_Master_Init();
Std_ReturnType SPI_Slave_Init();
Std_ReturnType SPI_Send_Char(u8 data);
Std_ReturnType SPI_ReceiveByte(u8* recev_byte);
Std_ReturnType SPI_SendString(u8 *str);
Std_ReturnType SPI_ReceiveString(u8 *str);
#endif /* MCAL_MCAL_SPI_SPI_HEADER_SPI_INTERFACE_H_ */
