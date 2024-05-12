################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.c \
../Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.c 

OBJS += \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.o \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.o 

C_DEPS += \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.d \
./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/lvgl/src/gpu/sdl/%.o Core/lvgl/src/gpu/sdl/%.su Core/lvgl/src/gpu/sdl/%.cyclo: ../Core/lvgl/src/gpu/sdl/%.c Core/lvgl/src/gpu/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-lvgl-2f-src-2f-gpu-2f-sdl

clean-Core-2f-lvgl-2f-src-2f-gpu-2f-sdl:
	-$(RM) ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_arc.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_blend.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_img.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_label.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_line.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_draw_rect.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_lru.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_mask.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_stack_blur.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_texture_cache.su ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.cyclo ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.d ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.o ./Core/lvgl/src/gpu/sdl/lv_gpu_sdl_utils.su

.PHONY: clean-Core-2f-lvgl-2f-src-2f-gpu-2f-sdl

