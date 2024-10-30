#ifndef DATA_H_
#define DATA_H_

#define WIFI_DISCONNECTED 0
#define WIFI_CONNECTED 1
#define WIFI_RECONNECT 2

typedef struct espPacket_ {
  char uartKey[3];
  int  tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_wday;
  int tm_year;
  int tm_user_offset_sec;
  int tm_user_day_start_hour;
  int tm_user_day_end_hour;
  int user_current_menu;
  int user_thema;
  char wifiSSID[40];
  int wifiStatus;
  int wifiSignal;
  char wifiLocalIP[16];
  float coord_lon;
  float coord_lat;
  int weather_id;
 /* String weather_main;
  String weather_description;
  String weather_icon;
  String base;*/
  float main_temp;
  float main_feels_like;
  float main_temp_min;
  float main_temp_max;
  int main_pressure;
  int main_humidity;
  int main_sea_level;
  int main_grnd_level;
  int visibility;
  float wind_speed;
  int wind_deg;
  float wind_gust;
  float rain_1h;
  float rain_3h;
  float snow_1h;
  float snow_3h;
  int clouds_all;
  unsigned long dt;
  /*String sys_country;*/
  unsigned long sys_sunrise;
  unsigned long sys_sunset;
  int timezone;
  unsigned long id;
  /*String name;*/
}espPacket_;

#endif /* DATA_H_ */
