
#define ADDRESS_WEATHER_TEMP 0x32
#define ADDRESS_WEATHER_HUMI 0x3C
#define ADDRESS_WEATHER_PRESS 0x46
#define ADDRESS_WEATHER_WIND 0x50
#define ADDRESS_WEATHER_CLOUD 0x5A
#define ADDRESS_WEATHER_RAIN 0x64
#define ADDRESS_WEATHER_SNOW 0x6E

//50-10

//extern bool day_; //from time_functions
//MAIN
float temp_out = 0;
int16_t temp_temp_out = 0;
//float feels_like_temp_out = 0;
int16_t humidity_out = 0;
int16_t pressure_out = 0;
//float min_temp_out = 0;
//float max_temp_out = 0;
//MAIN
//float  visibility = 0;
int16_t wind_speed = 0;
//int16_t wind_deg = 0;
int16_t clouds = 0;
float  rain_1h = 0;
uint16_t rain_temp = 0;
//float  rain_3h = 0;
float  snow_1h = 0;
uint16_t snow_temp = 0;
//float  snow_3h = 0;


String jsonBuffer;

void read_wetter() { //20 sec
  if (WiFi.status() == WL_CONNECTED) {
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
    jsonBuffer = httpGETRequest(serverPath.c_str());
    //Serial.println(jsonBuffer);
    JSONVar myObject = JSON.parse(jsonBuffer);
    if (JSON.typeof(myObject) == "undefined") {
      //Serial.println("Parsing input failed!");
      return;
    }
    //WEATHER
    //    weather_main =  (myObject["weather"]["main"]);                   //Group of weather parameters (Rain, Snow, Extreme etc.)
    //   weather_description =  (myObject["weather"]["description"]);      // Weather condition within the group. You can get the output in your language.
    //WEATHER

    //MAIN
    temp_out =  double(myObject["main"]["temp"]);                   //Temperature. Unit : Kelvin
    temp_out = (temp_out - 273);
    temp_temp_out = (int16_t)temp_out * 10;


    //send_value_test(temp_out);
    //Temperature. Unit : Celsius

    //feels_like_temp_out =  double(myObject["main"]["feels_like"]);  //Temperature feels_like. Unit : Kelvin
    //feels_like_temp_out = (feels_like_temp_out - 273);                       //Temperature feels_like. Unit : Celsius
    //feels_like_temp_out = temp_out * 10;

    pressure_out =  int(myObject["main"]["pressure"]);       // Atmospheric pressure (on the sea level, if there is no sea_level or grnd_level data), hPa
    //send_value(WEATHER_TEMP, temp_out);
    //send_value(ADDRESS_PRESSURE_OUT, pressure_out);

    humidity_out = int(myObject["main"]["humidity"]);          //Humidity, %

    //send_value(ADDRESS_HUMI_OUT, humidity_out);

    //min_temp_out =  double(myObject["main"]["temp_min"]);           // Maximum temperature at the moment. This is maximal currently observed temperature (within large megalopolises and urban areas) Unit : Kelvin
    //min_temp_out = (min_temp_out - 273);                              //Temperature. Unit : Celsius
    //min_temp_out = min_temp_out * 10;
    //send_value(ADDRESS_TEMP_MIN_OUT, min_temp_out);

    //max_temp_out =  double(myObject["main"]["temp_max"]);            //Temperature. Unit : Kelvin
    //max_temp_out = (max_temp_out - 273); //Temperature. Unit : Celsius
    //max_temp_out = max_temp_out * 10;
    //MAIN

    //visibility =  double(myObject["visibility"]);                  //Visibility, meter. The maximum value of the visibility is 10km
    //send_value(ADDRESS_VISIBILITY_OUT, visibility / 100);

    wind_speed = int(myObject["wind"]["speed"]);
    //Wind speed. Unit Default: meter/sec
    //send_value(ADDRESS_WIND_SPEED_OUT, wind_speed);
    //wind_deg = int(myObject["wind"]["deg"]);                      // Wind direction, degrees (meteorological)
    //send_value(ADDRESS_WIND_DEG_OUT, wind_deg);

    clouds = int(myObject["clouds"]["all"]);                        //Cloudiness, %

    //send_value(ADDRESS_CLOUDS_OUT, clouds);

    rain_1h = double(myObject["rain"]["1h"]);                        //Rain volume for the last 1 hour, mm
    rain_1h = rain_1h * 10;
    rain_temp = (uint16_t)rain_1h;
    if (rain_temp == 65535);
    {
      rain_temp = 0;
    }
    //send_value(ADDRESS_RAIN_1H, rain_1h);

    //rain_3h = double(myObject["rain"]["3h"]);  //Rain volume for the last 3 hour, mm
    //rain_3h = rain_3h * 10;
    //send_value(ADDRESS_RAIN_3H, rain_3h);

    snow_1h = double(myObject["snow"]["1h"]);                        //Rain volume for the last 1 hour, mm
    snow_1h = snow_1h * 10;
    snow_temp = (uint16_t)snow_1h;
    if (snow_temp == 65535);
    {
      snow_temp = 0;
    }
    //send_value(ADDRESS_SNOW_1H, snow_1h);

    //snow_3h = double(myObject["snow"]["3h"]);                        //Rain volume for the last 3 hour, mm
    //snow_3h = snow_1h * 10;
    //send_value(ADDRESS_SNOW_3H, snow_3h);
  }
  else {
    //Serial.println("WiFi Disconnected");
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
    //Serial.print("HTTP Response code: ");
    //Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    //Serial.print("Error code: ");
    //Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void debug_weather() {
  read_wetter();
  Serial.print(temp_temp_out);
  Serial.println(" outdoor *c");

  //   Serial.print(feels_like_temp_out);
  //   Serial.println(" feels_like_temp_out *c");
  //
  Serial.print(humidity_out);
  Serial.println(" humidity_out %");
  //
  Serial.print(pressure_out);
  Serial.println(" pressure_out hPa");
  //
  //    Serial.print(min_temp_out);
  //    Serial.println(" min_temp_out *c");
  //
  //    Serial.print(max_temp_out);
  //    Serial.println(" max_temp_out *c");
  //
  //    Serial.print(visibility);
  //    Serial.println(" visibility %");
  //
  Serial.print(wind_speed);
  Serial.println(" wind_speed m/s");
  //
  //    Serial.print(wind_deg);
  //    Serial.println(" wind_deg *");
  //
  Serial.print(clouds);
  Serial.println(" clouds %");

  Serial.print(rain_temp);
  Serial.println(" rain_1h mm");

  //Serial.print(rain_3h);
  //Serial.println(" rain_3h mm");

  Serial.print(snow_temp);
  Serial.println(" snow_1h mm");

  // Serial.print(snow_3h);
  //Serial.println(" snow_3h mm");


}
