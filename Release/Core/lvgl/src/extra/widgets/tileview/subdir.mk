################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/widgets/tileview/lv_tileview.c 

OBJS += \
./Core/lvgl/src/extra/widgets/tileview/lv_tileview.o 

C_DEPS += \
./Core/lvgl/src/extra/widgets/tileview/lv_tileview.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/widgets/tileview/%.o Core/lvgl/src/extra/widgets/tileview/%.su Core/lvgl/src/extra/widgets/tileview/%.cyclo: ../Core/lvgl/src/extra/widgets/tileview/%.c Core/lvgl/src/extra/widgets/tileview/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/ST/ST_Workspace/git/smart_weather_station_lvgl/ESP8266_Weather" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview

clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview:
	-$(RM) ./Core/lvgl/src/extra/widgets/tileview/lv_tileview.cyclo ./Core/lvgl/src/extra/widgets/tileview/lv_tileview.d ./Core/lvgl/src/extra/widgets/tileview/lv_tileview.o ./Core/lvgl/src/extra/widgets/tileview/lv_tileview.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-tileview

