
#define ADDRESS_WEATHER_TEMP 0x32
#define ADDRESS_WEATHER_HUMI 0x3C
#define ADDRESS_WEATHER_PRESS 0x46
#define ADDRESS_WEATHER_WIND 0x50
#define ADDRESS_WEATHER_CLOUD 0x5A
#define ADDRESS_WEATHER_RAIN 0x64
#define ADDRESS_WEATHER_SNOW 0x6E


struct openWeatherMapData_ {
  float coord_lon;
  float coord_lat;
  unsigned int weather_id;
  String weather_main;
  String weather_description;
  String weather_icon;
  String base;
  float main_temp;
  float main_feels_like;
  float main_temp_min;
  float main_temp_max;
  unsigned int main_pressure;
  unsigned int main_humidity;
  unsigned int main_sea_level;
  unsigned int main_grnd_level;
  unsigned int visibility;
  float wind_speed;
  unsigned int wind_deg;
  float wind_gust;
  float rain_1h;
  float rain_3h;
  float snow_1h;
  float snow_3h;
  unsigned int clouds_all;
  unsigned long dt;
  unsigned int sys_type;
  unsigned int sys_id;
  String sys_country;
  unsigned long sys_sunrise;
  unsigned long sys_sunset;
  unsigned int timezone;
  unsigned long id;
  String name;
  unsigned int cod;
};

openWeatherMapData_ openWeatherMapData;

double temp_out = 0;
int16_t temp_temp_out = 0;
int16_t humidity_out = 0;
int16_t pressure_out = 0;

int16_t wind_speed = 0;
int16_t clouds = 0;
double rain_1h = 0;
int16_t rain_temp = 0;
double snow_1h = 0;
int16_t snow_temp = 0;


String jsonBuffer;

void read_wetter() {  //20 sec
  String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
  jsonBuffer = httpGETRequest(serverPath.c_str());
  //Serial.println(jsonBuffer);
  JSONVar myObject = JSON.parse(jsonBuffer);
  if (JSON.typeof(myObject) == "undefined") {
    Serial.println("Parsing input failed!");
    return;
  }

  //MAIN
openWeatherMapData.coord_lon = double(myObject["coord"]["lon"]);//Долгота местоположения
openWeatherMapData.coord_lat = double(myObject["coord"]["lat"]);//Широта местоположения

openWeatherMapData.weather_id =int(myObject["weather"]["id"]);//Идентификатор погодных условий
openWeatherMapData.weather_main=String(myObject["weather"]["main"]);//Группа погодных параметров (Дождь, Снег, Облака и т.д.)
openWeatherMapData.weather_description=String(myObject["weather"]["description"]);//Погодные условия в группе.
openWeatherMapData.weather_icon=String(myObject["weather"]["icon"]);//Идентификатор значка погоды
openWeatherMapData.base=String(myObject["base"]);//Внутренний параметр
openWeatherMapData.main_temp=double(myObject["main"]["temp"]);//Температура. Единица измерения по умолчанию: Кельвин, метрическая: Цельсий, имперская: Фаренгейт
openWeatherMapData.main_feels_like=double(myObject["main"]["feels_like"]);//Температура. Этот температурный параметр учитывает человеческое восприятие погоды. Единица измерения по умолчанию: Кельвин, метрическая: Цельсий, имперская: Фаренгейт
openWeatherMapData.main_temp_min=double(myObject["main"]["temp_min"]);//Минимальная температура на данный момент. Это минимальная температура, наблюдаемая в настоящее время (в крупных мегаполисах и городских районах).
openWeatherMapData.main_temp_max=double(myObject["main"]["temp_max"]);//Максимальная температура на данный момент. Это максимальная температура, наблюдаемая в настоящее время (в крупных мегаполисах и городских районах).
openWeatherMapData.main_pressure=int(myObject["main"]["pressure"]);//Атмосферное давление на уровне моря, гПа
openWeatherMapData.main_humidity=int(myObject["main"]["humidity"]);//Влажность, %
openWeatherMapData.main_sea_level=int(myObject["main"]["sea_level"]);//Атмосферное давление на уровне моря, гПа
openWeatherMapData.main_grnd_level=int(myObject["main"]["grnd_level"]);//Атмосферное давление на уровне земли, гПа
openWeatherMapData.visibility=int(myObject["visibility"]);//Видимость, метр. Максимальное значение видимости 10 км.
openWeatherMapData.wind_speed=double(myObject["wind"]["speed"]);//Скорость ветра. Единица измерения по умолчанию: метр/сек, метрическая: метр/сек, имперская: мили/час
openWeatherMapData.wind_deg=int(myObject["wind"]["deg"]);//Направление ветра, градусы (метеорологическое)
openWeatherMapData.wind_gust=double(myObject["wind"]["gust"]);//Порыв ветра. Единица измерения по умолчанию: метр/сек, метрическая: метр/сек, имперская: мили/час
openWeatherMapData.rain_1h=double(myObject["rain"]["1h"]);//(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
openWeatherMapData.rain_3h=double(myObject["rain"]["3h"]);//(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
openWeatherMapData.snow_1h=double(myObject["snow"]["1h"]);//(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
openWeatherMapData.snow_3h=double(myObject["snow"]["3h"]);//(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
openWeatherMapData.clouds_all=int(myObject["clouds_all"]);//Облачность, %
openWeatherMapData.dt=long(myObject["dt"]);//Время расчета данных, unix, UTC
openWeatherMapData.sys_type=int(myObject["sys"]["type"]);//Внутренний параметр
openWeatherMapData.sys_id=int(myObject["sys"]["id"]);//Внутренний параметр
openWeatherMapData.sys_country=String(myObject["sys"]["country"]);//Код страны (GB, JP и т.д.)
openWeatherMapData.sys_sunrise=long(myObject["sys"]["sunrise"]);//Время восхода солнца, unix, UTC
openWeatherMapData.sys_sunset=long(myObject["sys"]["sunset"]);//Время заката, unix, UTC
openWeatherMapData.timezone=int(myObject["sys"]["timezone"]);//Сдвиг в секундах от UTC
openWeatherMapData.id=long(myObject["id"]);// City ID. Обратите внимание, что встроенная функциональность геокодера устарела
openWeatherMapData.name=String(myObject["name"]);// Название города. Обратите внимание, что встроенная функциональность геокодера устарела.
openWeatherMapData.cod =int(myObject["cod"]);//Внутренний параметр

  temp_out = double(myObject["main"]["temp"]);  //Temperature. Unit : Kelvin
  temp_out = (temp_out - 273);
  temp_temp_out = (int16_t)temp_out * 10;
  pressure_out = int(myObject["main"]["pressure"]);  // Atmospheric pressure (on the sea level, if there is no sea_level or grnd_level data), hPa
  humidity_out = int(myObject["main"]["humidity"]);  //Humidity, %
  wind_speed = int(myObject["wind"]["speed"]);
  clouds = int(myObject["clouds"]["all"]);   //Cloudiness, %
  rain_1h = double(myObject["rain"]["1h"]);  //Rain volume for the last 1 hour, mm
  rain_1h = rain_1h * 10;
  rain_temp = (int16_t)rain_1h;
  if (rain_temp == 0xFFFF) {
    rain_temp = 0;
  }
  snow_1h = double(myObject["snow"]["1h"]);  //Rain volume for the last 1 hour, mm
  snow_1h = snow_1h * 10;
  snow_temp = (int16_t)snow_1h;
  if (snow_temp == 0xFFFF) {
    snow_temp = 0;
  }
}
void send_data_weather() {
  send_value(ADDRESS_WEATHER_TEMP, temp_temp_out);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_PRESS, pressure_out);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_RAIN, rain_temp);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_SNOW, snow_temp);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_HUMI, humidity_out);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_WIND, wind_speed);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
  send_value(ADDRESS_WEATHER_CLOUD, clouds);
  delay(DELAY_SEND_FUNKTIONS_WEAT);
}


String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;

  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void debug_weather() {
  read_wetter();
  Serial.print("temperature outdoor c*= ");
  Serial.println((float)temp_temp_out / 10);
  Serial.println(" humidity_out %");
  Serial.print(humidity_out);
  Serial.println(" pressure_out hPa");
  Serial.print(pressure_out);
  Serial.println(" wind_speed m/s");
  Serial.print(wind_speed);
  Serial.println(" clouds %");
  Serial.print(clouds);
  Serial.println(" rain_1h mm");
  Serial.print((float)rain_temp / 10);
  Serial.println(" snow_1h mm");
  Serial.print((float)snow_temp / 10);
}
