
#ifndef MCAL_MCAL_UART_UART_HEADER_UART_PRIVATE_H_
#define MCAL_MCAL_UART_UART_HEADER_UART_PRIVATEH_


#include"../../../STD_TYPES.h"

/********************************** Macros Declarations *******************************/
#define UCSRB_reg  *((volatile u8*) 0x2A)
#define UCSRA_reg  *((volatile u8*) 0x2B)
#define UBRRL_reg  *((volatile u8*) 0x29)
#define UDR_reg    *((volatile u8*) 0x2C)
#define UCSRC_reg  *((volatile u8*) 0x40)
//#define UBRRH_reg  *((volatile u8*)) 0x40)
#define SREG_reg    *((volatile u8*) 0x5f)


/********************************** Data Type Declarations *******************************/


/********************************** Software Interfaces Declarations *******************************/





#endif /* MCAL_MCAL_UART_UART_HEADER_UART_INTERFACE_H_ */
