/*
 * brightness_control.h
 *
 *  Created on: Apr 1, 2024
 *      Author: toose
 */

#ifndef PERIPHERALS_INC_BRIGHTNESS_CONTROL_H_
#define PERIPHERALS_INC_BRIGHTNESS_CONTROL_H_

//List of includes
#include "stm32f4xx_hal.h"


void ILI9486_SetBrightness(uint8_t brightness);
void ILI9486_SetBrightness_Auto();

#endif /* PERIPHERALS_INC_BRIGHTNESS_CONTROL_H_ */
