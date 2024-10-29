//https://dl.espressif.com/dl/package_esp32_index.json
//https://arduino.esp8266.com/stable/package_esp8266com_index.json

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "time.h"
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
#include "data.h"


#define debug_time_ 1
#define debug_weather_ 1
#define debug_wifi_ 1

espPacket_ espPacket;

#define WIFI_DISCONNECTED 0
#define WIFI_CONNECTED 1
#define WIFI_RECONNECT 2

#define UPDATE_TIME 5000         // in mS

unsigned long previousMillis = 0;

//wifi
const char* ssid = "Freifunk";
const char* password = "";
String openWeatherMapApiKey = "467236d17fdfc652af154eb837422f8d";
//467236d17fdfc652af154eb837422f8d//
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600;      //
const int daylightOffset_sec = 3600;  //
String city = "Dortmund";
String countryCode = "DE";

void init_wifi(){
WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #if debug_wifi_
  Serial.print("WiFi connecting");
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    espPacket.wifiStatus = WIFI_RECONNECT;
    #if debug_wifi_
    Serial.print(".");
    Serial.print("wifi connected");
    #endif
  }
}
void setup() {
  Serial.begin(115200);
  init_wifi();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  delay(100);
  read_wifi();
  read_weather();
  read_time();
}

void loop() {
  unsigned long long currentMillis = millis();
  if (currentMillis - previousMillis >= UPDATE_TIME) {  //tick 5 sec
    previousMillis = currentMillis;        
    read_weather();
    read_wifi();
    read_time();
    #if debug_time_
    debug_time();
    #endif
     #if debug_weather_
     debug_weather();
    #endif
     #if debug_wifi_
     debug_wifi();
    #endif
  }
send_packet();
delay(10);
}
