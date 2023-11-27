#include "../peripherals/Inc/buzzer.h"
#include "stm32f4xx_hal.h"

#define TIMER_BUZZER htim12
#define TIMER_CHANNEL_BUZZER TIM_CHANNEL_1

extern TIM_HandleTypeDef TIMER_BUZZER;

float map_buz(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void buzzer_delay(uint32_t cnt) {
	for (uint32_t  i = 0; i < cnt*100; i++);
}
void start_buzzer(uint16_t time, uint16_t volume) {
	uint16_t freq;
	if (volume > 100)
		volume = 100;
	if (time > 1000)
		time = 1000;
	freq = map_buz(volume, 1, 100, 100, 50000);
	__HAL_TIM_SET_COMPARE(&TIMER_BUZZER, TIM_CHANNEL_1, freq);
	buzzer_delay(time);
	__HAL_TIM_SET_COMPARE(&TIMER_BUZZER, TIM_CHANNEL_1, 0);
}


