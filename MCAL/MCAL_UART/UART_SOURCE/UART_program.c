/*
 * UART_program.c
 *
 *  Created on: Oct 29, 2023
 *      Author: mohamed
 */


#include"../UART_HEADER/UART_interface.h"
#include"../UART_HEADER/UART_PRIVATE.h"


/********************************** Macros Declarations *******************************/


/********************************** Data Type Declarations *******************************/
void (* pv_call_back_pointer)(void)=NULL;

/********************************** Software Interfaces Declarations *******************************/


Std_ReturnType UART_vidInit(void)
{

Std_ReturnType ret=E_NOT_OK;
#if (UART_ENABLE_INTERRUPT==1)
SET_BIT(UCSRB_reg,7);//enable interrupt
SET_BIT(UCSRC_reg,7);//enable interrupt
CLEAR_BIT(UCSRB_reg,2);//enable interrupt
SET_BIT(UCSRC_reg,2);//8bit size
SET_BIT(UCSRC_reg,1);//8bit size
CLEAR_BIT(UCSRC_reg,6);//asynchronus mode
SET_BIT(UCSRB_reg,3);//enable transmit
SET_BIT(SREG_reg,7);

SET_BIT(UCSRB_reg,4);//enable recive
//No parity
CLEAR_BIT(UCSRC_reg,5);
CLEAR_BIT(UCSRC_reg,4);

//Number of stop bits
SET_BIT(UCSRC_reg,3);
#else
//Setting both Receive Enable and Transmit Enable
	SET_BIT(UCSRB_reg,4);
	SET_BIT(UCSRB_reg,3);

	//Selecting UCSRA

	//Selecting Asynchronous mode

	//No parity
	CLEAR_BIT(UCSRC_reg,5);
	CLEAR_BIT(UCSRC_reg,4);

	//Number of stop bits
	SET_BIT(UCSRC_reg,3);

	//Character size
	CLEAR_BIT(UCSRB_reg,2);
	SET_BIT(UCSRC_reg,2);
	SET_BIT(UCSRC_reg,1);
#endif

	UBRRL_reg=103;

	return ret;
}
Std_ReturnType UART_vidSendByte(u8 u8byteCpy) {
	while (READ_BIT(UCSRA_reg,5) == 0); //Checking the UART Data Register Empty (UDRE) bit
	UDR_reg = u8byteCpy;
return 1;
}

Std_ReturnType UART_u8ReceiveByte(u8 *ret_val) {
	while (READ_BIT(UCSRA_reg,7) == 0); //Checking the Receive Complete (RxE) bit
	*ret_val= UDR_reg;
	return 1;
}
void  UART_u8ReceiveCall_Back(void (* call_back_from_user)(void)) {
	if(call_back_from_user!=NULL){
		pv_call_back_pointer=call_back_from_user;


	}
	else{/*do nothing*/}
}
void __vector_13(void) __attribute__((signal));
void __vector_13(void){
/*important must  do some  operation here
 * 	reciv_chr= UDR_reg+32;
 */
	if(pv_call_back_pointer!=NULL){

		pv_call_back_pointer();
	}


}

/*
Std_ReturnType UART_vidInitExpanded(UARTConfig_t *uart_obj);
Std_ReturnType UART_vidSendByte(u8 data);
Std_ReturnType UART_u8ReceiveByte(u8 *ret_val);
Std_ReturnType UART_u8GetReceivedByte(u8 * ret_val);
Std_ReturnType UART_vidSendLine(void);
Std_ReturnType UART_vidSendString(u8 *str);

*/
