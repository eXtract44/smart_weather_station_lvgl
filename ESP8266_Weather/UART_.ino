#define HMI_Serial Serial
#define _Check 0xFE



void send_value(const uint16_t _Address, int16_t value) {
  char Data[2] = {0x00, 0x00};
  // Convert Value
  int16_t _Value_RAW = value;
  // Set Data Low/High Byte
  Data[1] = (_Value_RAW & (int16_t)0x00FF);
  Data[0]  = ((_Value_RAW & (int16_t)0xFF00) >> 8);
  // Send Data Pack
  if (HMI_Serial.availableForWrite()) //
  {
    HMI_Serial.write(_Address);
    delay(2); 
    HMI_Serial.write(Data[1]);
    delay(2); 
    HMI_Serial.write(Data[0]);
    delay(2); 
    HMI_Serial.write(_Check);
    delay(5); 
  }
  delay(20);
}
