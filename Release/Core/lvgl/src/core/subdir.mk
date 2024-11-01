################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/core/lv_disp.c \
../Core/lvgl/src/core/lv_event.c \
../Core/lvgl/src/core/lv_group.c \
../Core/lvgl/src/core/lv_indev.c \
../Core/lvgl/src/core/lv_indev_scroll.c \
../Core/lvgl/src/core/lv_obj.c \
../Core/lvgl/src/core/lv_obj_class.c \
../Core/lvgl/src/core/lv_obj_draw.c \
../Core/lvgl/src/core/lv_obj_pos.c \
../Core/lvgl/src/core/lv_obj_scroll.c \
../Core/lvgl/src/core/lv_obj_style.c \
../Core/lvgl/src/core/lv_obj_style_gen.c \
../Core/lvgl/src/core/lv_obj_tree.c \
../Core/lvgl/src/core/lv_refr.c \
../Core/lvgl/src/core/lv_theme.c 

OBJS += \
./Core/lvgl/src/core/lv_disp.o \
./Core/lvgl/src/core/lv_event.o \
./Core/lvgl/src/core/lv_group.o \
./Core/lvgl/src/core/lv_indev.o \
./Core/lvgl/src/core/lv_indev_scroll.o \
./Core/lvgl/src/core/lv_obj.o \
./Core/lvgl/src/core/lv_obj_class.o \
./Core/lvgl/src/core/lv_obj_draw.o \
./Core/lvgl/src/core/lv_obj_pos.o \
./Core/lvgl/src/core/lv_obj_scroll.o \
./Core/lvgl/src/core/lv_obj_style.o \
./Core/lvgl/src/core/lv_obj_style_gen.o \
./Core/lvgl/src/core/lv_obj_tree.o \
./Core/lvgl/src/core/lv_refr.o \
./Core/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Core/lvgl/src/core/lv_disp.d \
./Core/lvgl/src/core/lv_event.d \
./Core/lvgl/src/core/lv_group.d \
./Core/lvgl/src/core/lv_indev.d \
./Core/lvgl/src/core/lv_indev_scroll.d \
./Core/lvgl/src/core/lv_obj.d \
./Core/lvgl/src/core/lv_obj_class.d \
./Core/lvgl/src/core/lv_obj_draw.d \
./Core/lvgl/src/core/lv_obj_pos.d \
./Core/lvgl/src/core/lv_obj_scroll.d \
./Core/lvgl/src/core/lv_obj_style.d \
./Core/lvgl/src/core/lv_obj_style_gen.d \
./Core/lvgl/src/core/lv_obj_tree.d \
./Core/lvgl/src/core/lv_refr.d \
./Core/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/core/%.o Core/lvgl/src/core/%.su Core/lvgl/src/core/%.cyclo: ../Core/lvgl/src/core/%.c Core/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"C:/ST/ST_Workspace/git/smart_weather_station_lvgl/ESP8266_Weather" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-core

clean-Core-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Core/lvgl/src/core/lv_disp.cyclo ./Core/lvgl/src/core/lv_disp.d ./Core/lvgl/src/core/lv_disp.o ./Core/lvgl/src/core/lv_disp.su ./Core/lvgl/src/core/lv_event.cyclo ./Core/lvgl/src/core/lv_event.d ./Core/lvgl/src/core/lv_event.o ./Core/lvgl/src/core/lv_event.su ./Core/lvgl/src/core/lv_group.cyclo ./Core/lvgl/src/core/lv_group.d ./Core/lvgl/src/core/lv_group.o ./Core/lvgl/src/core/lv_group.su ./Core/lvgl/src/core/lv_indev.cyclo ./Core/lvgl/src/core/lv_indev.d ./Core/lvgl/src/core/lv_indev.o ./Core/lvgl/src/core/lv_indev.su ./Core/lvgl/src/core/lv_indev_scroll.cyclo ./Core/lvgl/src/core/lv_indev_scroll.d ./Core/lvgl/src/core/lv_indev_scroll.o ./Core/lvgl/src/core/lv_indev_scroll.su ./Core/lvgl/src/core/lv_obj.cyclo ./Core/lvgl/src/core/lv_obj.d ./Core/lvgl/src/core/lv_obj.o ./Core/lvgl/src/core/lv_obj.su ./Core/lvgl/src/core/lv_obj_class.cyclo ./Core/lvgl/src/core/lv_obj_class.d ./Core/lvgl/src/core/lv_obj_class.o ./Core/lvgl/src/core/lv_obj_class.su ./Core/lvgl/src/core/lv_obj_draw.cyclo ./Core/lvgl/src/core/lv_obj_draw.d ./Core/lvgl/src/core/lv_obj_draw.o ./Core/lvgl/src/core/lv_obj_draw.su ./Core/lvgl/src/core/lv_obj_pos.cyclo ./Core/lvgl/src/core/lv_obj_pos.d ./Core/lvgl/src/core/lv_obj_pos.o ./Core/lvgl/src/core/lv_obj_pos.su ./Core/lvgl/src/core/lv_obj_scroll.cyclo ./Core/lvgl/src/core/lv_obj_scroll.d ./Core/lvgl/src/core/lv_obj_scroll.o ./Core/lvgl/src/core/lv_obj_scroll.su ./Core/lvgl/src/core/lv_obj_style.cyclo ./Core/lvgl/src/core/lv_obj_style.d ./Core/lvgl/src/core/lv_obj_style.o ./Core/lvgl/src/core/lv_obj_style.su ./Core/lvgl/src/core/lv_obj_style_gen.cyclo ./Core/lvgl/src/core/lv_obj_style_gen.d ./Core/lvgl/src/core/lv_obj_style_gen.o ./Core/lvgl/src/core/lv_obj_style_gen.su ./Core/lvgl/src/core/lv_obj_tree.cyclo ./Core/lvgl/src/core/lv_obj_tree.d ./Core/lvgl/src/core/lv_obj_tree.o ./Core/lvgl/src/core/lv_obj_tree.su ./Core/lvgl/src/core/lv_refr.cyclo ./Core/lvgl/src/core/lv_refr.d ./Core/lvgl/src/core/lv_refr.o ./Core/lvgl/src/core/lv_refr.su ./Core/lvgl/src/core/lv_theme.cyclo ./Core/lvgl/src/core/lv_theme.d ./Core/lvgl/src/core/lv_theme.o ./Core/lvgl/src/core/lv_theme.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-core

