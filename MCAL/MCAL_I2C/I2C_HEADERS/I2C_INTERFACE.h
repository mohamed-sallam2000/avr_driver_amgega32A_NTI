/*
 * I2C_INTERFACE.h
 *
 *  Created on: Oct 31, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_I2C_I2C_HEADERS_I2C_INTERFACE_H_
#define MCAL_MCAL_I2C_I2C_HEADERS_I2C_INTERFACE_H_

#include "../../../STD_TYPES.h"
#include "../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"
#include"avr/io.h"
#include "math.h"
#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define BITRATE(TWSR)	((F_CPU/F_SCL)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

/*
 *
 * scl frequency = cpu_f/(16+2*(TWBR)*4^twPs)
 * TWBR=
 */
void I2C_master_init(void);

u8 I2C_start(u8 address);
u8 I2C_write(u8 data);
u8 I2C_read(void);
u8 I2C_Repeated_Start(u8 read_address) ;/* I2C repeated start function */
void I2C_stop(void);
void I2C_Slave_Init(u8 My_Add);
u8 I2C_Slave_avialable();
u8 I2C_Read_Ack();
u8 I2C_Read_Nack();

#endif /* MCAL_MCAL_I2C_I2C_HEADERS_I2C_INTERFACE_H_ */



/*	eeprom write  and  read code
 *
#define EEPROM_Write_Addess		0xA0
#define EEPROM_Read_Addess		0xA1

 *
 * u8 array[10] = "test";	* Declare array to be print /
	   		* Initialize LCD /
	 I2C_master_init();			* Initialize I2C /
	 I2C_start(EEPROM_Write_Addess);* Start I2C with device write address /
	 I2C_write(0x00);		* Write start memory address for data write /
	    for (int i = 0; i<strlen(array); i++)/ Write array data /
		{
	    	//I2C_write(array[i]);
		}
	    I2C_stop();			* Stop I2C /
	    _delay_ms(10);
	    I2C_start(EEPROM_Write_Addess);* Start I2C with device write address *
	    I2C_write(0x00);		* Write start memory address /
	    I2C_Repeated_Start(EEPROM_Read_Addess);* Repeat start I2C SLA+R /
	    for (int i = 0; i<strlen(array); i++)* Read data with acknowledgmen /
		{
	    	ECU_Lcd_4Bit_Send_char(&lcd_obj,I2C_Read_Ack());
}
	    I2C_Read_Nack();		* Read flush data with nack/
	    I2C_stop();			* Stop I2C
	    return 0;

}
	    */
