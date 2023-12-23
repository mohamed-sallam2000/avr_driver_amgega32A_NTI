/*
 * ECU_LCD_Private.c
 *
 *  Created on: Oct 22, 2023
 *      Author: mohamed
 */


/*include section*/
#include"../ECU_LCD_HEADERS/ECU_LCD_Interface.h"
/*private function
 * @Brief: function to calcualte  the  power  of  number
 * input: base  is  8u
 * input : power to multiple
 * output  : the result
 * */


u32 pow_m(u8 l_base, u8 power) {


    u32 res = 1;
    if (power == 0) {
        return 1;
    }
    while (power--) {
        res *= l_base;

    }
    return res;
}

Std_ReturnType ECU_Lcd_4Bit_convert_arr_to_int(u8 arr[],u16*val){
	Std_ReturnType ret=E_NOT_OK;
	*val=0;
	for (int i=0;i<6;i++){
		if(arr[i]!=0xff&&arr[i]>='0'&&arr[i]<='9'){//,AKE SURE THE  NUMBER  IS NOT ANY OTHER  CHARARCTER
			*val=(*val)*10+(arr[i]-'0');}
	}
	return ret;
}
Std_ReturnType  ECU_Lcd_4Bit_reverse(u8* str, u8 length) {
	Std_ReturnType ret=E_OK;
	u8 start = 0;
	u8 end = length - 1;
	while (start < end) {
		u8 temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return ret;
}
Std_ReturnType ECU_Lcd_4Bit_convert_floatToString(f32 number, u8* buffer, u8 bufferSize, u8 precision) {
	Std_ReturnType ret=E_NOT_OK;
	u8 isNegative = 0;
	if (number < 0) {
		isNegative = 1;
		number = -number;
	}

	// Extract integer and fractional parts
	u32 intPart = (u32)number;
	f32 fractionalPart = number - intPart;

	// Convert integer part to string
	u8 index = 0;
	while (intPart) {
		buffer[index++] = (intPart % 10) + '0';
		intPart /= 10;
	}
	if (index == 0) {
		buffer[index++] = '0';
	}
	if (isNegative) {
		buffer[index++] = '-';
	}
	 ECU_Lcd_4Bit_reverse(buffer, index);

	// Convert fractional part to string
	if (precision > 0) {
		buffer[index++] = '.';
		for (u8 i = 0; i < precision; i++) {
			fractionalPart *= 10;
			u8 digit = (u8)fractionalPart;
			buffer[index++] = digit + '0';
			fractionalPart -= digit;
		}
	}

	buffer[index-2] = '\0';//add termination char
	return ret;
}

/*
Std_ReturnType ECU_Lcd_4Bit_convert_int(u8 charr,u8 * int_val){
	*int_val=charr-'0';
	return E_OK;



}*/
Std_ReturnType ECU_Lcd_convert_int_to_string(u32 value, u8 *str) {
    u32 l_counter = 0;
    Std_ReturnType ret = E_NOT_OK;
    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        u32 power;
        memset(str, '\0', 11); //fill the array with null termination
        for (l_counter = 1; l_counter <= 11; l_counter++) {
            power = pow_m(10, l_counter);

            str[11 - l_counter] = (((value) % (power)) / (power / 10)) + '0';


        }

        ret = E_OK;
    }



    return ret;
}
