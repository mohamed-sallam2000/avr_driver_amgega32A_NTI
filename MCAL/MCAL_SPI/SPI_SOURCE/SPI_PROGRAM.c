/*
 * SPI_PROGRAM.c
 *
 *  Created on: Oct 30, 2023
 *      Author: mohamed
 */


#include "../SPI_HEADER/SPI_INTERFACE.h"
#include "../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_REGISTER.h"


#include "avr/io.h"
Std_ReturnType SPI_Master_Init()
  {
	DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB7);
		SPCR |= (1<<SPE)|(1<<MSTR);


     return E_OK;
  }

Std_ReturnType SPI_Slave_Init()
  {
	DDRB |= (1<<PB6);
	SPCR |= (1<<SPE);

    return E_OK;
  }

u8 SPI_Send_Char(u8 data)
  {
    SPDR = data;
    while(!(SPSR & (1<<SPIF)));
    return SPDR;

  }

Std_ReturnType SPI_ReceiveByte(u8* recev_byte)
{
	while(READ_BIT(SPSR,SPIF));
	*recev_byte =SPDR;
	  return E_OK;
}

Std_ReturnType SPI_SendString(u8 *str)
{
	while(*str)
	{
		SPI_Send_Char(*str);
		str++;

	}
	  return E_OK;
}

Std_ReturnType SPI_ReceiveString(u8 *str)
{
	u8 i = 0;
	 SPI_ReceiveByte(&str[i]);
	while(str[i] != '\0')
	{
		i++;
		 SPI_ReceiveByte(&str[i]);
	}
	str[i] = '\0';
	  return E_OK;
}
