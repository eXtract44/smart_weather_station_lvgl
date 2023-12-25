//https://dl.espressif.com/dl/package_esp32_index.json
//https://arduino.esp8266.com/stable/package_esp8266com_index.json

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "time.h"
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

#define UPDATE_TIME 5000         // in mS
#define DELAY_SEND_FUNKTIONS_WEAT 2  // in mS
#define DELAY_SEND_FUNKTIONS_TIME 2  // in mS

unsigned long previousMillis = 0;
extern uint16_t wifi_status;

//wifi
const char* ssid = "WiFi name";
const char* password = "wifi password";
String openWeatherMapApiKey = "your openWeatherMapApiKey";
//467236d17fdfc652af154eb837422f8d//
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;      //
const int daylightOffset_sec = 3600;  //
String city = "Dortmund";
String countryCode = "DE";

void setup() {
  delay(2000);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("WiFi connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    wifi_status = 5;
    Serial.print(".");
  }
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  delay(100);
  check_wifi();
  read_wetter();
  read_time();
  send_data_time();
  send_data_wifi();
  send_data_weather();
}

void loop() {
  unsigned long long currentMillis = millis();
  static uint16_t cnt_debug = 0;

  if (currentMillis - previousMillis >= UPDATE_TIME) {  //tick 5 sec
    previousMillis = currentMillis;
    if (WiFi.status() == WL_CONNECTED) {
      read_time();
      delay(2);
      read_wetter();
      cnt_debug++;
      if (cnt_debug > 6) {
        delay(2);
        debug_time();
        delay(2);
        debug_weather();
        cnt_debug = 0;
      }
    }
    check_wifi();
  }

  send_data_time();
  delay(5);
  send_data_wifi();
  delay(5);
  send_data_weather();
  delay(5);
}
