/*
 * timer0_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: mohamed sallam
 */

/************************include part********/
#include"../timer0_HEADERS/timer0_interface.h"
#include"../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_DATATYPES.h"

#include "../timer0_HEADERS/MCAL_TIMER0_CONFIG.H"
/*********private *************/
void(*ptr_func)();
u8 global_pre_load_value ;
pin_t OC0;



/*********functions *************/
TIMER0_ERROR_ST Timer0_ERROR_sT_Init(const timer0_t *_timer){
	TIMER0_ERROR_ST ret=TIMER_NOT_OK;


	if(_timer==NULL){
		ret=TIMER_NOT_OK;

	}else

	{
	TCNT0_REG=_timer->timer0_preload_value;
	global_pre_load_value=_timer->timer0_preload_value;
#if TIMER0_MODE == TIMER0_OVERFLOW_MODE
	TCCR0_REG=_timer->prescaler_value;//toggle pin and  the pre scaler  and  ctc mode

	ret=TIMER_OK;

#elif TIMER0_MODE == TIMER0_CTC_MODE
	OC0.direction=OUTPUT;
	OC0.pin=pin3;
	OC0.port_index=PORT_B;
	Mcal_Dio_Std_Set_Pin_Direction(&OC0);
	TCCR0_REG=_timer->prescaler_value|24;//toggle pin and  the pre scaler  and  ctc mode
	OCR0_REG=_timer->timer0_compare_value;
	ret=TIMER_OK;

#elif TIMER0_MODE == TIMER0_FAST_PWM
//	Mcal_Dio_Std_Set_Pin_Direction()
	TCCR0_REG=((u8)_timer->prescaler_value|(u8)0b01101000);//clear oc0 on compare match and set it  at bottm && chose  fast pwm mode
	OCR0_REG=_timer->timer0_compare_value;
	OC0.direction=OUTPUT;
	OC0.pin=pin3;
	OC0.port_index=PORT_B;
	Mcal_Dio_Std_Set_Pin_Direction(&OC0);
	ret=TIMER_OK;


#elif TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
	OC0.direction=OUTPUT;
	OC0.pin=pin3;
	OC0.port_index=PORT_B;
	Mcal_Dio_Std_Set_Pin_Direction(&OC0);
	TCCR0_REG=_timer->prescaler_value|0b00101000;//clear oc0 on compare match when count up and set it  at compare match on count dowm
	//&& chose  phase correct  pwm mode
	ret=TIMER_OK;


#elif TIMER0_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
	TIMSK_REG|=0x01;
	ptr_func=_timer->TMR0_InterruptHandler;
#endif

	}
	return ret;
}

TIMER0_ERROR_ST Timer0_ERROR_DeInit(const timer0_t *_timer){

	TIMER0_ERROR_ST ret=TIMER_NOT_OK;
	if(_timer==NULL){
		ret=TIMER_NOT_OK;

	}else{

	TCCR0_REG=0;
	 ret=TIMER_OK;
	}
	return ret;

}
TIMER0_ERROR_ST Timer0_ERROR_Write_Value(const timer0_t *_timer, u16 _value){


	TIMER0_ERROR_ST ret=TIMER_NOT_OK;
	if(_timer==NULL){
		ret=TIMER_NOT_OK;

	}
	else{
#if TIMER0_MODE == TIMER0_FAST_PWM

		OCR0_REG=_value;
#else
		TCNT0_REG=_value;
		#endif

	 ret=TIMER_OK;
	}
	return ret;

}
TIMER0_ERROR_ST Timer0_ERROR_Read_Value(const timer0_t *_timer, u16 *_value){

	TIMER0_ERROR_ST ret=TIMER_NOT_OK;
	if(_timer==NULL){
		ret=TIMER_NOT_OK;

	}
	else{
	*_value=TCNT0_REG;
	 ret=TIMER_OK;
	}
	return ret;


}

#if TIMER0_INTERRUPT_FEATURE==INTERRUPT_FEATURE_ENABLE


void __vector_10(void) __attribute__((signal));//interuupt  when timer0 compare match

void __vector_10(void){

	if(ptr_func!= NULL)
	{
		ptr_func();
		TCNT0_REG=global_pre_load_value;
	}
}


/*

void __vector_11(void) __attribute__((signal));//interuupt  when timer0 overflow

void __vector_11(void){

	if(ptr_func!= NULL)
	{
		ptr_func();
		TCNT0_REG=global_pre_load_value;
	}
}

*/
#endif
