################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/rt-thread/lv_rt_thread_port.c 

OBJS += \
./Core/lvgl/rt-thread/lv_rt_thread_port.o 

C_DEPS += \
./Core/lvgl/rt-thread/lv_rt_thread_port.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/rt-thread/%.o Core/lvgl/rt-thread/%.su Core/lvgl/rt-thread/%.cyclo: ../Core/lvgl/rt-thread/%.c Core/lvgl/rt-thread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-rt-2d-thread

clean-Core-2f-lvgl-2f-rt-2d-thread:
	-$(RM) ./Core/lvgl/rt-thread/lv_rt_thread_port.cyclo ./Core/lvgl/rt-thread/lv_rt_thread_port.d ./Core/lvgl/rt-thread/lv_rt_thread_port.o ./Core/lvgl/rt-thread/lv_rt_thread_port.su

.PHONY: clean-Core-2f-lvgl-2f-rt-2d-thread

