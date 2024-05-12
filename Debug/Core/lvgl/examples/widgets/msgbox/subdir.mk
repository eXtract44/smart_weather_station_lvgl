################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.c 

OBJS += \
./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.o 

C_DEPS += \
./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/examples/widgets/msgbox/%.o Core/lvgl/examples/widgets/msgbox/%.su Core/lvgl/examples/widgets/msgbox/%.cyclo: ../Core/lvgl/examples/widgets/msgbox/%.c Core/lvgl/examples/widgets/msgbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-msgbox

clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-msgbox:
	-$(RM) ./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.cyclo ./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.d ./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.o ./Core/lvgl/examples/widgets/msgbox/lv_example_msgbox_1.su

.PHONY: clean-Core-2f-lvgl-2f-examples-2f-widgets-2f-msgbox

