################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/widgets/animimg/lv_animimg.c 

OBJS += \
./Core/lvgl/src/extra/widgets/animimg/lv_animimg.o 

C_DEPS += \
./Core/lvgl/src/extra/widgets/animimg/lv_animimg.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/widgets/animimg/%.o Core/lvgl/src/extra/widgets/animimg/%.su Core/lvgl/src/extra/widgets/animimg/%.cyclo: ../Core/lvgl/src/extra/widgets/animimg/%.c Core/lvgl/src/extra/widgets/animimg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg

clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg:
	-$(RM) ./Core/lvgl/src/extra/widgets/animimg/lv_animimg.cyclo ./Core/lvgl/src/extra/widgets/animimg/lv_animimg.d ./Core/lvgl/src/extra/widgets/animimg/lv_animimg.o ./Core/lvgl/src/extra/widgets/animimg/lv_animimg.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-animimg

