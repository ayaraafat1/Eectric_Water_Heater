################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/temp\ sensor/tempsensor.c 

OBJS += \
./HAL/temp\ sensor/tempsensor.o 

C_DEPS += \
./HAL/temp\ sensor/tempsensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/temp\ sensor/tempsensor.o: ../HAL/temp\ sensor/tempsensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/temp sensor/tempsensor.d" -MT"HAL/temp\ sensor/tempsensor.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


