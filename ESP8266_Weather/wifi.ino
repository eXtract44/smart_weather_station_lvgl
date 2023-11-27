#define ADDRESS_WIFI_STATUS 0xFA 


//extern uint16_t eCO2;
//extern uint16_t TVOC;
//extern float temperature;
//extern uint8_t humid;
//extern float lux;

#define WIFI_RECONNECT_TIME 6 // *10 sec
uint16_t wifi_cnt = 0;
uint16_t wifi_status = 0;

void check_wifi() {//10 sec   //0 wifi OK 1 wifi OFF
  
  if (WiFi.status() == WL_CONNECTED) {
    wifi_status = 10;
    //send_value(ADDRESS_WIFI, wifi_status);
  }
  else {
    wifi_cnt++;
    if(wifi_cnt > WIFI_RECONNECT_TIME){
      WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    wifi_status = 5;
    //Serial.print(".");
  }
      
      wifi_cnt=0;
    }
    wifi_status = 20;
    //send_value(ADDRESS_WIFI, wifi_status);
  }
}
void send_data_wifi(){
 send_value(ADDRESS_WIFI_STATUS, wifi_status); 
 delay(DELAY_SEND_FUNKTIONS_WEAT);
}
  
/*
void handleNewMessages(int numNewMessages) {
  #if (_DEBUG == 1)
    Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));
#endif
  

  for (int i = 0; i < numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID) {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String text = bot.messages[i].text;
      #if (_DEBUG == 1)
   Serial.println(text);
#endif
   

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Добро пожаловать в спальню , " + from_name + ".\n";
      welcome += "Используйте следуйщие команды.\n\n";
      welcome += "/check_sleeproom для проверики датчиков в спальне \n";
      //welcome += "/led_off to turn GPIO OFF \n";
      //welcome += "/state to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    //bot.sendMessage(chat_id, "HELLO FROM ESP32", "");
   
    if (text == "/check_sleeproom") {
      String message = "Температура в спальне составляет: " + String(temperature) + " ºC \n";
      bot.sendMessage(chat_id, message, "");
      message = "Влажность в спальне составляет: " + String(humid) + " % \n";
      bot.sendMessage(chat_id, message, "");
     
      message = "Количество углекилосго  воздуха в спальне составляет: " + String(eCO2) + " ppm \n";
      bot.sendMessage(chat_id, message, "");
      message = "Количество мелких частиц в воздухе в спальне составляет: " + String(TVOC) + " ppm \n";
      bot.sendMessage(chat_id, message, "");
      
  if(eCO2 < 600){
    bot.sendMessage(chat_id, "Качество воздуха в кухне отличное", "");
  }
   if(eCO2 > 601 && eCO2 < 800){
    bot.sendMessage(chat_id, "Качество воздуха в кухне хорошее", "");
  }
  if(eCO2 > 801 && eCO2 < 1200){
    bot.sendMessage(chat_id, "Качество воздуха в кухне нормальное", "");
  }
  if(eCO2 > 1201 && eCO2 < 2000){
     bot.sendMessage(chat_id, "Качество воздуха в кухне плохое", "");
  }         
    
  message = "Яркость в спальне составляет: " + String(lux) + " lux \n";
      bot.sendMessage(chat_id, message, "");
      
  
      
    }//// /check_kitchen
 
  }
}
*/
void UPDATE_INET(){
  //int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  //  handleNewMessages(numNewMessages);
}
