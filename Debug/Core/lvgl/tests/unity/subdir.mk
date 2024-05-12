################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/tests/unity/unity.c \
../Core/lvgl/tests/unity/unity_support.c 

OBJS += \
./Core/lvgl/tests/unity/unity.o \
./Core/lvgl/tests/unity/unity_support.o 

C_DEPS += \
./Core/lvgl/tests/unity/unity.d \
./Core/lvgl/tests/unity/unity_support.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/tests/unity/%.o Core/lvgl/tests/unity/%.su Core/lvgl/tests/unity/%.cyclo: ../Core/lvgl/tests/unity/%.c Core/lvgl/tests/unity/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-tests-2f-unity

clean-Core-2f-lvgl-2f-tests-2f-unity:
	-$(RM) ./Core/lvgl/tests/unity/unity.cyclo ./Core/lvgl/tests/unity/unity.d ./Core/lvgl/tests/unity/unity.o ./Core/lvgl/tests/unity/unity.su ./Core/lvgl/tests/unity/unity_support.cyclo ./Core/lvgl/tests/unity/unity_support.d ./Core/lvgl/tests/unity/unity_support.o ./Core/lvgl/tests/unity/unity_support.su

.PHONY: clean-Core-2f-lvgl-2f-tests-2f-unity

