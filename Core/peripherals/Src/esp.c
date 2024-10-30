#include "../Core/peripherals/Inc/esp.h"

extern UART_HandleTypeDef huart2;

espPacket_ espPacket;

uint8_t rxBuffer[sizeof(espPacket)];
uint8_t dataCorrect = 0;

// UART Callback, um die Daten bei Empfang zu verarbeiten
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) { // Sicherstellen, dass die Daten von USART2 kommen
		// Struktur aus dem rxBuffer in `receivedData` kopieren
		memcpy(&espPacket, rxBuffer, sizeof(espPacket_));
		// Prüfen, ob das Präfix korrekt ist
		if (strncmp(espPacket.uartKey, "ESP", 3) == 0) {
			dataCorrect = 1;
			// Daten sind gültig; Sie können jetzt auf temperature, humidity und lightLevel zugreifen
		}
	}
}
uint8_t get_time_second() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_min;
	}
	ret = constrain(ret, 0, 59);
	return ret;
}
uint8_t get_time_minute() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_min;
	}
	ret = constrain(ret, 0, 59);
	return ret;
}

uint8_t get_time_hour() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_hour - espPacket.tm_user_offset_sec / 3600;
	}
	ret = constrain(ret, 0, 23);
	return ret;
}

uint8_t get_time_mday() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_mday;
	}
	ret = constrain(ret, 1, 31);
	return ret;
}
uint8_t get_time_month() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_mon;
	}
	ret = constrain(ret, 1, 12);
	return ret;
}
uint8_t get_time_wday() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_wday;
	}
	ret = constrain(ret, 1, 7);
	return ret;
}

uint8_t get_start_day() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_user_day_start_hour;
	}
	ret = constrain(ret, 0, 23);
	return ret;
}
uint8_t get_end_day() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.tm_user_day_end_hour;
	}
	ret = constrain(ret, 0, 23);
	return ret;
}

float get_weather_temperature() {
	static float ret = 0;
	if (dataCorrect) {
		ret = espPacket.main_temp;
	}
	ret = constrain(ret, -20, 60);
	return ret;
}

uint8_t get_weather_humidity() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.main_humidity;
	}
	ret = constrain(ret, 0, 100);
	return ret;
}
float get_weather_wind() {
	static float ret = 0;
	if (dataCorrect) {
		ret = espPacket.wind_speed;
	}
	ret = constrain(ret, 0, 45);
	return ret;
}
uint8_t get_weather_clouds() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.clouds_all;
	}
	ret = constrain(ret, 0, 100);
	return ret;
}
float get_weather_rain() {
	static float ret = 0;
	if (dataCorrect) {
		ret = espPacket.rain_1h;
	}
	ret = constrain(ret, 0, 45);
	return ret;
}
float get_weather_snow() {
	static float ret = 0;
	if (dataCorrect) {
		ret = espPacket.snow_1h;
	}
	ret = constrain(ret, 0, 45);
	return ret;
}
uint16_t get_weather_press() {
	static uint16_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.main_pressure;
	}
	ret = constrain(ret, 200, 1500);
	return ret;
}
uint8_t get_wifi() {
	static uint8_t ret = 0;
	if (dataCorrect) {
		ret = espPacket.wifiStatus;
	}
	ret = constrain(ret, 0, 2);
	return ret;
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

