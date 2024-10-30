#include "../smart_weather_station_lvgl/Core/peripherals/Inc/esp.h"

#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include <../ESP8266_Weather/data.h>

#include "../smart_weather_station_lvgl/Core/peripherals/Inc/median.h"
#include "../smart_weather_station_lvgl/ESP8266_Weather/data.h"

extern UART_HandleTypeDef huart2;

espPacket_ espPacket;

uint8_t rxBuffer[sizeof(espPacket)];
uint8_t dataCorrect = 0;

// UART Callback, um die Daten bei Empfang zu verarbeiten
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {  // Sicherstellen, dass die Daten von USART2 kommen
		// Struktur aus dem rxBuffer in `receivedData` kopieren
		memcpy(&espPacket, rxBuffer, sizeof(espPacket_));
		// Prüfen, ob das Präfix korrekt ist
		if (strncmp(espPacket.uartKey, "ESP", 3) == 0) {
			dataCorrect = 1;
			// Daten sind gültig; Sie können jetzt auf temperature, humidity und lightLevel zugreifen
		}
	}
}

uint8_t read_time_hour() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_hour - espPacket.tm_user_offset_sec / 3600;
	}
	ret = constrain(ret, 0, 23);
	return ret;
}
uint8_t read_time_minute() {
	static uint8_t ret = 0;
		if (dataCorrect) {
			ret = espPacket
		}
		ret = constrain(ret, 0, 23);
		return ret;


	return time_esp.minute;
}
uint8_t read_time_mday() {
	return time_esp.mday;
}
uint8_t read_time_month() {
	return time_esp.month;
}
uint8_t read_time_wday() {
	return time_esp.wday;
}
float map_esp(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
float read_weather_temperature() {
	float temp_w;
	temp_w = (float) weather_esp.temperature_raw;
	temp_w = temp_w / 10.0f;
	return temp_w;
}

uint8_t read_weather_humidity() {
	uint8_t temp = weather_esp.humidity;
	return temp;
}
uint8_t read_weather_wind() {
	//uint8_t temp = map_esp(weather_esp.wind, WEATHER_WIND_MIN, WEATHER_WIND_MAX, 1, 100);
	uint8_t temp = weather_esp.wind;
	if (temp < 0)
		temp = 0;
	if (temp > 60)
		temp = 60;
	return temp;
}
uint8_t read_weather_clouds() {
	uint8_t temp = map_esp(weather_esp.clouds, WEATHER_CLOUD_MIN, WEATHER_CLOUD_MAX, 1, 100);
	if (temp < 1)
		temp = 1;
	if (temp > 100)
		temp = 100;
	return temp;
}
uint8_t read_weather_rain() {
	uint8_t temp = map_esp(weather_esp.rain, WEATHER_RAIN_MIN, WEATHER_RAIN_MAX, 1, 100); /* 1 rain == 0.1 mm*/
	if (temp < 1)
		temp = 1;
	if (temp > 100)
		temp = 100;
	return temp;
}
uint8_t read_weather_snow() {
	uint8_t temp = map_esp(weather_esp.snow, WEATHER_SNOW_MIN, WEATHER_SNOW_MAX, 1, 100); /* 1 rain == 0.1 mm*//* 1 snow == 0.1 mm*/
	if (temp < 1)
		temp = 1;
	if (temp > 100)
		temp = 100;
	return temp;
}
uint16_t read_weather_press() {
	return weather_esp.pressure;
}
uint8_t read_wifi() {
	return weather_esp.wifi; /*5 == connecting, 10 == connected, 20 == disconnected*/
}
/*
 ****** WIND m/s
 0  Windstille        0
 1  leiser Zug        1>
 2  leichte Brise     3>
 3  schwacher Wind    5>
 4  mäßiger Wind      7>
 5  frischer Wind    10>
 6  starker Wind     13>
 7  steifer Wind     17>
 8  stürmischer Wind 20>
 9  Sturm            24>
 *
 *
 ******WOLKEN
 0/8 = wolkenlos

 1/8 = fast wolkenlos 12 %

 2/8= heiter          25%

 3/8 = leicht bewölkt 37%

 4/8 = wolkig         50%

 5/8 = bewölkt        62%

 6/8 = stark bewölkt  75%

 7/8 = fast bedeckt   87%

 8/8 = bedeckt        100%

 ******* REGEN Rain volume for the last 1 hour, mm
 leichter Sprühregen: < 0,1 mm
 mäßiger Sprühregen: ≥ 0,1 mm
 starker Sprühregen: ≥ 0,5 mm
 leichter Regen: < 2,5 mm
 mäßiger Regen: ≥ 2,5 mm bis < 10,0 mm
 starker Regen: ≥ 10,0 mm
 sehr starker Regen: ≥ 50,0 mm

 ******* SCHNEE Snow volume for the last 1 hour, mm
 leichter Schneeschauer: < 0,2 mm (jeweils innerhalb von 10 Minuten)
 mäßiger Schneeschauer: ≥ 0,2 mm bis < 0,9 mm
 starker Schneeschauer: ≥ 0,9 mm
 */

