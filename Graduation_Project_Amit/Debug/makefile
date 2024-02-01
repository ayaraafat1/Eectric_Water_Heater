################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/EXT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/temp\ sensor/subdir.mk
-include HAL/seven_segment/subdir.mk
-include HAL/SW/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/EXT_TIMER0/subdir.mk
-include HAL/EXTR_INT/subdir.mk
-include HAL/EEPROM/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Graduation_Project_Amit.lss \

FLASH_IMAGE += \
Graduation_Project_Amit.hex \

EEPROM_IMAGE += \
Graduation_Project_Amit.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Graduation_Project_Amit.elf secondary-outputs

# Tool invocations
Graduation_Project_Amit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Graduation_Project_Amit.map -mmcu=atmega32 -o "Graduation_Project_Amit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Graduation_Project_Amit.lss: Graduation_Project_Amit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Graduation_Project_Amit.elf  >"Graduation_Project_Amit.lss"
	@echo 'Finished building: $@'
	@echo ' '

Graduation_Project_Amit.hex: Graduation_Project_Amit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Graduation_Project_Amit.elf  "Graduation_Project_Amit.hex"
	@echo 'Finished building: $@'
	@echo ' '

Graduation_Project_Amit.eep: Graduation_Project_Amit.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Graduation_Project_Amit.elf  "Graduation_Project_Amit.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Graduation_Project_Amit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Graduation_Project_Amit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Graduation_Project_Amit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
