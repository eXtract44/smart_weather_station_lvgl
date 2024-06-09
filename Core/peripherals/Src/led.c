#include "stm32f4xx_hal.h"
#include "../peripherals/Inc/led.h"


#define LED_PIN GPIO_PIN_12 //blue
#define LED_PORT GPIOB      //blue

#define LED_PIN_GREEN GPIO_PIN_8
#define LED_PORT_GREEN GPIOD

#define LED_PIN_RED GPIO_PIN_5
#define LED_PORT_RED GPIOC



void turn_led_on(){
	HAL_GPIO_WritePin(LED_PORT, LED_PIN,GPIO_PIN_SET);
}
void turn_led_off(){
	HAL_GPIO_WritePin(LED_PORT, LED_PIN,GPIO_PIN_RESET);
}
void toggle_led(){
	HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
}

