################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_LCD/ECU_LCD_PROGRAM.c 

OBJS += \
./ECU_LCD/ECU_LCD_PROGRAM.o 

C_DEPS += \
./ECU_LCD/ECU_LCD_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_LCD/%.o: ../ECU_LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

