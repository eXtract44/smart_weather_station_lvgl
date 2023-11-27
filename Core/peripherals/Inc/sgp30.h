/*
 * sgp30.h
 *
 *  Created on: Jan 19, 2023
 *      Author: Alex
 */

#ifndef INC_SGP30_H_
#define INC_SGP30_H_

#define SGP30_ADDR          0x58
#define	SGP30_ADDR_WRITE	SGP30_ADDR<<1       //0xb0
#define	SGP30_ADDR_READ		(SGP30_ADDR<<1)+1   //0xb1

/* SGP30传感器接的硬件I2C接口 */
#define SGP30_I2C_Handle_Name   hi2c1

typedef struct sgp30_data_st {
    uint16_t co2;
    uint16_t tvoc;
}sgp30_data_t;

typedef enum sgp30_cmd_en {
    /* 初始化空气质量测量 */
    INIT_AIR_QUALITY = 0x2003,

    /* 开始空气质量测量 */
    MEASURE_AIR_QUALITY = 0x2008

} sgp30_cmd_t;

extern I2C_HandleTypeDef SGP30_I2C_Handle_Name;
extern sgp30_data_t      sgp30_data;

int sgp30_init(void);
int sgp30_read(void);
uint16_t read_co2_sgp30();
uint16_t read_tvoc_sgp30();

#endif /* INC_SGP30_H_ */
