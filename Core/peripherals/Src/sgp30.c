#include "stm32f4xx_hal.h"
#include "../peripherals/Inc/sgp30.h"

sgp30_data_t sgp30_data;
//#define SIMULATE_SGP30_VALUES

static uint8_t sgp30_send_cmd(sgp30_cmd_t cmd)
{
    uint8_t cmd_buffer[2];
    cmd_buffer[0] = cmd >> 8;
    cmd_buffer[1] = cmd;
    return HAL_I2C_Master_Transmit(&SGP30_I2C_Handle_Name, SGP30_ADDR_WRITE, (uint8_t*) cmd_buffer, 2, 0xFFFF);
}
static int sgp30_soft_reset(void)
{
    uint8_t cmd = 0x06;
    return HAL_I2C_Master_Transmit(&SGP30_I2C_Handle_Name, 0x00, &cmd, 1, 0xFFFF);
}
int sgp30_init(void)
{
    int status;

    status = sgp30_soft_reset();
    if (status != HAL_OK) {
        return -1;
    }

    HAL_Delay(100);

    status = sgp30_send_cmd(INIT_AIR_QUALITY);

    HAL_Delay(100);

    return status == 0 ? 0 : -1;
}
static int sgp30_start(void)
{
    return sgp30_send_cmd(MEASURE_AIR_QUALITY);
}
#define CRC8_POLYNOMIAL 0x31
static uint8_t CheckCrc8(uint8_t* const message, uint8_t initial_value)
{
    uint8_t  remainder;	    //余数
    uint8_t  i = 0, j = 0;  //循环变量

    /* 初始化 */
    remainder = initial_value;

    for(j = 0; j < 2;j++)
    {
        remainder ^= message[j];

        /* 从最高位开始依次计算  */
        for (i = 0; i < 8; i++)
        {
            if (remainder & 0x80)
            {
                remainder = (remainder << 1)^CRC8_POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }

    /* 返回计算的CRC码 */
    return remainder;
}
int sgp30_read(void)
{
#ifdef SIMULATE_SGP30_VALUES
	static uint16_t temp = 400;
	temp += 10;
	if(temp> 9999)temp = 400;
	sgp30_data.co2  = temp;
	    sgp30_data.tvoc = temp-111;
#else
    int status;
    uint8_t recv_buffer[6]={0};

    /* 启动测量 */
    status = sgp30_start();
    if (status != 0) {
        //printf("sgp30 start fail\r\n");
    //    return -1;
    }

    HAL_Delay(100);

    /* 读取测量数据 */
    status = HAL_I2C_Master_Receive(&SGP30_I2C_Handle_Name, SGP30_ADDR_READ, (uint8_t*)recv_buffer, 6, 0xFFFF);
    if (status != HAL_OK) {
        //printf("I2C Master Receive fail\r\n");
        return -1;
    }

    /* 校验接收的测量数据 */
    if (CheckCrc8(&recv_buffer[0], 0xFF) != recv_buffer[2]) {
        //printf("co2 recv data crc check fail\r\n");
        return -1;
    }
    if (CheckCrc8(&recv_buffer[3], 0xFF) != recv_buffer[5]) {
        //printf("tvoc recv data crc check fail\r\n");
        return -1;
    }


    /* 转换测量数据 */
    sgp30_data.co2  = recv_buffer[0] << 8 | recv_buffer[1];
    sgp30_data.tvoc = recv_buffer[3] << 8 | recv_buffer[4];

#endif
    return 0;
}
uint16_t read_co2_sgp30(){
return sgp30_data.co2;
}
uint16_t read_tvoc_sgp30(){
	return sgp30_data.tvoc;
}
