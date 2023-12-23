#include "../EXT_INT_HEADERS/MCAL_EXT_INT_INTERGFACE.h"
void (*pvptr_func_int0)(void)=0;
void (*pvptr_func_int1)(void)=0;
void (*pvptr_func_int2)(void)=0;
#define SREG_reg    *((volatile u8*) 0x5f)


Std_ReturnType MCAL_EXT_INTERRRUPT_inti(u8 channel){
	Std_ReturnType ret =E_NOT_OK;
	if(channel==0){MCUCR_REG|=FALLING_EDGE;(GICR_REG|=(1<<6));/*enable int0*/}
	SET_BIT(SREG_reg,7);

return ret;


}
Std_ReturnType MCAL_EXT_INTERRRUPT_CallBack(void (*func)(void),u8 channel){
	Std_ReturnType ret =E_NOT_OK;

	if(channel==0){
		pvptr_func_int0=func;


	}

	return ret;

}
void __vector_1(void) __attribute__((signal));//interuupt  when external interrupt on D2 int0

void __vector_1(void){

	if(pvptr_func_int0!= 0)
	{
		pvptr_func_int0();

	}
}

void __vector_2(void) __attribute__((signal));//interuupt  when external interrupt on D2 int0

void __vector_2(void){

	if(pvptr_func_int1!= 0)
	{
		pvptr_func_int1();

	}
}

void __vector_3(void) __attribute__((signal));//interuupt  when external interrupt on D2 int0

void __vector_3(void){

	if(pvptr_func_int2!= 0)
	{
		pvptr_func_int2();

	}
}
