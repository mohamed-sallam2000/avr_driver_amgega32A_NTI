/*
 * ADC_PROGRAM.C
 *
 *  Created on: Oct 29, 2023
 *      Author: mohamed
 */


#include "ADC_INTERFACE.h"

#include "STD_TYPES.h"

/********************************** Macros Declarations *******************************/


/********************************** Data Type Declarations *******************************/


/********************************** Software Interfaces Declarations *******************************/

Std_ReturnType ADC1_init_mine(void){
	Std_ReturnType ret= E_OK;
	ADCSRA_reg = 0b10000111;//128 prescaler
	ADMUX_reg = 0b01000001;
return ret;
}

Std_ReturnType ADC_Read_mine(u8 channel,u8* ret_val){
	Std_ReturnType ret= E_OK;
	ADMUX_reg |= channel;
	ADCSRA_reg |= 1<<6;
	while((ADCSRA_reg & 1<<6));
	*ret_val= (ADCL_reg+ (ADCH_reg << 8));
	return ret;
}

