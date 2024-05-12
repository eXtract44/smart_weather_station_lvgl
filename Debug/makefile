################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/peripherals/Src/subdir.mk
-include Core/menu/Scr/subdir.mk
-include Core/lvgl/src/widgets/subdir.mk
-include Core/lvgl/src/misc/subdir.mk
-include Core/lvgl/src/hal/subdir.mk
-include Core/lvgl/src/gpu/sdl/subdir.mk
-include Core/lvgl/src/gpu/subdir.mk
-include Core/lvgl/src/font/subdir.mk
-include Core/lvgl/src/extra/widgets/win/subdir.mk
-include Core/lvgl/src/extra/widgets/tileview/subdir.mk
-include Core/lvgl/src/extra/widgets/tabview/subdir.mk
-include Core/lvgl/src/extra/widgets/spinner/subdir.mk
-include Core/lvgl/src/extra/widgets/spinbox/subdir.mk
-include Core/lvgl/src/extra/widgets/span/subdir.mk
-include Core/lvgl/src/extra/widgets/msgbox/subdir.mk
-include Core/lvgl/src/extra/widgets/meter/subdir.mk
-include Core/lvgl/src/extra/widgets/list/subdir.mk
-include Core/lvgl/src/extra/widgets/led/subdir.mk
-include Core/lvgl/src/extra/widgets/keyboard/subdir.mk
-include Core/lvgl/src/extra/widgets/imgbtn/subdir.mk
-include Core/lvgl/src/extra/widgets/colorwheel/subdir.mk
-include Core/lvgl/src/extra/widgets/chart/subdir.mk
-include Core/lvgl/src/extra/widgets/calendar/subdir.mk
-include Core/lvgl/src/extra/widgets/animimg/subdir.mk
-include Core/lvgl/src/extra/themes/mono/subdir.mk
-include Core/lvgl/src/extra/themes/default/subdir.mk
-include Core/lvgl/src/extra/themes/basic/subdir.mk
-include Core/lvgl/src/extra/others/snapshot/subdir.mk
-include Core/lvgl/src/extra/libs/sjpg/subdir.mk
-include Core/lvgl/src/extra/libs/qrcode/subdir.mk
-include Core/lvgl/src/extra/libs/png/subdir.mk
-include Core/lvgl/src/extra/libs/gif/subdir.mk
-include Core/lvgl/src/extra/libs/fsdrv/subdir.mk
-include Core/lvgl/src/extra/libs/freetype/subdir.mk
-include Core/lvgl/src/extra/libs/bmp/subdir.mk
-include Core/lvgl/src/extra/layouts/grid/subdir.mk
-include Core/lvgl/src/extra/layouts/flex/subdir.mk
-include Core/lvgl/src/extra/subdir.mk
-include Core/lvgl/src/draw/subdir.mk
-include Core/lvgl/src/core/subdir.mk
-include Core/lvgl/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := F446_LVGL_SMARTROOM
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F446_LVGL_SMARTROOM.elf \

MAP_FILES += \
F446_LVGL_SMARTROOM.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F446_LVGL_SMARTROOM.list \

OBJCOPY_BIN += \
F446_LVGL_SMARTROOM.bin \


# All Target
all: main-build

# Main-build Target
main-build: F446_LVGL_SMARTROOM.elf secondary-outputs

# Tool invocations
F446_LVGL_SMARTROOM.elf F446_LVGL_SMARTROOM.map: $(OBJS) $(USER_OBJS) C:\ST\ST_Workspace\F446_LVGL_SMARTROOM\STM32F446VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F446_LVGL_SMARTROOM.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\ST\ST_Workspace\F446_LVGL_SMARTROOM\STM32F446VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="F446_LVGL_SMARTROOM.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F446_LVGL_SMARTROOM.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F446_LVGL_SMARTROOM.list"
	@echo 'Finished building: $@'
	@echo ' '

F446_LVGL_SMARTROOM.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "F446_LVGL_SMARTROOM.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F446_LVGL_SMARTROOM.bin F446_LVGL_SMARTROOM.elf F446_LVGL_SMARTROOM.list F446_LVGL_SMARTROOM.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
