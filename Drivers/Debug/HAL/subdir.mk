################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/buzzer.c \
../HAL/external_eeprom.c \
../HAL/flame_sensor.c \
../HAL/keypad.c \
../HAL/lcd.c \
../HAL/ldr_sensor.c \
../HAL/lm35_sensor.c \
../HAL/motor.c \
../HAL/pir_sensor.c \
../HAL/three_leds.c \
../HAL/ultrasonic_sensor.c 

OBJS += \
./HAL/buzzer.o \
./HAL/external_eeprom.o \
./HAL/flame_sensor.o \
./HAL/keypad.o \
./HAL/lcd.o \
./HAL/ldr_sensor.o \
./HAL/lm35_sensor.o \
./HAL/motor.o \
./HAL/pir_sensor.o \
./HAL/three_leds.o \
./HAL/ultrasonic_sensor.o 

C_DEPS += \
./HAL/buzzer.d \
./HAL/external_eeprom.d \
./HAL/flame_sensor.d \
./HAL/keypad.d \
./HAL/lcd.d \
./HAL/ldr_sensor.d \
./HAL/lm35_sensor.d \
./HAL/motor.d \
./HAL/pir_sensor.d \
./HAL/three_leds.d \
./HAL/ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


