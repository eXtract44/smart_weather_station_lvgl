

String jsonBuffer;

void read_weather() {  //20 sec
  if (WiFi.status() == WL_CONNECTED) {
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
    jsonBuffer = httpGETRequest(serverPath.c_str());
    //Serial.println(jsonBuffer);
    JSONVar myObject = JSON.parse(jsonBuffer);
    if (JSON.typeof(myObject) == "undefined") {
      Serial.println("Parsing input failed!");
      return;
    }

    //MAIN
    espPacket.coord_lon = double(myObject["coord"]["lon"]);  //Долгота местоположения
    espPacket.coord_lat = double(myObject["coord"]["lat"]);  //Широта местоположения

    espPacket.weather_id = int(myObject["weather"]["id"]);                     //Идентификатор погодных условий
                                                                               /* espPacket.weather_main = String(myObject["weather"]["main"]);                //Группа погодных параметров (Дождь, Снег, Облака и т.д.)
  espPacket.weather_description = String(myObject["weather"]["description"]);  //Погодные условия в группе.
  espPacket.weather_icon = String(myObject["weather"]["icon"]);                //Идентификатор значка погоды
  espPacket.base = String(myObject["base"]);*/
                                                                               //Внутренний параметр
    espPacket.main_temp = double(myObject["main"]["temp"]) - 273;              //Температура. Единица измерения Цельсий
    espPacket.main_feels_like = double(myObject["main"]["feels_like"]) - 273;  //Температура. Этот температурный параметр учитывает человеческое восприятие погоды. Единица измерения Цельсий
    espPacket.main_temp_min = double(myObject["main"]["temp_min"]) - 273;      //Минимальная температура на данный момент. Это минимальная температура, наблюдаемая в настоящее время (в крупных мегаполисах и городских районах).
    espPacket.main_temp_max = double(myObject["main"]["temp_max"]) - 273;      //Максимальная температура на данный момент. Это максимальная температура, наблюдаемая в настоящее время (в крупных мегаполисах и городских районах).

    espPacket.main_pressure = int(myObject["main"]["pressure"]);      //Атмосферное давление на уровне моря, гПа
    espPacket.main_humidity = int(myObject["main"]["humidity"]);      //Влажность, %
    espPacket.main_sea_level = int(myObject["main"]["sea_level"]);    //Атмосферное давление на уровне моря, гПа
    espPacket.main_grnd_level = int(myObject["main"]["grnd_level"]);  //Атмосферное давление на уровне земли, гПа
    espPacket.visibility = int(myObject["visibility"]);               //Видимость, метр. Максимальное значение видимости 10 км.
    espPacket.wind_speed = double(myObject["wind"]["speed"]);         //Скорость ветра. Единица измерения по умолчанию: метр/сек, метрическая: метр/сек, имперская: мили/час
    espPacket.wind_deg = int(myObject["wind"]["deg"]);                //Направление ветра, градусы (метеорологическое)
    espPacket.wind_gust = double(myObject["wind"]["gust"]);           //Порыв ветра. Единица измерения по умолчанию: метр/сек, метрическая: метр/сек, имперская: мили/час
    espPacket.rain_1h = double(myObject["rain"]["1h"]);               //(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
    espPacket.rain_3h = double(myObject["rain"]["3h"]);               //(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
    espPacket.snow_1h = double(myObject["snow"]["1h"]);               //(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
    espPacket.snow_3h = double(myObject["snow"]["3h"]);               //(где доступно) Осадки, мм/ч. Обратите внимание, что для этого параметра доступны только мм/ч в качестве единиц измерения
    espPacket.clouds_all = int(myObject["clouds_all"]);               //Облачность, %
    espPacket.dt = long(myObject["dt"]);                              //Время расчета данных, unix, UTC
    //espPacket.sys_country = String(myObject["sys"]["country"]);                  //Код страны (GB, JP и т.д.)
    espPacket.sys_sunrise = long(myObject["sys"]["sunrise"]);  //Время восхода солнца, unix, UTC
    espPacket.sys_sunset = long(myObject["sys"]["sunset"]);    //Время заката, unix, UTC
    espPacket.timezone = int(myObject["sys"]["timezone"]);     //Сдвиг в секундах от UTC
    espPacket.id = long(myObject["id"]);                       // City ID. Обратите внимание, что встроенная функциональность геокодера устарела
    //espPacket.name = String(myObject["name"]);                                   // Название города. Обратите внимание, что встроенная функциональность геокодера устарела.
  }
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
  Serial.println("******************** weather ********************");
  Serial.print(espPacket.coord_lon);
  Serial.println(" coord_lon");
  Serial.print(espPacket.coord_lat);
  Serial.println(" coord_lat");
  Serial.print(espPacket.weather_id);
  Serial.println(" weather_id");
  Serial.print(espPacket.main_temp);
  Serial.println(" main_temp");
  Serial.print(espPacket.main_feels_like);
  Serial.println(" main_feels_like");
  Serial.print(espPacket.main_temp_min);
  Serial.println(" main_temp_min");
  Serial.print(espPacket.main_temp_max);
  Serial.println(" main_temp_max");
  Serial.print(espPacket.main_pressure);
  Serial.println(" main_pressure");
  Serial.print(espPacket.main_humidity);
  Serial.println(" main_humidity");
  Serial.print(espPacket.main_sea_level);
  Serial.println(" main_sea_level");
  Serial.print(espPacket.main_grnd_level);
  Serial.println(" main_grnd_level");
  Serial.print(espPacket.visibility);
  Serial.println(" visibility");
  Serial.print(espPacket.wind_speed);
  Serial.println(" wind_speed");
  Serial.print(espPacket.wind_deg);
  Serial.println(" wind_deg");
  Serial.print(espPacket.wind_gust);
  Serial.println(" wind_gust");
  Serial.print(espPacket.rain_1h);
  Serial.println(" rain_1h");
  Serial.print(espPacket.rain_3h);
  Serial.println(" rain_3h");
  Serial.print(espPacket.snow_1h);
  Serial.println(" snow_1h");
  Serial.print(espPacket.snow_3h);
  Serial.println(" snow_3h");
  Serial.print(espPacket.clouds_all);
  Serial.println(" clouds_all");
  Serial.print(espPacket.dt);
  Serial.println(" dt");
  Serial.print(espPacket.sys_sunrise);
  Serial.println(" sys_sunrise");
  Serial.print(espPacket.sys_sunset);
  Serial.println(" sys_sunset");
  Serial.print(espPacket.timezone);
  Serial.println(" timezone");
  Serial.print(espPacket.id);
  Serial.println(" id");
}
