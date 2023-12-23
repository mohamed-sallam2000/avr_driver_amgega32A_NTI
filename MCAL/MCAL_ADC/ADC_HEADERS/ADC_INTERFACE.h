/*
 * ADC_INTERFACE.h
 *
 *  Created on: Oct 29, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_
#define MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_

#include"ADC_PRIVATE.h"

#include "../../../STD_TYPES.h"


/********************************** Macros Declarations *******************************/


/********************************** Data Type Declarations *******************************/


/********************************** Software Interfaces Declarations *******************************/
Std_ReturnType ADC1_init_mine(void);
Std_ReturnType ADC_Read_mine(u8 channel,u8* ret_val);

#endif /* MCAL_MCAL_ADC_ADC_HEADERS_ADC_INTERFACE_H_ */
/*ecample using lm35 to calculate temperature
 * 	ADC1_init_mine();
		ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_CLEAR);
		_delay_ms(10);
		ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_RETURN_HOME);
		charr_receive='d';
		_delay_ms(10);
		ECU_Lcd_4Bit_Send_char(&lcd_obj,charr_receive);
		_delay_ms(10);

		ADC_Read_mine(1,&charr_send);
		millvolte =((u16)((u32)charr_send*5000UL)/256UL);
		u8 temp=millvolte/10;
	 ECU_Lcd_convert_int_to_string((u32)temp, str) ;

		ECU_Lcd_4Bit_Send_str(&lcd_obj,str);

		//ECU_Lcd_4Bit_Send_char(&lcd_obj,charr_receive);
		UART_vidSendByte(temp);
 */
