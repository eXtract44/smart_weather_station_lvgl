#include "../smart_weather_station_lvgl/Core/peripherals/Inc/led.h"

#include "stm32f4xx_hal.h"

#include "../smart_weather_station_lvgl/Core/Inc/main.h"



void turn_led_on(){
	HAL_GPIO_WritePin(LED_STM_GPIO_Port, LED_STM_Pin,GPIO_PIN_SET);
}
void turn_led_off(){
	HAL_GPIO_WritePin(LED_STM_GPIO_Port, LED_STM_Pin,GPIO_PIN_RESET);
}
void toggle_led(){
	HAL_GPIO_TogglePin(LED_STM_GPIO_Port, LED_STM_Pin);
}

