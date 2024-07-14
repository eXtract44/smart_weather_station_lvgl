################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/peripherals/Src/adc.c \
../Core/peripherals/Src/aht10.c \
../Core/peripherals/Src/brightness_control.c \
../Core/peripherals/Src/buzzer.c \
../Core/peripherals/Src/dfplayer_mini.c \
../Core/peripherals/Src/esp.c \
../Core/peripherals/Src/ili9486.c \
../Core/peripherals/Src/led.c \
../Core/peripherals/Src/lv53l0x.c \
../Core/peripherals/Src/median.c \
../Core/peripherals/Src/range.c \
../Core/peripherals/Src/sgp30.c 

OBJS += \
./Core/peripherals/Src/adc.o \
./Core/peripherals/Src/aht10.o \
./Core/peripherals/Src/brightness_control.o \
./Core/peripherals/Src/buzzer.o \
./Core/peripherals/Src/dfplayer_mini.o \
./Core/peripherals/Src/esp.o \
./Core/peripherals/Src/ili9486.o \
./Core/peripherals/Src/led.o \
./Core/peripherals/Src/lv53l0x.o \
./Core/peripherals/Src/median.o \
./Core/peripherals/Src/range.o \
./Core/peripherals/Src/sgp30.o 

C_DEPS += \
./Core/peripherals/Src/adc.d \
./Core/peripherals/Src/aht10.d \
./Core/peripherals/Src/brightness_control.d \
./Core/peripherals/Src/buzzer.d \
./Core/peripherals/Src/dfplayer_mini.d \
./Core/peripherals/Src/esp.d \
./Core/peripherals/Src/ili9486.d \
./Core/peripherals/Src/led.d \
./Core/peripherals/Src/lv53l0x.d \
./Core/peripherals/Src/median.d \
./Core/peripherals/Src/range.d \
./Core/peripherals/Src/sgp30.d 


# Each subdirectory must supply rules for building sources it contributes
Core/peripherals/Src/%.o Core/peripherals/Src/%.su Core/peripherals/Src/%.cyclo: ../Core/peripherals/Src/%.c Core/peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-peripherals-2f-Src

clean-Core-2f-peripherals-2f-Src:
	-$(RM) ./Core/peripherals/Src/adc.cyclo ./Core/peripherals/Src/adc.d ./Core/peripherals/Src/adc.o ./Core/peripherals/Src/adc.su ./Core/peripherals/Src/aht10.cyclo ./Core/peripherals/Src/aht10.d ./Core/peripherals/Src/aht10.o ./Core/peripherals/Src/aht10.su ./Core/peripherals/Src/brightness_control.cyclo ./Core/peripherals/Src/brightness_control.d ./Core/peripherals/Src/brightness_control.o ./Core/peripherals/Src/brightness_control.su ./Core/peripherals/Src/buzzer.cyclo ./Core/peripherals/Src/buzzer.d ./Core/peripherals/Src/buzzer.o ./Core/peripherals/Src/buzzer.su ./Core/peripherals/Src/dfplayer_mini.cyclo ./Core/peripherals/Src/dfplayer_mini.d ./Core/peripherals/Src/dfplayer_mini.o ./Core/peripherals/Src/dfplayer_mini.su ./Core/peripherals/Src/esp.cyclo ./Core/peripherals/Src/esp.d ./Core/peripherals/Src/esp.o ./Core/peripherals/Src/esp.su ./Core/peripherals/Src/ili9486.cyclo ./Core/peripherals/Src/ili9486.d ./Core/peripherals/Src/ili9486.o ./Core/peripherals/Src/ili9486.su ./Core/peripherals/Src/led.cyclo ./Core/peripherals/Src/led.d ./Core/peripherals/Src/led.o ./Core/peripherals/Src/led.su ./Core/peripherals/Src/lv53l0x.cyclo ./Core/peripherals/Src/lv53l0x.d ./Core/peripherals/Src/lv53l0x.o ./Core/peripherals/Src/lv53l0x.su ./Core/peripherals/Src/median.cyclo ./Core/peripherals/Src/median.d ./Core/peripherals/Src/median.o ./Core/peripherals/Src/median.su ./Core/peripherals/Src/range.cyclo ./Core/peripherals/Src/range.d ./Core/peripherals/Src/range.o ./Core/peripherals/Src/range.su ./Core/peripherals/Src/sgp30.cyclo ./Core/peripherals/Src/sgp30.d ./Core/peripherals/Src/sgp30.o ./Core/peripherals/Src/sgp30.su

.PHONY: clean-Core-2f-peripherals-2f-Src

