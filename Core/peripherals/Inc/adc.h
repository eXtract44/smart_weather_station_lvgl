/*
 * adc.h
 *
 *  Created on: 17.06.2023
 *      Author: Alex
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#define NUMBER_OF_ADC_CHANNELS 3
#define V_REFERENCE 3.30f
#define ADC_RESOLUTION 4095.0f




enum adc_channel {
	ADC_BATTERY, ADC_BRIGHTNESS,ADC_POT,

};

float temt6000_read();
uint16_t read_battery();
uint8_t read_battery_status();
uint16_t read_potentiometer();
uint8_t read_volume_dfplayer();


float map_adc(float x, float in_min, float in_max, float out_min, float out_max);

#endif /* INC_ADC_H_ */
