#ifndef _EXR_INT_HEADER_H
#define _EXR_INT_HEADER_H


#include "../../../STD_TYPES.h"
#include "../../MCAL_DIO/DIO_HEADERS/MCAL_DIO_INTERFACE.h"
#define MCUCR_REG *((volatile u8 *)0x55)
#define MCUCSR_REG *((volatile u8 *)0x54)
#define GICR_REG *((volatile u8 *)0x5B)
Std_ReturnType MCAL_EXT_INTERRRUPT_inti(u8 channel);
Std_ReturnType MCAL_EXT_INTERRRUPT_CallBack(void (*func)(void),u8 channel);


 enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RAISING_EDGE


};




#endif
