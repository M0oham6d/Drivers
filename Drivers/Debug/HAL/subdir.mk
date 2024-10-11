################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/buzzer.c \
../HAL/flame_sensor.c \
../HAL/lcd.c \
../HAL/ldr_sensor.c \
../HAL/leds.c \
../HAL/lm35_sensor.c \
../HAL/motor.c 

OBJS += \
./HAL/buzzer.o \
./HAL/flame_sensor.o \
./HAL/lcd.o \
./HAL/ldr_sensor.o \
./HAL/leds.o \
./HAL/lm35_sensor.o \
./HAL/motor.o 

C_DEPS += \
./HAL/buzzer.d \
./HAL/flame_sensor.d \
./HAL/lcd.d \
./HAL/ldr_sensor.d \
./HAL/leds.d \
./HAL/lm35_sensor.d \
./HAL/motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


