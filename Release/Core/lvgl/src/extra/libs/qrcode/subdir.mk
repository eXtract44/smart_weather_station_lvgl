################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/extra/libs/qrcode/lv_qrcode.c \
../Core/lvgl/src/extra/libs/qrcode/qrcodegen.c 

OBJS += \
./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.o \
./Core/lvgl/src/extra/libs/qrcode/qrcodegen.o 

C_DEPS += \
./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.d \
./Core/lvgl/src/extra/libs/qrcode/qrcodegen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/extra/libs/qrcode/%.o Core/lvgl/src/extra/libs/qrcode/%.su Core/lvgl/src/extra/libs/qrcode/%.cyclo: ../Core/lvgl/src/extra/libs/qrcode/%.c Core/lvgl/src/extra/libs/qrcode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/ST/ST_Workspace/git/smart_weather_station_lvgl/ESP8266_Weather" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode

clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode:
	-$(RM) ./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.cyclo ./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.d ./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.o ./Core/lvgl/src/extra/libs/qrcode/lv_qrcode.su ./Core/lvgl/src/extra/libs/qrcode/qrcodegen.cyclo ./Core/lvgl/src/extra/libs/qrcode/qrcodegen.d ./Core/lvgl/src/extra/libs/qrcode/qrcodegen.o ./Core/lvgl/src/extra/libs/qrcode/qrcodegen.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-extra-2f-libs-2f-qrcode

