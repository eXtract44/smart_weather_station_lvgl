################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/menu/Scr/cloud.c \
../Core/menu/Scr/lvgl_menu.c \
../Core/menu/Scr/moon.c \
../Core/menu/Scr/rain.c \
../Core/menu/Scr/snow.c \
../Core/menu/Scr/sun.c \
../Core/menu/Scr/wind.c 

OBJS += \
./Core/menu/Scr/cloud.o \
./Core/menu/Scr/lvgl_menu.o \
./Core/menu/Scr/moon.o \
./Core/menu/Scr/rain.o \
./Core/menu/Scr/snow.o \
./Core/menu/Scr/sun.o \
./Core/menu/Scr/wind.o 

C_DEPS += \
./Core/menu/Scr/cloud.d \
./Core/menu/Scr/lvgl_menu.d \
./Core/menu/Scr/moon.d \
./Core/menu/Scr/rain.d \
./Core/menu/Scr/snow.d \
./Core/menu/Scr/sun.d \
./Core/menu/Scr/wind.d 


# Each subdirectory must supply rules for building sources it contributes
Core/menu/Scr/%.o Core/menu/Scr/%.su Core/menu/Scr/%.cyclo: ../Core/menu/Scr/%.c Core/menu/Scr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-menu-2f-Scr

clean-Core-2f-menu-2f-Scr:
	-$(RM) ./Core/menu/Scr/cloud.cyclo ./Core/menu/Scr/cloud.d ./Core/menu/Scr/cloud.o ./Core/menu/Scr/cloud.su ./Core/menu/Scr/lvgl_menu.cyclo ./Core/menu/Scr/lvgl_menu.d ./Core/menu/Scr/lvgl_menu.o ./Core/menu/Scr/lvgl_menu.su ./Core/menu/Scr/moon.cyclo ./Core/menu/Scr/moon.d ./Core/menu/Scr/moon.o ./Core/menu/Scr/moon.su ./Core/menu/Scr/rain.cyclo ./Core/menu/Scr/rain.d ./Core/menu/Scr/rain.o ./Core/menu/Scr/rain.su ./Core/menu/Scr/snow.cyclo ./Core/menu/Scr/snow.d ./Core/menu/Scr/snow.o ./Core/menu/Scr/snow.su ./Core/menu/Scr/sun.cyclo ./Core/menu/Scr/sun.d ./Core/menu/Scr/sun.o ./Core/menu/Scr/sun.su ./Core/menu/Scr/wind.cyclo ./Core/menu/Scr/wind.d ./Core/menu/Scr/wind.o ./Core/menu/Scr/wind.su

.PHONY: clean-Core-2f-menu-2f-Scr

