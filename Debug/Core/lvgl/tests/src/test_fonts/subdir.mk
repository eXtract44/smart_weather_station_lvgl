################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/tests/src/test_fonts/font_1.c \
../Core/lvgl/tests/src/test_fonts/font_2.c \
../Core/lvgl/tests/src/test_fonts/font_3.c 

OBJS += \
./Core/lvgl/tests/src/test_fonts/font_1.o \
./Core/lvgl/tests/src/test_fonts/font_2.o \
./Core/lvgl/tests/src/test_fonts/font_3.o 

C_DEPS += \
./Core/lvgl/tests/src/test_fonts/font_1.d \
./Core/lvgl/tests/src/test_fonts/font_2.d \
./Core/lvgl/tests/src/test_fonts/font_3.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/tests/src/test_fonts/%.o Core/lvgl/tests/src/test_fonts/%.su Core/lvgl/tests/src/test_fonts/%.cyclo: ../Core/lvgl/tests/src/test_fonts/%.c Core/lvgl/tests/src/test_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-tests-2f-src-2f-test_fonts

clean-Core-2f-lvgl-2f-tests-2f-src-2f-test_fonts:
	-$(RM) ./Core/lvgl/tests/src/test_fonts/font_1.cyclo ./Core/lvgl/tests/src/test_fonts/font_1.d ./Core/lvgl/tests/src/test_fonts/font_1.o ./Core/lvgl/tests/src/test_fonts/font_1.su ./Core/lvgl/tests/src/test_fonts/font_2.cyclo ./Core/lvgl/tests/src/test_fonts/font_2.d ./Core/lvgl/tests/src/test_fonts/font_2.o ./Core/lvgl/tests/src/test_fonts/font_2.su ./Core/lvgl/tests/src/test_fonts/font_3.cyclo ./Core/lvgl/tests/src/test_fonts/font_3.d ./Core/lvgl/tests/src/test_fonts/font_3.o ./Core/lvgl/tests/src/test_fonts/font_3.su

.PHONY: clean-Core-2f-lvgl-2f-tests-2f-src-2f-test_fonts

