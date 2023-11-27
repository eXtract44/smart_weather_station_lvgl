#define ADDRESS_TIME_MIN 0x00
#define ADDRESS_TIME_HOUR 0x0A
#define ADDRESS_TIME_MDAY 0x14
#define ADDRESS_TIME_MON 0x1E
#define ADDRESS_TIME_WDAY 0x28


//0-40

//#define TIME_DAY_START 6 //std
//#define TIME_DAY_END 21//std

struct tm timeinfo;

//bool day_ = true;
//uint8_t jahreszeit_ = 0;  //1-fru,2-somm,3-herb,4-wint

//uint8_t sec = 0;
uint8_t minute = 0;
uint8_t hour = 0;
uint8_t mday = 0;
uint8_t mon = 0;
//uint16_t year = 0;
uint8_t wday = 0;
//uint8_t yday = 0;
/*
bool getLocalTime(struct tm * info, uint32_t ms)
{
    uint32_t start = millis();
    time_t now;
    while((millis()-start) <= ms) {
        time(&now);
        localtime_r(&now, info);
        if(info->tm_year > (2016 - 1900)){
            return true;
        }
        delay(10);
    }
    return false;
}
*/
void read_time() {// every 1 sec
  if (WiFi.status() == WL_CONNECTED) {
    getLocalTime(&timeinfo,300);
    //sec = timeinfo.tm_sec; //
    minute = timeinfo.tm_min;//
    hour = timeinfo.tm_hour; //
    mday = timeinfo.tm_mday; //Tage im Monat (1, 31)   
    mon = timeinfo.tm_mon + 1; //Monate seit Januar (0, 11)
    //year = timeinfo.tm_year + 1900 - 2000; //Jahre seit 1900
    wday = timeinfo.tm_wday; //Tage seit Sonntag (0, 6)   
    //yday = timeinfo.tm_yday; //Tage seit dem 1. Januar (0, 365)
    //send_time(sec, minute, hour, wday, mday, mon, year);
  }
}
void send_data_time(){
    send_value(ADDRESS_TIME_MIN, minute);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_HOUR, hour);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_MDAY, mday);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_MON, mon);
    delay(DELAY_SEND_FUNKTIONS_TIME);
    send_value(ADDRESS_TIME_WDAY, wday); 
    delay(DELAY_SEND_FUNKTIONS_TIME);
}
/*
uint16_t cnt_day = 0;
void read_day_night() {
  if (hour > TIME_DAY_START && hour < TIME_DAY_END) {
    day_ = true;
    //set_bri(80);
  } else {
    day_ = false;//night
    //set_bri(9);
  }

  cnt_day++;
  if (cnt_day > 360) {
    if (mon > 2 && mon < 6) { //03-05
      jahreszeit_ = 0;  //1-fru,2-somm,3-herb,4-wint
    }
    if (mon > 5 && mon < 9) { //06-08
      jahreszeit_ = 1;  //1-fru,2-somm,3-herb,4-wint
    }
    if (mon > 8 && mon < 12) { //09-11
      jahreszeit_ = 2;  //1-fru,2-somm,3-herb,4-wint
    }
    if (mon > 10 && mon < 2) { //11-1
      jahreszeit_ = 3;  //1-fru,2-somm,3-herb,4-wint
    }
    //change_main_pic(jahreszeit_);
    cnt_day = 0;
  }
}


void debug_time() {
  read_time();
  //Serial.print(sec);
  //Serial.println(" sec");
  Serial.print(minute);
  Serial.println(" min");
  Serial.print(hour);
  Serial.println(" hour");
  Serial.print(mday);
  Serial.println(" monat day");
  Serial.print(mon);
  Serial.println(" monat");
//  Serial.print(year);
 // Serial.println(" year");
  Serial.print(wday);
  Serial.println(" Tage seit Sonntag");
  //Serial.print(yday);
  //Serial.println(" Tage seit dem 1. Januar");
}
*/
