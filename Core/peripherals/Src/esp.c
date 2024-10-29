#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "../peripherals/Inc/esp.h"
#include "../peripherals/Inc/median.h"

#include "../ESP8266_Weather/data.h"

extern UART_HandleTypeDef huart2;

espPacket_ espPacket;

uint8_t rxBuffer[sizeof(espPacket)];
uint8_t dataAvailable = 0;

// UART Callback, um die Daten bei Empfang zu verarbeiten
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {  // Sicherstellen, dass die Daten von USART2 kommen
        // Struktur aus dem rxBuffer in `receivedData` kopieren
        memcpy(&espPacket, rxBuffer, sizeof(espPacket_));
        // Prüfen, ob das Präfix korrekt ist
        if (strncmp(espPacket.uartKey, "ESP", 3) == 0) {
        	dataAvailable = 1;
            // Daten sind gültig; Sie können jetzt auf temperature, humidity und lightLevel zugreifen
        }
    }
}






















//TODO

uint8_t uart_esp_rx_buffer[NUMBER_OF_RX_BYTES_ESP] = { 0 };
#define TIME_HOUR_OFFSET 0

//#define SIMULATE_ESP_VALUES

time_t time_esp = { 0 };
weather_t weather_esp = { 0 };

int16_t constrain_values(const int16_t value, int16_t old_value, const int16_t in_min, const int16_t in_max) {
	if (value >= in_min && value < in_max + 1) {
		return value;
	}
	return old_value;
}
bool check_valid() {
	return dataAvailable;
}

void esp_read() {
#ifdef SIMULATE_ESP_VALUES
	static int16_t temp[9] = { 0 };
	static int16_t temp_t = -250;
	static uint16_t temp_p = 850;
	temp[0]++;
	if (temp[0] > 60) {
		temp[0] = 1;
		temp[1]++;
		if (temp[1] > 12)
			temp[1] = 1;
		time_esp.hour = temp[1];
	}
	time_esp.minute = temp[0];

	temp[2]++;
	if (temp[2] > 31){
		temp[2] = 1;
	}

	time_esp.mday = temp[2];

	time_esp.month = temp[1];

	temp[3]++;
	if (temp[3] > 7)
		temp[3] = 1;
	time_esp.wday = temp[3];

	temp[4] = temp[4] + 5;
	if (temp[4] > 100)
		temp[4] = 1;
	weather_esp.clouds = temp[4];

	weather_esp.humidity = temp[4];

	temp[5] = temp[5] + 10;
	if (temp[5] > 500)
		temp[5] = 1;
	weather_esp.rain = temp[5];
	weather_esp.snow = temp[5];

	temp_p = temp_p + 5;
	if (temp_p > 1100)
		temp_p = 830;
	weather_esp.pressure = temp_p;

	weather_esp.wind = temp[4];
	temp[7] = temp[7] + 5;
	if (temp[7] > 20)
		temp[7] = 5;
	weather_esp.wifi = temp[7];

	temp_t = temp_t + 5;
	if (temp_t > 600)
		temp_t = -250;
	weather_esp.temperature_raw = temp_t;

#else
	int16_t value_temp_esp, median_temp_esp = 0;
	if (check_valid(ADDRESS_TIME_MIN)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		//median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_minute], value_temp_esp);
		//time_esp.minute = constrain_values(median_temp_esp, time_esp.minute, 0, 60); /*min 0 max 60 minute*/
		time_esp.minute = constrain_values(value_temp_esp, time_esp.minute, 0, 60); /*min 0 max 60 minute*/
	} else if (check_valid(ADDRESS_TIME_HOUR)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		//median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_hour], value_temp_esp);
		//time_esp.hour = constrain_values(median_temp_esp, time_esp.hour, 0, 24); /*min 0 max 24 hour*/
		time_esp.hour = constrain_values(value_temp_esp, time_esp.hour, 0, 24); /*min 0 max 24 hour*/
	} else if (check_valid(ADDRESS_TIME_MDAY)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_mday], value_temp_esp);
		time_esp.mday = constrain_values(median_temp_esp, time_esp.mday, 1, 31); /*min 1 max 31 mday*/
	} else if (check_valid(ADDRESS_TIME_MON)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_month], value_temp_esp);
		time_esp.month = constrain_values(median_temp_esp, time_esp.month, 1, 12); /*min 1 max 12 month*/
	} else if (check_valid(ADDRESS_TIME_WDAY)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_wday], value_temp_esp);
		time_esp.wday = constrain_values(median_temp_esp, time_esp.wday, 1, 7); /*min 1 max 7 wday*/
	} else if (check_valid(ADDRESS_WEATHER_CLOUD)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_clouds], value_temp_esp);
		weather_esp.clouds = constrain_values(median_temp_esp, weather_esp.clouds, WEATHER_CLOUD_MIN,
				WEATHER_CLOUD_MAX); /*min 0 max 100%*/
	} else if (check_valid(ADDRESS_WEATHER_TEMP)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_temperature_raw], value_temp_esp);
		weather_esp.temperature_raw = constrain_values(median_temp_esp, weather_esp.temperature_raw, WEATHER_TEMP_MIN,
		WEATHER_TEMP_MAX); /* min -25 , max 50*c*/
	} else if (check_valid(ADDRESS_WEATHER_HUMI)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_humidity], value_temp_esp);
		weather_esp.humidity = constrain_values(median_temp_esp, weather_esp.humidity, WEATHER_HUMI_MIN,
				WEATHER_HUMI_MAX); /*min 0 max 100%*/
	} else if (check_valid(ADDRESS_WEATHER_RAIN)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_rain], value_temp_esp);
		weather_esp.rain = constrain_values(median_temp_esp, weather_esp.rain, WEATHER_RAIN_MIN, WEATHER_RAIN_MAX); /*max 50 mm/h*/
	} else if (check_valid(ADDRESS_WEATHER_PRESS)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_pressure], value_temp_esp);
		weather_esp.pressure = constrain_values(median_temp_esp, weather_esp.pressure, WEATHER_PRESS_MIN,
				WEATHER_PRESS_MAX); /*min 750 max 1200 hPa*/
	} else if (check_valid(ADDRESS_WEATHER_WIND)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_wind], value_temp_esp);
		weather_esp.wind = constrain_values(median_temp_esp, weather_esp.wind, WEATHER_WIND_MIN, WEATHER_WIND_MAX); /*max 40m/s*/
	} else if (check_valid(ADDRESS_WIFI_STATUS)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_wifi], value_temp_esp);
		weather_esp.wifi = constrain_values(median_temp_esp, weather_esp.wifi, WEATHER_WIFI_MIN, WEATHER_WIFI_MAX);
	} else if (check_valid(ADDRESS_WEATHER_SNOW)) {
		value_temp_esp = convertBytesToInt16(uart_esp_rx_buffer);
		median_temp_esp = MEDIANFILTER_Insert(&medianFilter_esp[median_snow], value_temp_esp);
		weather_esp.snow = constrain_values(median_temp_esp, weather_esp.snow, WEATHER_SNOW_MIN, WEATHER_SNOW_MAX); /*max 1 mm/h*/
	}
#endif
}

uint8_t read_time_hour() {
	uint8_t temp = 0;
	if(time_esp.hour == 0)temp = 23;
	else temp = time_esp.hour - TIME_HOUR_OFFSET;
	return temp;
}
uint8_t read_time_minute() {
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

