#define ADDRESS_WIFI_STATUS 0xFA 

#define WIFI_RECONNECT_TIME 40 // 1 tick 5 sec
#define WIFI_CONNECTED 10
#define WIFI_RECONNECT 5
#define WIFI_DISCONNECTED 20

uint16_t wifi_status = 0;

void check_wifi() {//5 sec
  static uint16_t wifi_cnt = 0;
  if (WiFi.status() == WL_CONNECTED) {
    wifi_status = WIFI_CONNECTED;
  }
  else {
    wifi_cnt++;
    if(wifi_cnt > WIFI_RECONNECT_TIME){
      WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    wifi_status = WIFI_RECONNECT;
    Serial.print(".");
  }
      
      wifi_cnt=0;
    }
    wifi_status = WIFI_DISCONNECTED;
    Serial.println("WiFi Disconnected");
  }
}
void send_data_wifi(){
 send_value(ADDRESS_WIFI_STATUS, wifi_status); 
 delay(DELAY_SEND_FUNKTIONS_WEAT);
}
