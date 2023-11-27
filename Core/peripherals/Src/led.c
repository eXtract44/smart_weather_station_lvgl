#include "stm32f4xx_hal.h"
#include "../peripherals/Inc/led.h"


#define LED_PIN GPIO_PIN_12
#define LED_PORT GPIOB



void turn_led_on(){
	HAL_GPIO_WritePin(LED_PORT, LED_PIN,GPIO_PIN_SET);
}
void turn_led_off(){
	HAL_GPIO_WritePin(LED_PORT, LED_PIN,GPIO_PIN_RESET);
}
void toggle_led(){
	HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
}

