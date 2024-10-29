################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/gpu/lv_gpu_nxp_pxp.c \
../Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.c \
../Core/lvgl/src/gpu/lv_gpu_nxp_vglite.c \
../Core/lvgl/src/gpu/lv_gpu_sdl.c \
../Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.o \
./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o \
./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.o \
./Core/lvgl/src/gpu/lv_gpu_sdl.o \
./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.d \
./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d \
./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.d \
./Core/lvgl/src/gpu/lv_gpu_sdl.d \
./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/gpu/%.o Core/lvgl/src/gpu/%.su Core/lvgl/src/gpu/%.cyclo: ../Core/lvgl/src/gpu/%.c Core/lvgl/src/gpu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-gpu

clean-Core-2f-lvgl-2f-src-2f-gpu:
	-$(RM) ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.cyclo ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.d ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.o ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp.su ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.cyclo ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o ./Core/lvgl/src/gpu/lv_gpu_nxp_pxp_osa.su ./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.cyclo ./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.d ./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.o ./Core/lvgl/src/gpu/lv_gpu_nxp_vglite.su ./Core/lvgl/src/gpu/lv_gpu_sdl.cyclo ./Core/lvgl/src/gpu/lv_gpu_sdl.d ./Core/lvgl/src/gpu/lv_gpu_sdl.o ./Core/lvgl/src/gpu/lv_gpu_sdl.su ./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.cyclo ./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.d ./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.o ./Core/lvgl/src/gpu/lv_gpu_stm32_dma2d.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-gpu

