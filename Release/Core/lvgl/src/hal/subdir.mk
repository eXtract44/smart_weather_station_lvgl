################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/hal/lv_hal_disp.c \
../Core/lvgl/src/hal/lv_hal_indev.c \
../Core/lvgl/src/hal/lv_hal_tick.c 

OBJS += \
./Core/lvgl/src/hal/lv_hal_disp.o \
./Core/lvgl/src/hal/lv_hal_indev.o \
./Core/lvgl/src/hal/lv_hal_tick.o 

C_DEPS += \
./Core/lvgl/src/hal/lv_hal_disp.d \
./Core/lvgl/src/hal/lv_hal_indev.d \
./Core/lvgl/src/hal/lv_hal_tick.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/hal/%.o Core/lvgl/src/hal/%.su Core/lvgl/src/hal/%.cyclo: ../Core/lvgl/src/hal/%.c Core/lvgl/src/hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-hal

clean-Core-2f-lvgl-2f-src-2f-hal:
	-$(RM) ./Core/lvgl/src/hal/lv_hal_disp.cyclo ./Core/lvgl/src/hal/lv_hal_disp.d ./Core/lvgl/src/hal/lv_hal_disp.o ./Core/lvgl/src/hal/lv_hal_disp.su ./Core/lvgl/src/hal/lv_hal_indev.cyclo ./Core/lvgl/src/hal/lv_hal_indev.d ./Core/lvgl/src/hal/lv_hal_indev.o ./Core/lvgl/src/hal/lv_hal_indev.su ./Core/lvgl/src/hal/lv_hal_tick.cyclo ./Core/lvgl/src/hal/lv_hal_tick.d ./Core/lvgl/src/hal/lv_hal_tick.o ./Core/lvgl/src/hal/lv_hal_tick.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-hal

