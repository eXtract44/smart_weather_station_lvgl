/*
 * brightness_control.c
 *
 *  Created on: Apr 1, 2024
 *      Author: toose
 */
#include "../peripherals/Inc/brightness_control.h"
#include "../peripherals/Inc/adc.h"


extern TIM_HandleTypeDef htim3;


#define AUTO_BRIGTNESS_MIN 10
#define AUTO_BRIGTNESS_MAX 100
#define BRIGTNESS_MIN 1
#define BRIGTNESS_MAX 100
#define LUX_MIN 20
#define LUX_MAX 360
#define BRIGTNESS_MIN_PROC 0
#define BRIGTNESS_MAX_PROC 100

#define BRIGTNESS_MIN_PROC 0
#define BRIGTNESS_MAX_PROC 100
//-------------------------------------------------------------------
uint32_t map_bri(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void ILI9486_SetBrightness(uint8_t brightness)
/*
//ini PWM Timer in (main.c) HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
*/
{
	if (brightness < 1)
		brightness = 1;
	if (brightness > 100)
		brightness = 100;
	uint16_t compare  = map_bri(brightness, BRIGTNESS_MIN, BRIGTNESS_MAX, htim3.Init.Period, 35000);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, compare);

}

void ILI9486_SetBrightness_Auto()
{
	ILI9486_SetBrightness(map_bri(temt6000_read(), LUX_MIN, LUX_MAX, AUTO_BRIGTNESS_MIN, AUTO_BRIGTNESS_MAX));
}
