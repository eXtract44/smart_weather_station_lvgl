################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/themes/default/lv_theme_default.c 

OBJS += \
./Core/lvgl/src/extra/themes/default/lv_theme_default.o 

C_DEPS += \
./Core/lvgl/src/extra/themes/default/lv_theme_default.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/themes/default/%.o Core/lvgl/src/extra/themes/default/%.su Core/lvgl/src/extra/themes/default/%.cyclo: ../Core/lvgl/src/extra/themes/default/%.c Core/lvgl/src/extra/themes/default/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-themes-2f-default

clean-Core-2f-lvgl-2f-src-2f-extra-2f-themes-2f-default:
	-$(RM) ./Core/lvgl/src/extra/themes/default/lv_theme_default.cyclo ./Core/lvgl/src/extra/themes/default/lv_theme_default.d ./Core/lvgl/src/extra/themes/default/lv_theme_default.o ./Core/lvgl/src/extra/themes/default/lv_theme_default.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-themes-2f-default

