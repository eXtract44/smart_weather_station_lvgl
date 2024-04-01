/*
 * brightness_control.c
 *
 *  Created on: Apr 1, 2024
 *      Author: toose
 */
#include "../peripherals/Inc/brightness_control.h"
#include "../peripherals/Inc/adc.h"


extern TIM_HandleTypeDef htim3;

#define BRIGTNESS_MIN 25
#define BRIGTNESS_MAX 100
#define LUX_MIN 35
#define LUX_MAX 360
#define BRIGTNESS_MIN_PROC 0
#define BRIGTNESS_MAX_PROC 100
//-------------------------------------------------------------------
uint32_t map_bri(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void ILI9486_SetBrightness(uint8_t brightness)
/*
htim3.Init.Prescaler = 0;
htim3.Init.Period = 1000;
//ini PWM Timer in (main.c) HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
*/
{
	if(brightness > BRIGTNESS_MAX_PROC)brightness=BRIGTNESS_MAX_PROC;
	if(brightness < BRIGTNESS_MIN_PROC)brightness=BRIGTNESS_MIN_PROC;
	 float i = map_bri(brightness, BRIGTNESS_MIN_PROC, BRIGTNESS_MAX_PROC, htim3.Init.Period, 0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, i);
}

void ILI9486_SetBrightness_Auto()
{
	uint16_t temp = (uint16_t)(map_bri(temt6000_read(), LUX_MIN, LUX_MAX, BRIGTNESS_MIN, BRIGTNESS_MAX));
	ILI9486_SetBrightness(temp);
}
