#define WIFI_RECONNECT_TIME 40  // 1 tick 5 sec

extern espPacket_ espPacket;

void read_wifi() {  //5 sec
  static uint16_t wifi_cnt = 0;
  if (WiFi.status() == WL_CONNECTED) {
    espPacket.wifiStatus = WIFI_CONNECTED;
    espPacket.wifiSignal = WiFi.RSSI();

 String ipString = WiFi.localIP().toString();
    // Copy the IP address to the char buffer
    strncpy(espPacket.wifiLocalIP, ipString.c_str(), sizeof(espPacket.wifiLocalIP) - 1);
    espPacket.wifiLocalIP[sizeof(espPacket.wifiLocalIP) - 1] = '\0';
    strncpy(espPacket.wifiSSID, WiFi.SSID().c_str(), sizeof(espPacket.wifiSSID));
  } else {
    wifi_cnt++;
    if (wifi_cnt > WIFI_RECONNECT_TIME) {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        espPacket.wifiStatus = WIFI_RECONNECT;
        Serial.print(".");
      }
      wifi_cnt = 0;
    }
    espPacket.wifiStatus = WIFI_DISCONNECTED;
    Serial.println("WiFi Disconnected");
  }
}
/*RSSI Value Range	WiFi Signal Strength
 RSSI > -30 dBm	 Amazing
 RSSI < – 55 dBm	 Very good signal
  RSSI < – 67 dBm	 Fairly Good
  RSSI < – 70 dBm	 Okay
  RSSI < – 80 dBm	 Not good
  RSSI < – 90 dBm	 Extremely weak signal (unusable)*/
void debug_wifi() {
  Serial.println("******************** wifi ********************");
  switch (espPacket.wifiStatus) {
    case WIFI_CONNECTED:
      Serial.println(" WIFI_CONNECTED");
      break;
    case WIFI_DISCONNECTED:
      Serial.println(" WIFI_DISCONNECTED");
      break;
    case WIFI_RECONNECT:
      Serial.println(" WIFI_RECONNECT");
      break;
  }
  Serial.println(espPacket.wifiSSID);
  Serial.print(espPacket.wifiSignal);
  Serial.println(" wifiSignal");
   Serial.print("IP address: ");
  Serial.println(espPacket.wifiLocalIP);
  Serial.println(" wifiLocalIP");
  Serial.print(espPacket.wifiSignal);
  Serial.println(" wifiSignal");
}