  struct espPacket_ {
  char uartKey[3];
  int  tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_wday;
  int tm_year;
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
};
