/*
 * MCAL_TIMER1_INTERFACE.h
 *
 *  Created on: Oct 28, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_TIMER1_TIMER1_HEADERS_MCAL_TIMER1_INTERFACE_H_
#define MCAL_MCAL_TIMER1_TIMER1_HEADERS_MCAL_TIMER1_INTERFACE_H_

#define TCCR1_A_REG (*((volatile u8 * )0x4f))
#define TCCR1_B_REG (*((volatile u8 * )0x4E))
#define TCNT1_L_REG (*((volatile u8 * )0x4C))
#define TCNT1_H_REG (*((volatile u8 * )0x4D))

#define ICR1_H_REG (*((volatile u8 * )0x47))
#define ICR1_L_REG (*((volatile u8 * )0x46))
#endif /* MCAL_MCAL_TIMER1_TIMER1_HEADERS_MCAL_TIMER1_INTERFACE_H_ */

// *while(0){
//		TCCR1_A_REG = 0;
//			TCNT1=0;
//			TIFR = (1<<ICF1);   Clear ICF (Input Capture flag) flag
//
//			TCCR1_B_REG = 0x41;  	 Rising edge, no prescaler
//			while ((TIFR&(1<<ICF1)) == 0);
//			a = ICR1;  		/* Take value of capture register
//			TIFR = (1<<ICF1);  	 Clear ICF flag
//
//			TCCR1_B_REG = 0x01;  	 Falling edge, no prescaler
//			while ((TIFR&(1<<ICF1)) == 0);
//			b = ICR1;  		Take value of capture register
//			TIFR = (1<<ICF1);  	Clear ICF flag
//
//			TCCR1_B_REG = 0x41;  	 Rising edge, no prescaler
//			while ((TIFR&(1<<ICF1)) == 0);
//			c = ICR1;  		Take value of capture register
//			TIFR = (1<<ICF1);  	/ Clear ICF flag
//
//			TCCR1_B_REG = 0;  		* Stop the timer /
//
//			if(a<b && b<c)  	* Check for valid condition,
//						to avoid timer overflow reading /
//			{
//				high=b-a;
//				period=c-a;
//
//				long freq= F_CPU/period;* Calculate frequency *
//
//							/ Calculate duty cycle *
//	            		float duty_cycle =((float) high /(float)period)*100;
//	            		u8 str[10];
//	            					floatToString((freq),str,10,6);
//
//
//
//				ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_CLEAR);
//				_delay_ms(10);
//						ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_RETURN_HOME);
//						u8 str2[]="frequ=";
//				ECU_Lcd_4Bit_Send_str(&lcd_obj,str2);
//				ECU_Lcd_4Bit_Send_str(&lcd_obj,str);
//		u8	str3[]="HZ";
//				ECU_Lcd_4Bit_Send_str(&lcd_obj,str3);
//
//				            		//u8 str[11];
//				            					floatToString((duty_cycle),str,10,6);
//
//				            					ECU_Lcd_4Bit_Send_str(&lcd_obj,str);
//
//
//
//			}
//
//			else
//			{
//				u8	str4[]="out";
//				ECU_Lcd_4Bit_Send_str(&lcd_obj,str4);
//			}
//			_delay_ms(50);
//		}
//
//
//	while(0){
//
//		if (state==3){
//			state=0;
//			f32 dutycyckle=time_on/total_time;
//			u8 str[11];
//			floatToString((dutycyckle),str,10,6);
//			u8 str2[]="dutyecycle=";
//			ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_CLEAR);
//			_delay_ms(10);
//			ECU_Lcd_4Bit_Send_Command(&lcd_obj,_LCD_RETURN_HOME);
//			_delay_ms(10);
//			ECU_Lcd_4Bit_Send_str(&lcd_obj,str2);
//			_delay_ms(10);
//			ECU_Lcd_4Bit_Send_str(&lcd_obj,str);
//			_delay_ms(10);
//			u8 str44[44];
//
//						long freq= F_CPU/total_time;/ Calculate frequency
//						u8 str4[]="freq";
//						ECU_Lcd_4Bit_Send_str(&lcd_obj,str4);
//						_delay_ms(10);
//						floatToString((freq),str44,10,6);
//						ECU_Lcd_4Bit_Send_str(&lcd_obj,str44);
