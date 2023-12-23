/*
 * UART_interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: mohamed
 */

#ifndef MCAL_MCAL_UART_UART_HEADER_UART_INTERFACE_H_
#define MCAL_MCAL_UART_UART_HEADER_UART_INTERFACE_H_

#include"UART_PRIVATE.h"
#include "../../../STD_TYPES.h"

/********************************** Macros Declarations *******************************/



#define UART_ENABLE_TXRX 0
#define UART_ENABLE_TX 1
#define UART_ENABLE_RX 2

#define UART_PARITYBITS_DISABLED 0
#define UART_PARITYBITS_EVEN 1
#define UART_PARITYBITS_ODD 2

#define UART_STOPBITS_1 0
#define UART_STOPBITS_2 1

#define UART_CHARSIZE_5 0
#define UART_CHARSIZE_6 1
#define UART_CHARSIZE_7 2
#define UART_CHARSIZE_8 3
#define UART_CHARSIZE_9 4



#define UART_ENABLE_INTERRUPT   1
/********************************** Data Type Declarations *******************************/
typedef struct {
	u8 u8RxTxEnable;
	u8 u8ParityBits;
	u8 u8StopBits;
	u8 u8CharacterSize;
	u8 u8BaudRateHigh;
	u8 u8BaudRateLow;
} UARTConfig_t;



/********************************** Software Interfaces Declarations *******************************/




Std_ReturnType UART_u8ReceiveByte(u8 *ret_val);
Std_ReturnType UART_vidSendByte(u8 u8byteCpy);
Std_ReturnType UART_vidInit(void);
void  UART_u8ReceiveCall_Back(void (* call_back_from_user)(void)) ;


#endif /* MCAL_MCAL_UART_UART_HEADER_UART_INTERFACE_H_ */
