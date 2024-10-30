/*
 * esp.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Alex
 */

#ifndef INC_ESP_H_
#define INC_ESP_H_

#include "stm32f4xx_hal.h"
#include "../Core/peripherals/Inc/healper.h"
#include "../ESP8266_Weather/data.h"

uint8_t get_time_second();
uint8_t get_time_minute();
uint8_t get_time_hour();

uint8_t get_time_mday();
uint8_t get_time_month();
uint8_t get_time_wday();

uint8_t get_start_day();
uint8_t get_start_day();

float get_weather_temperature();
uint8_t get_weather_humidity();
float get_weather_wind();
uint8_t get_weather_clouds();
float get_weather_rain();
float get_weather_snow();
uint16_t get_weather_press();
uint8_t get_wifi();

#endif /* INC_ESP_H_ */
