//https://dl.espressif.com/dl/package_esp32_index.json
//https://arduino.esp8266.com/stable/package_esp8266com_index.json

//#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "time.h"
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
//#if (_INET == 1)
//#include <ArduinoJson.h>
//#include <WiFiClientSecure.h>
//#include <UniversalTelegramBot.h>
//#endif

#define UPDATE_TIME  5 * 1000 // 5 sec
//#define UPDATE_TIME_WEATHER  6 * 1 // 1 min
#define DELAY_SEND_FUNKTIONS_WEAT  10 // in ms
#define DELAY_SEND_FUNKTIONS_TIME  10 // in ms


unsigned long previousMillis = 0;

//wifi
const char* ssid       = "xx";
const char* password   = "xx";
String openWeatherMapApiKey = "xx";
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;//
const int   daylightOffset_sec = 3600;//
String city = "Dortmund";
String countryCode = "DE";
//#if (_INET == 1)
//#define BOTtoken "5657548564:AAGvnIlqb-UVp6fik-6DC_sK2O7n_C05v3o"  // your Bot Token (Get from Botfather)
//#define CHAT_ID "421330653"
//WiFiClientSecure client;
//UniversalTelegramBot bot(BOTtoken, client);
//#endif




extern uint16_t wifi_status;

//proto

void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    wifi_status = 5;
    //Serial.print(".");
  }
  //Serial.println(" CONNECTED");
  //client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  delay(500);
  check_wifi();
  read_wetter();
  read_time();
  send_data_time();
  delay(100);
  send_data_wifi();
  send_data_weather();
  delay(100);
}
uint16_t cnt_weather = 0;
void loop() {
  send_data_time();
  delay(50);
  send_data_wifi();
  send_data_weather();
  delay(50);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= UPDATE_TIME) {  //10 sec
    previousMillis = currentMillis;  
    check_wifi();
    read_time();
    read_wetter();
    //debug_time();
    //debug_weather();      
  }
}
