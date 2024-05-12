################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/examples/styles/lv_example_style_1.c \
../Core/lvgl/examples/styles/lv_example_style_10.c \
../Core/lvgl/examples/styles/lv_example_style_11.c \
../Core/lvgl/examples/styles/lv_example_style_12.c \
../Core/lvgl/examples/styles/lv_example_style_13.c \
../Core/lvgl/examples/styles/lv_example_style_14.c \
../Core/lvgl/examples/styles/lv_example_style_2.c \
../Core/lvgl/examples/styles/lv_example_style_3.c \
../Core/lvgl/examples/styles/lv_example_style_4.c \
../Core/lvgl/examples/styles/lv_example_style_5.c \
../Core/lvgl/examples/styles/lv_example_style_6.c \
../Core/lvgl/examples/styles/lv_example_style_7.c \
../Core/lvgl/examples/styles/lv_example_style_8.c \
../Core/lvgl/examples/styles/lv_example_style_9.c 

OBJS += \
./Core/lvgl/examples/styles/lv_example_style_1.o \
./Core/lvgl/examples/styles/lv_example_style_10.o \
./Core/lvgl/examples/styles/lv_example_style_11.o \
./Core/lvgl/examples/styles/lv_example_style_12.o \
./Core/lvgl/examples/styles/lv_example_style_13.o \
./Core/lvgl/examples/styles/lv_example_style_14.o \
./Core/lvgl/examples/styles/lv_example_style_2.o \
./Core/lvgl/examples/styles/lv_example_style_3.o \
./Core/lvgl/examples/styles/lv_example_style_4.o \
./Core/lvgl/examples/styles/lv_example_style_5.o \
./Core/lvgl/examples/styles/lv_example_style_6.o \
./Core/lvgl/examples/styles/lv_example_style_7.o \
./Core/lvgl/examples/styles/lv_example_style_8.o \
./Core/lvgl/examples/styles/lv_example_style_9.o 

C_DEPS += \
./Core/lvgl/examples/styles/lv_example_style_1.d \
./Core/lvgl/examples/styles/lv_example_style_10.d \
./Core/lvgl/examples/styles/lv_example_style_11.d \
./Core/lvgl/examples/styles/lv_example_style_12.d \
./Core/lvgl/examples/styles/lv_example_style_13.d \
./Core/lvgl/examples/styles/lv_example_style_14.d \
./Core/lvgl/examples/styles/lv_example_style_2.d \
./Core/lvgl/examples/styles/lv_example_style_3.d \
./Core/lvgl/examples/styles/lv_example_style_4.d \
./Core/lvgl/examples/styles/lv_example_style_5.d \
./Core/lvgl/examples/styles/lv_example_style_6.d \
./Core/lvgl/examples/styles/lv_example_style_7.d \
./Core/lvgl/examples/styles/lv_example_style_8.d \
./Core/lvgl/examples/styles/lv_example_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/examples/styles/%.o Core/lvgl/examples/styles/%.su Core/lvgl/examples/styles/%.cyclo: ../Core/lvgl/examples/styles/%.c Core/lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-examples-2f-styles

clean-Core-2f-lvgl-2f-examples-2f-styles:
	-$(RM) ./Core/lvgl/examples/styles/lv_example_style_1.cyclo ./Core/lvgl/examples/styles/lv_example_style_1.d ./Core/lvgl/examples/styles/lv_example_style_1.o ./Core/lvgl/examples/styles/lv_example_style_1.su ./Core/lvgl/examples/styles/lv_example_style_10.cyclo ./Core/lvgl/examples/styles/lv_example_style_10.d ./Core/lvgl/examples/styles/lv_example_style_10.o ./Core/lvgl/examples/styles/lv_example_style_10.su ./Core/lvgl/examples/styles/lv_example_style_11.cyclo ./Core/lvgl/examples/styles/lv_example_style_11.d ./Core/lvgl/examples/styles/lv_example_style_11.o ./Core/lvgl/examples/styles/lv_example_style_11.su ./Core/lvgl/examples/styles/lv_example_style_12.cyclo ./Core/lvgl/examples/styles/lv_example_style_12.d ./Core/lvgl/examples/styles/lv_example_style_12.o ./Core/lvgl/examples/styles/lv_example_style_12.su ./Core/lvgl/examples/styles/lv_example_style_13.cyclo ./Core/lvgl/examples/styles/lv_example_style_13.d ./Core/lvgl/examples/styles/lv_example_style_13.o ./Core/lvgl/examples/styles/lv_example_style_13.su ./Core/lvgl/examples/styles/lv_example_style_14.cyclo ./Core/lvgl/examples/styles/lv_example_style_14.d ./Core/lvgl/examples/styles/lv_example_style_14.o ./Core/lvgl/examples/styles/lv_example_style_14.su ./Core/lvgl/examples/styles/lv_example_style_2.cyclo ./Core/lvgl/examples/styles/lv_example_style_2.d ./Core/lvgl/examples/styles/lv_example_style_2.o ./Core/lvgl/examples/styles/lv_example_style_2.su ./Core/lvgl/examples/styles/lv_example_style_3.cyclo ./Core/lvgl/examples/styles/lv_example_style_3.d ./Core/lvgl/examples/styles/lv_example_style_3.o ./Core/lvgl/examples/styles/lv_example_style_3.su ./Core/lvgl/examples/styles/lv_example_style_4.cyclo ./Core/lvgl/examples/styles/lv_example_style_4.d ./Core/lvgl/examples/styles/lv_example_style_4.o ./Core/lvgl/examples/styles/lv_example_style_4.su ./Core/lvgl/examples/styles/lv_example_style_5.cyclo ./Core/lvgl/examples/styles/lv_example_style_5.d ./Core/lvgl/examples/styles/lv_example_style_5.o ./Core/lvgl/examples/styles/lv_example_style_5.su ./Core/lvgl/examples/styles/lv_example_style_6.cyclo ./Core/lvgl/examples/styles/lv_example_style_6.d ./Core/lvgl/examples/styles/lv_example_style_6.o ./Core/lvgl/examples/styles/lv_example_style_6.su ./Core/lvgl/examples/styles/lv_example_style_7.cyclo ./Core/lvgl/examples/styles/lv_example_style_7.d ./Core/lvgl/examples/styles/lv_example_style_7.o ./Core/lvgl/examples/styles/lv_example_style_7.su ./Core/lvgl/examples/styles/lv_example_style_8.cyclo ./Core/lvgl/examples/styles/lv_example_style_8.d ./Core/lvgl/examples/styles/lv_example_style_8.o ./Core/lvgl/examples/styles/lv_example_style_8.su ./Core/lvgl/examples/styles/lv_example_style_9.cyclo ./Core/lvgl/examples/styles/lv_example_style_9.d ./Core/lvgl/examples/styles/lv_example_style_9.o ./Core/lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-Core-2f-lvgl-2f-examples-2f-styles

