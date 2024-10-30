/*
 * lvgl_menu.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Alex
 */

#ifndef INC_LVGL_MENU_H_
#define INC_LVGL_MENU_H_

#include "stm32f4xx_hal.h"
#include "../lvgl/lvgl.h"
#include "../lvgl/lv_port_indev.h"
#include "../peripherals/Inc/aht10.h"
#include "../peripherals/Inc/sgp30.h"
#include "../peripherals/Inc/esp.h"
#include "../peripherals/Inc/adc.h"
#include "../peripherals/Inc/range.h"
#include "../peripherals/Inc/dfplayer_mini.h"
#include "../peripherals/Inc/ili9486.h"

#define NUMBERS_OF_FONTS 3+1

enum namesOfFonts {
	FONT_SMALL, FONT_MEDIUM, FONT_LARGE, FONT_VERY_LARGE,
};
//lv_group_t *GROUP_BUTTONS;
#define NUMBERS_OF_STYLES 3 + 1

enum namesOfStyles {
	STYLE_TEXT_SMALL, STYLE_TEXT_MEDIUM, STYLE_TEXT_LARGE, STYLE_TEXT_VERY_LARGE,
};

#define NUMBER_OF_OBJECTS 44+1

typedef struct {
	const lv_coord_t x_ofs;
	const lv_coord_t y_ofs;
	const lv_coord_t x_pos;
	const lv_coord_t y_pos;
	const lv_coord_t width;
	const lv_coord_t height;
	const lv_align_t align;
} para_t;
enum nameOfObjects {
	SCREEN_MAIN_MENU,
	BACKGROUND_MAIN_MENU,
	BACKGROUND_INSIDE_VALUES,
	BACKGROUND_OUTSIDE_VALUES,
	BACKGROUND_CLOCK_VALUES,
	BACKGROUND_WEATHER,
	METER_CO2_MAIN_MENU,
	CHART_CO2_MAIN_MENU,
	SLIDER_DISTANCE_MAIN_MENU,
	SYMBOL_TEMPERATURE_INSIDE,
	SYMBOL_HUMIDITY_INSIDE,
	SYMBOL_TVOC,
	SYMBOL_BRIGHTNESS,
	SYMBOL_TEMPERATURE_OUTSIDE,
	SYMBOL_HUMIDITY_OUTSIDE,
	SYMBOL_WIND,
	SYMBOL_PRESS,
	SYMBOL_EYE,
	SYMBOL_BUZZER,
	SYMBOL_WIFI,
	SYMBOL_BATTERY,
	BAR_DISTANCE,
	VALUE_TEMPERATURE_INSIDE,
	VALUE_HUMIDITY_INSIDE,
	VALUE_CO2_INSIDE,
	VALUE_TVOC_INSIDE,
	VALUE_BRIGHTNESS_INSIDE,
	VALUE_TEMPERATURE_OUTSIDE,
	VALUE_HUMIDITY_OUTSIDE,
	VALUE_WIND_OUTSIDE,
	VALUE_PRESS_OUTSIDE,
	IMAGE_SUN,
	IMAGE_MOON,
	IMAGE_CLOUD,
	IMAGE_CLOUD_1,
	IMAGE_WIND,
	IMAGE_WIND_1,
	IMAGE_RAIN,
	IMAGE_RAIN_1,
	IMAGE_SNOW,
	IMAGE_SNOW_1,
	TIME_HOUR_MINUTE,
	TIME_MINUTE,
	TIME_MDAY_MONTH,
	TIME_WDAY,
};

void init_lv_objects() ;

#endif /* INC_LVGL_MENU_H_ */
