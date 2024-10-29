
extern espPacket_ espPacket;

struct tm timeinfo;

void read_time() {  // every 5 sec
  getLocalTime(&timeinfo, 300);
  espPacket.tm_sec = timeinfo.tm_sec;
  espPacket.tm_min = timeinfo.tm_min;
  espPacket.tm_hour = timeinfo.tm_hour;
  espPacket.tm_mday = timeinfo.tm_mday;
  espPacket.tm_mon = timeinfo.tm_mon + 1;
  espPacket.tm_wday = timeinfo.tm_wday;
  espPacket.tm_year = timeinfo.tm_year;
}

void debug_time() {
 Serial.println("******************** time ********************");
  Serial.print(timeinfo.tm_sec);
  Serial.println(" sec");
  Serial.print(timeinfo.tm_min);
  Serial.println(" min");
  Serial.print(timeinfo.tm_hour);
  Serial.println(" hour");
  Serial.print(timeinfo.tm_mday);
  Serial.println(" month day");
  Serial.print(timeinfo.tm_mon + 1);
  Serial.println(" month");
  Serial.print(timeinfo.tm_wday+1);
  Serial.println(" wday");
    Serial.print(timeinfo.tm_year);
  Serial.println(" year");
}
