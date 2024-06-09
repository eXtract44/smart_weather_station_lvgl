/*
 * esp.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Alex
 */

#ifndef INC_ESP_H_
#define INC_ESP_H_

#define NUMBER_OF_RX_BYTES_ESP 4


#define _Check 0xFE
#define TIME_DAY_START 7
#define TIME_DAY_END 22
#define ADDRESS_TIME_MIN 0x00
#define ADDRESS_TIME_HOUR 0x0A
#define ADDRESS_TIME_MDAY 0x14
#define ADDRESS_TIME_MON 0x1E
#define ADDRESS_TIME_WDAY 0x28

#define ADDRESS_WEATHER_TEMP 0x32
#define ADDRESS_WEATHER_HUMI 0x3C
#define ADDRESS_WEATHER_PRESS 0x46
#define ADDRESS_WEATHER_WIND 0x50
#define ADDRESS_WEATHER_CLOUD 0x5A
#define ADDRESS_WEATHER_RAIN 0x64
#define ADDRESS_WEATHER_SNOW 0x6E

#define ADDRESS_WIFI_STATUS 0xFA


#define WEATHER_TEMP_MIN -250
#define WEATHER_TEMP_MAX 500
#define WEATHER_HUMI_MIN 0
#define WEATHER_HUMI_MAX 100
#define WEATHER_CLOUD_MIN 0
#define WEATHER_CLOUD_MAX 100
#define WEATHER_PRESS_MIN 750
#define WEATHER_PRESS_MAX 1250
#define WEATHER_WIND_MIN 0
#define WEATHER_WIND_MAX 40
#define WEATHER_RAIN_MIN 0
#define WEATHER_RAIN_MAX 500
#define WEATHER_SNOW_MIN 0
#define WEATHER_SNOW_MAX 10
#define WEATHER_WIFI_MIN 5
#define WEATHER_WIFI_MAX 20

#define WIFI_CONNECTING 5
#define WIFI_CONNECTED 10
#define WIFI_DISCONNECTED 20



typedef struct
{
	uint8_t hour;
	uint8_t minute;
	uint8_t month;
	uint8_t mday;
	uint8_t wday;

}time_t;

typedef struct
{
	int16_t temperature_raw;
	uint16_t humidity;
	uint16_t pressure;
	uint16_t wind;
	uint16_t clouds;
	uint16_t rain;    //rain_mm/1h = snow_1h * 10
	uint16_t snow;    //snow_mm/1h = snow_1h * 10
	uint8_t wifi; // 5 load, 10 on, 20 off
}weather_t;



uint8_t read_time_hour();
uint8_t read_time_minute();
uint8_t read_time_mday();
uint8_t read_time_month();
uint8_t read_time_wday();

float read_weather_temperature();
uint8_t read_weather_humidity();
uint8_t read_weather_wind();
uint8_t read_weather_clouds();
uint8_t read_weather_rain();
uint8_t read_weather_snow();
uint16_t read_weather_press();
uint8_t read_wifi();
int16_t convertBytesToInt16(const uint8_t* bytes);
void esp_read_weather();
void esp_read_time();
void esp_read();
void init_filter_esp();
#endif /* INC_ESP_H_ */
