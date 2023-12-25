
#define ADDRESS_WEATHER_TEMP 0x32
#define ADDRESS_WEATHER_HUMI 0x3C
#define ADDRESS_WEATHER_PRESS 0x46
#define ADDRESS_WEATHER_WIND 0x50
#define ADDRESS_WEATHER_CLOUD 0x5A
#define ADDRESS_WEATHER_RAIN 0x64
#define ADDRESS_WEATHER_SNOW 0x6E

//50-10

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
  if (rain_temp == 0xFFFF)
  {
    rain_temp = 0;
  }
  snow_1h = double(myObject["snow"]["1h"]);  //Rain volume for the last 1 hour, mm
  snow_1h = snow_1h * 10;
  snow_temp = (int16_t)snow_1h;
  if (snow_temp == 0xFFFF)
  {
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
