#include <stdint.h>
#include "../peripherals/Inc/adc.h"
//#define SIMULATE_ADC_VALUES

volatile uint16_t adc_data[NUMBER_OF_ADC_CHANNELS];

float map_adc(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float temt6000_read() {/*IN LUX*/
	float volts = (float)adc_data[ADC_BRIGHTNESS] * V_REFERENCE / ADC_RESOLUTION;
	float amps = volts / 10000.0f;
	float microamps = amps * 1000000.0f;
	float lux = microamps * 2.0f;
	return lux;
}
uint16_t read_battery() {/*IN PROC*/
uint16_t temp = map_adc(adc_data[ADC_BATTERY], 1500, 2200, 0, 100);
	if (temp < 0) {
		temp = 0;
	}
	if (temp > 100) {
		temp = 100;
	}
return temp;
}
uint8_t read_battery_status(){
	uint8_t temp = read_battery();
	if(temp < 20)return 1;
	else if(temp > 20 && temp < 40)return 2;
	else if(temp > 40 && temp < 60)return 3;
	else if(temp > 60 && temp < 80)return 4;
	else if(temp > 80)return 5;
	else return 0;
}
uint16_t read_potentiometer() {/*IN PROC*/
uint16_t temp = map_adc(adc_data[ADC_POT], 10, 4090, 0, 30);
	if (temp < 0) {
		temp = 0;
	}
	if (temp > 30) {
		temp = 30;
	}
return temp;
}
uint8_t read_volume_dfplayer() {
	if (read_potentiometer() < 4)
		return 1;
	else if (read_potentiometer() > 5 && read_potentiometer() < 15)
		return 2;
	else if (read_potentiometer() > 24)
		return 3;
}


//void simulate_adc_values(){
//	static uint16_t temp = 1500;
//	static uint16_t temp1 = 0;
//	temp =temp+100;
//	temp1 =temp1+100;
//	if(temp1 > 4090)temp1 = 0;
//	if(temp > 4090)temp = 1500;
//	adc_data[ADC_BATTERY] = temp;
//	adc_data[ADC_BRIGHTNESS] = temp1;
//}
