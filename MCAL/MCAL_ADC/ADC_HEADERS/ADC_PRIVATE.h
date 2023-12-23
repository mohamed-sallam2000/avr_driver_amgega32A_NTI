/*
 * ADC_PRIVATE.h
 *
 *  Created on: Oct 29, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_ADC_ADC_HEADERS_ADC_PRIVATE_H_
#define MCAL_MCAL_ADC_ADC_HEADERS_ADC_PRIVATE_H_



/********************************** Macros Declarations *******************************/

/********************************** Macros Declarations *******************************/
#define ADCSRA_reg  *((volatile u8*) 0x26)
#define ADMUX_reg  *((volatile u8*) 0x27)
#define ADCL_reg  *((volatile u8*) 0x24)
#define ADCH_reg    *((volatile u8*) 0x25)

/********************************** Data Type Declarations *******************************/


/********************************** Software Interfaces Declarations *******************************/

#endif /* MCAL_MCAL_ADC_ADC_HEADERS_ADC_PRIVATE_H_ */
