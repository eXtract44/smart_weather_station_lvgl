
#ifndef INC_AHT10_H_
#define INC_AHT10_H_

#define AHTX0_I2CADDR_DEFAULT 0x38   ///< AHT default i2c address
#define AHTX0_I2CADDR_ALTERNATE 0x39 ///< AHT alternate i2c address
#define AHTX0_CMD_CALIBRATE 0xE1     ///< Calibration command
#define AHTX0_CMD_TRIGGER 0xAC       ///< Trigger reading command
#define AHTX0_CMD_SOFTRESET 0xBA     ///< Soft reset command
#define AHTX0_STATUS_BUSY 0x80       ///< Status bit for busy
#define AHTX0_STATUS_CALIBRATED 0x08 ///< Status bit for calibrated

void aht10_init();
void aht10_read();
float read_temperature_aht10();
uint8_t read_humidity_aht10();

#endif /* INC_AHT10_H_ */
