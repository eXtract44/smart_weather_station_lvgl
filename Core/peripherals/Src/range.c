#include "../peripherals/Inc/led.h"
#include "../Inc/vl53l0x.h"
#include "../Inc/range.h"
#include "../Inc/brightness_control.h"
#include <stdint.h>

uint16_t cnt_standby = 0;

uint16_t read_standby_time() {
	return cnt_standby;
}
uint8_t range_read(){
	uint16_t current_range = vl53_read_cm();
	if (current_range < RANGE_STEP) {
		return RANGE_1;
	} else {
		return RANGE_0;
	}
}
void range_handler() { //1 tick ~500mS
	static uint16_t delay_ = 0;
	uint16_t current_range = vl53_read_cm();
	if (current_range < RANGE_STEP && current_range > RANGE_MIN) {
		toggle_led();
		delay_++;
		if (delay_ > ACTIVATION_DELAY) {
			ILI9486_SetBrightness(100);
			delay_ = 0;
			cnt_standby = 0;
		}
	} else {
		turn_led_off();
		delay_ = 0;
		cnt_standby++;
		if (cnt_standby > TIME_STANDBY) {
			ILI9486_SetBrightness(0);
			cnt_standby = TIME_STANDBY+1;
		} else {
			ILI9486_SetBrightness_Auto();
		}
	}
}
