//https://dl.espressif.com/dl/package_esp32_index.json
//https://arduino.esp8266.com/stable/package_esp8266com_index.json

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "time.h"
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
#include "data.h"
#include <ESP8266WebServer.h>
#include <EEPROM.h>

#define debug_time_ 1
#define debug_weather_ 1
#define debug_wifi_ 1

espPacket_ espPacket;

#define UPDATE_TIME 5000  // in mS

unsigned long previousMillis = 0;

ESP8266WebServer server(80);

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

void send_packet() {
  strncpy(espPacket.uartKey, "ESP", 3);  // Präfix zur Überprüfung
  Serial.write((uint8_t*)&espPacket, sizeof(espPacket));
}

void init_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
#if debug_wifi_
  Serial.print("WiFi connecting");
#endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    espPacket.wifiStatus = WIFI_RECONNECT;
#if debug_wifi_
    Serial.println();
    Serial.print("Verbunden! IP-Adresse: ");
    Serial.println(WiFi.localIP());
#endif
  }
}
void init_webserver() {
  // Webserver-Routen einrichten
  server.on("/", HTTP_GET, handleRoot);
  server.on("/update", HTTP_POST, handleUpdate);

  // Webserver starten
  server.begin();
  Serial.println("Webserver gestartet");
}
void setup() {
  Serial.begin(115200);
  init_wifi();
  init_webserver();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  EEPROM.begin(512);
  espPacket.tm_user_offset_sec = EEPROM.read(0);
  espPacket.tm_user_day_start_hour = EEPROM.read(1);
  espPacket.tm_user_day_end_hour = EEPROM.read(2);
  espPacket.user_current_menu = EEPROM.read(3);
  espPacket.user_thema = EEPROM.read(4);
  delay(100);
  read_wifi();
  read_weather();
  read_time();
}

void loop() {
  server.handleClient();
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
