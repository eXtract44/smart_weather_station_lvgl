################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.c \
../Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.c 

OBJS += \
./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.o \
./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.o 

C_DEPS += \
./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.d \
./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/examples/widgets/checkbox/%.o Core/lvgl/examples/widgets/checkbox/%.su Core/lvgl/examples/widgets/checkbox/%.cyclo: ../Core/lvgl/examples/widgets/checkbox/%.c Core/lvgl/examples/widgets/checkbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-checkbox

clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-checkbox:
	-$(RM) ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.cyclo ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.d ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.o ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_1.su ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.cyclo ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.d ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.o ./Core/lvgl/examples/widgets/checkbox/lv_example_checkbox_2.su

.PHONY: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-checkbox

