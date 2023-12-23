/*
 * timer0_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: mohamed sallam
 */


/*timer 0 driver  you  must  select the mode in timer0_config.h berfore intializing  the timer
 *if u disabled  interuupt  it  will act  as  signel timer coutner
 *
 * */
#ifndef MCAL_MCAL_TIMER0_TIMER0_HEADERS_TIMER0_INTERFACE_H_
#define MCAL_MCAL_TIMER0_TIMER0_HEADERS_TIMER0_INTERFACE_H_
#include"../../../STD_TYPES.h"
#include"../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"

#include "MCAL_TIMER0_CONFIG.H"
#define TIMER0_ENABLE_INTERRUPT 1
#define TIMER0_DISABLE_INTERRUPT 0

#define TCCR0_REG (*((volatile u8 * )0x53))
#define TCNT0_REG (*((volatile u8 * )0x52))
#define OCR0_REG (*((volatile u8 * )0x5c))
#define TIMSK_REG (*((volatile u8 * )0x59))
#define 	TIMER_OK 0
#define TIMER_NOT_OK 1


typedef u8 TIMER0_ERROR_ST;

//TIMER 0 MODES {OVER FLOW (INT , NOT INT)|||CTC(INT , NOT INT )|||FAST PWM|||PHASE CORRECT PWM}

#define   TIMER0_PRESCALER_NO_CLOCK  	 	     0
#define    TIMER0_PRESCALER_BY_1     			 1
#define TIMER0_PRESCALER_DIV_BY_8    			 2
#define    TIMER0_PRESCALER_DIV_BY_64  	 		 3
#define TIMER0_PRESCALER_DIV_BY_256   	 	     4
#define TIMER0_PRESCALER_DIV_BY_1024  			 5
#define TIMER0_EXTERNAL_CLOCK_FALLING_EDGE  	 6
#define	TIMER0_EXTERNAL_CLOCK_RISING_EDGE  		 7

typedef u8 timer0_prescaler_select_t ;


typedef struct{
#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FEATURE_ENABLE
    void (*TMR0_InterruptHandler)(void);

#endif

   u8 timer0_compare_value;


    timer0_prescaler_select_t prescaler_value;
    u8 timer0_preload_value;

}timer0_t;
TIMER0_ERROR_ST Timer0_ERROR_sT_Init(const timer0_t *_timer);
TIMER0_ERROR_ST Timer0_ERROR_DeInit(const timer0_t *_timer);
TIMER0_ERROR_ST Timer0_ERROR_Write_Value(const timer0_t *_timer, u16 _value);
TIMER0_ERROR_ST Timer0_ERROR_Read_Value(const timer0_t *_timer, u16 *_value);

#endif /* MCAL_MCAL_TIMER0_TIMER0_HEADERS_TIMER0_INTERFACE_H_ */


/*
timer0_inst.prescaler_value=TIMER0_PRESCALER_BY_1 ;
timer0_inst.timer0_compare_value=125;
timer0_inst.TMR0_InterruptHandler=interrupt_timer0_overflow;*/
//Timer0_ERROR_sT_Init(&timer0_inst);
//Timer0_ERROR_sT_Init(&timer0_inst);*/
