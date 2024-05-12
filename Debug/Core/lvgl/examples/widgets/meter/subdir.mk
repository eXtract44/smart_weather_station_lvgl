################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/examples/widgets/meter/lv_example_meter_1.c \
../Core/lvgl/examples/widgets/meter/lv_example_meter_2.c \
../Core/lvgl/examples/widgets/meter/lv_example_meter_3.c \
../Core/lvgl/examples/widgets/meter/lv_example_meter_4.c 

OBJS += \
./Core/lvgl/examples/widgets/meter/lv_example_meter_1.o \
./Core/lvgl/examples/widgets/meter/lv_example_meter_2.o \
./Core/lvgl/examples/widgets/meter/lv_example_meter_3.o \
./Core/lvgl/examples/widgets/meter/lv_example_meter_4.o 

C_DEPS += \
./Core/lvgl/examples/widgets/meter/lv_example_meter_1.d \
./Core/lvgl/examples/widgets/meter/lv_example_meter_2.d \
./Core/lvgl/examples/widgets/meter/lv_example_meter_3.d \
./Core/lvgl/examples/widgets/meter/lv_example_meter_4.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/examples/widgets/meter/%.o Core/lvgl/examples/widgets/meter/%.su Core/lvgl/examples/widgets/meter/%.cyclo: ../Core/lvgl/examples/widgets/meter/%.c Core/lvgl/examples/widgets/meter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-meter

clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-meter:
	-$(RM) ./Core/lvgl/examples/widgets/meter/lv_example_meter_1.cyclo ./Core/lvgl/examples/widgets/meter/lv_example_meter_1.d ./Core/lvgl/examples/widgets/meter/lv_example_meter_1.o ./Core/lvgl/examples/widgets/meter/lv_example_meter_1.su ./Core/lvgl/examples/widgets/meter/lv_example_meter_2.cyclo ./Core/lvgl/examples/widgets/meter/lv_example_meter_2.d ./Core/lvgl/examples/widgets/meter/lv_example_meter_2.o ./Core/lvgl/examples/widgets/meter/lv_example_meter_2.su ./Core/lvgl/examples/widgets/meter/lv_example_meter_3.cyclo ./Core/lvgl/examples/widgets/meter/lv_example_meter_3.d ./Core/lvgl/examples/widgets/meter/lv_example_meter_3.o ./Core/lvgl/examples/widgets/meter/lv_example_meter_3.su ./Core/lvgl/examples/widgets/meter/lv_example_meter_4.cyclo ./Core/lvgl/examples/widgets/meter/lv_example_meter_4.d ./Core/lvgl/examples/widgets/meter/lv_example_meter_4.o ./Core/lvgl/examples/widgets/meter/lv_example_meter_4.su

.PHONY: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-meter

