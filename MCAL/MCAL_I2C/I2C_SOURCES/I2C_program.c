/*
 * I2C_program.c
 *
 *  Created on: Oct 31, 2023
 *      Author: mohamed
 */

#include"../I2C_HEADERS/I2C_INTERFACE.h"

#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)
void I2C_master_init(void)
{


	    TWBR = BITRATE(TWSR=0x00);	/* Get bit rate register value by formula */




}

u8 I2C_start(u8 address)
{

	    u8 status;		/* Declare variable */
	    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT); /* Enable TWI, generate START */
	    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	    status=TWSR&0xF8;		/* Read TWI status register */
	    if(status!=0x08){		/* Check weather START transmitted or not? */
	    return 0;		}	/* Return 0 to indicate start condition fail */
	    else{
	    TWDR=address;		/* Write SLA+W in TWI data register */
	    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI & clear interrupt flag */
	    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	    status=TWSR&0xF8;		/* Read TWI status register */
	    }
	    if(status==0x18)		/* Check for SLA+W transmitted &ack received */
	    return 1;			/* Return 1 to indicate ack received */
	    if(status==0x20)		/* Check for SLA+W transmitted &nack received */
	    return 2;			/* Return 2 to indicate nack received */
	    else
	    return 3;			/* Else return 3 to indicate SLA+W failed */

}

u8  I2C_write(u8 data)
{



	   u8 status;		/* Declare variable */
	    TWDR=data;			/* Copy data in TWI data register */
	    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
	    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	    status=TWSR&0xF8;		/* Read TWI status register */
	    if(status==0x28)		/* Check for data transmitted &ack received */
	    return 0;			/* Return 0 to indicate ack received */
	    if(status==0x30)		/* Check for data transmitted &nack received */
	    return 1;			/* Return 1 to indicate nack received */
	    else
	    return 2;			/* Else return 2 for data transmission failure */

}
u8 I2C_Repeated_Start(u8 read_address) /* I2C repeated start function */
{
    uint8_t status;		/* Declare variable */
    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);/* Enable TWI, generate start */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    status=TWSR&0xF8;		/* Read TWI status register */
    if(status!=0x10)		/* Check for repeated start transmitted */
    return 0;			/* Return 0 for repeated start condition fail */
    TWDR=read_address;		/* Write SLA+R in TWI data register */
    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    status=TWSR&0xF8;		/* Read TWI status register */
    if(status==0x40)		/* Check for SLA+R transmitted &ack received */
    return 1;			/* Return 1 to indicate ack received */
    if(status==0x48)		/* Check for SLA+R transmitted &nack received */
    return 2;			/* Return 2 to indicate nack received */
    else
    return 3;			/* Else return 3 to indicate SLA+W failed */
}
u8 I2C_read(void)
{

	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}
u8 I2C_Read_Ack()		/* I2C read ack function */
{
    TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); /* Enable TWI, generation of ack */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    return TWDR;			/* Return received data */
}
void I2C_stop(void)
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);/* Enable TWI, generate stop */
while(TWCR&(1<<TWSTO));	/* Wait until stop condition execution */
}
void I2C_Slave_Init(u8 My_Add){
	TWAR = My_Add<<1;/* Assign Address in TWI address register */
	TWCR = (1<<TWEA) | (1<<TWINT) | (1<<TWEN);/* Enable TWI, Enable ack generation */



}

u8 I2C_Slave_avialable(){
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return ((TWSR & 0xF8) ==1);
}

u8 I2C_Read_Nack()		/* I2C read nack function */
{
    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    return TWDR;		/* Return received data */
}
