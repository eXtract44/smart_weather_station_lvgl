#include "stm32f4xx_hal.h"
#include "../peripherals/Inc/aht10.h"
//PB11 SDA
//PB10 CLK

#define I2C_MODE hi2c2
extern I2C_HandleTypeDef I2C_MODE;
static uint32_t AHT10_ADC_Raw = 0;

//#define SIMULATE_AHT10_VALUES

float AHT10_Temperature = 0;
uint8_t AHT10_Humidity = 0;

uint8_t AHT10_TmpHum_Cmd[3] = { AHTX0_CMD_TRIGGER, 0x33, 0x00 };
uint8_t AHT10_RX_Data[6];
#define AHT10_ADRESS (0x38 << 1) // 0b1110000; Adress[7-bit]

void aht10_init()
{
	HAL_I2C_Master_Transmit(&I2C_MODE, AHT10_ADRESS, AHTX0_CMD_SOFTRESET,
				1, 100);
	HAL_Delay(50);
	HAL_I2C_Master_Transmit(&I2C_MODE, AHT10_ADRESS, AHTX0_CMD_CALIBRATE,
					1, 100);
	while (AHT10_Temperature > 2 && AHT10_Humidity > 10) {
		HAL_Delay(100);
	    aht10_read();
	  }
}

void aht10_read() {
#ifdef SIMULATE_AHT10_VALUES
	static uint8_t temp = 0;
	temp++;
	if(temp > 100)temp = 0;
	AHT10_Humidity= temp;

	static float temp_f = -10;
	temp_f = temp_f + 0.3f;
	if(temp_f > 60)temp_f = -10;
	AHT10_Temperature = temp_f;


#else
	HAL_I2C_Master_Transmit(&I2C_MODE, AHT10_ADRESS, (uint8_t*) AHT10_TmpHum_Cmd,
			3, 50); /* Send command (trigger measuremetns) + parameters */
	HAL_Delay(75);
	HAL_I2C_Master_Receive(&I2C_MODE, AHT10_ADRESS, (uint8_t*) AHT10_RX_Data, 6,
			50); /* Receive data: STATUS[1]:HIMIDITY[2.5]:TEMPERATURE[2.5] */

	if(~AHT10_RX_Data[0] & AHTX0_STATUS_BUSY)//aht10 not busy
	{
	/* Convert to Temperature in °C */
	AHT10_ADC_Raw = (((uint32_t) AHT10_RX_Data[3] & 15U) << 16U)
			| ((uint32_t) AHT10_RX_Data[4] << 8U) | AHT10_RX_Data[5];
	AHT10_Temperature = (float) (AHT10_ADC_Raw * 200.00f / 1048576.00f) - 50.00f;
	//			/* Convert to Relative Humidity in % */
	AHT10_ADC_Raw = ((uint32_t) AHT10_RX_Data[1] << 12U)
			| ((uint32_t) AHT10_RX_Data[2] << 4U) | (AHT10_RX_Data[3] >> 4U);
	AHT10_Humidity = (uint8_t) (AHT10_ADC_Raw * 100.00f / 1048576.00f);
	}
#endif
}
float read_temperature_aht10(){
	return AHT10_Temperature;
}
uint8_t read_humidity_aht10(){
	return AHT10_Humidity;
}
