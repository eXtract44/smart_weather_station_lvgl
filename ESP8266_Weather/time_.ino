#define ADDRESS_TIME_MIN 0x00
#define ADDRESS_TIME_HOUR 0x0A
#define ADDRESS_TIME_MDAY 0x14
#define ADDRESS_TIME_MON 0x1E
#define ADDRESS_TIME_WDAY 0x28

struct tm timeinfo;

void read_time() {// every 5 sec
    getLocalTime(&timeinfo,300);
}
void send_data_time(){
    send_value(ADDRESS_TIME_MIN, timeinfo.tm_min);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_HOUR, timeinfo.tm_hour);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_MDAY, timeinfo.tm_mday);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_MON, timeinfo.tm_mon + 1);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_WDAY, timeinfo.tm_wday); 
    delay(DELAY_SEND_FUNKTIONS_TIME);
}

void debug_time() {
  read_time();
  //Serial.print(sec);
  //Serial.println(" sec");
  Serial.print(timeinfo.tm_min);
  Serial.println(" min");
  Serial.print(timeinfo.tm_hour);
  Serial.println(" hour");
  Serial.print(timeinfo.tm_mday);
  Serial.println(" month day");
  Serial.print(timeinfo.tm_mon + 1);
  Serial.println(" month");
  Serial.print(timeinfo.tm_wday);
  Serial.println(" Tage seit Sonntag");
}
