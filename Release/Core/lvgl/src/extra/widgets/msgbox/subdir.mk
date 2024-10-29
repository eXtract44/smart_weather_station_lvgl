################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.c 

OBJS += \
./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.o 

C_DEPS += \
./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/widgets/msgbox/%.o Core/lvgl/src/extra/widgets/msgbox/%.su Core/lvgl/src/extra/widgets/msgbox/%.cyclo: ../Core/lvgl/src/extra/widgets/msgbox/%.c Core/lvgl/src/extra/widgets/msgbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/ST/ST_Workspace/git/smart_weather_station_lvgl/ESP8266_Weather" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-msgbox

clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-msgbox:
	-$(RM) ./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.cyclo ./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.d ./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.o ./Core/lvgl/src/extra/widgets/msgbox/lv_msgbox.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-msgbox

