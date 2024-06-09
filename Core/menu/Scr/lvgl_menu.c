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
#include "../menu/Inc/lvgl_menu.h"

//extern lv_indev_t *indev_keypad; // for btn group
static lv_meter_indicator_t *indic_co2;
const lv_font_t *font[NUMBERS_OF_FONTS];
static lv_style_t style[NUMBERS_OF_STYLES];
static lv_obj_t *lv_object[NUMBER_OF_OBJECTS];

char string_buffer[20];
#define MAX_VALUE_CO2 2400
#define MIN_VALUE_CO2 400

float map_val(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void print_value(const char *flags, float value, lv_obj_t *value_lv) {
	lv_label_set_text_fmt(value_lv, flags, value);
}
static void create_text(const char *text, lv_obj_t *bg, uint16_t theme, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	lv_obj_t *cont = lv_label_create(bg);
	lv_obj_remove_style_all(cont);
	switch (theme) {
	case STYLE_TEXT_SMALL:
		lv_obj_add_style(cont, &style[STYLE_TEXT_SMALL], 0);
		break;
	case STYLE_TEXT_MEDIUM:
		lv_obj_add_style(cont, &style[STYLE_TEXT_MEDIUM], 0);
		break;
	case STYLE_TEXT_LARGE:
		lv_obj_add_style(cont, &style[STYLE_TEXT_LARGE], 0);
		break;
	}
	lv_label_set_text(cont, text);
	lv_obj_align(cont, align, x_ofs, y_ofs);
}
static lv_obj_t* create_label(lv_obj_t *screen, const char *text, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs) {
	lv_obj_t *con = lv_label_create(screen);
	lv_obj_align(con, align, x_ofs, y_ofs);
	lv_label_set_text(con, text);
	return con;
}
static lv_obj_t* create_meter(lv_obj_t *screen, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	const int16_t start_value = 400;
	const int16_t start_value_1 = 800;
	const int16_t end_value = 2000;
	const int16_t end_value_1 = 2400;

	lv_obj_t *meter = lv_meter_create(screen);
	//lv_obj_remove_style(meter, NULL, LV_PART_MAIN); // remove arc
	//lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);
	lv_obj_set_size(meter, w, h);
	lv_obj_align(meter, align, x_ofs, y_ofs);
	/*Add a scale first*/

	lv_meter_scale_t *scale = lv_meter_add_scale(meter);
	lv_meter_set_scale_ticks(meter, scale, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
	//lv_meter_set_scale_major_ticks(meter, scale, 8, 4, 15, lv_color_black(), 10);
	lv_meter_set_scale_range(meter, scale, 400, 2400, 250, 145);

	/*Add a blue arc to the start*/
	indic_co2 = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_GREEN), 0);
	lv_meter_set_indicator_start_value(meter, indic_co2, start_value);
	lv_meter_set_indicator_end_value(meter, indic_co2, start_value_1);

	/*Make the tick lines blue at the start of the scale*/
	indic_co2 = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_GREEN),
			lv_palette_main(LV_PALETTE_GREEN), false, 0);
	lv_meter_set_indicator_start_value(meter, indic_co2, start_value);
	lv_meter_set_indicator_end_value(meter, indic_co2, start_value_1);

	/*Add a red arc to the end*/
	indic_co2 = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_RED), 0);
	lv_meter_set_indicator_start_value(meter, indic_co2, end_value);
	lv_meter_set_indicator_end_value(meter, indic_co2, end_value_1);

	/*Make the tick lines red at the end of the scale*/
	indic_co2 = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED),
	false, 0);
	lv_meter_set_indicator_start_value(meter, indic_co2, end_value);
	lv_meter_set_indicator_end_value(meter, indic_co2, end_value_1);

	/*Add a needle line indicator*/
	indic_co2 = lv_meter_add_needle_line(meter, scale, 4, lv_palette_main(LV_PALETTE_GREY), -10);

	return meter;
}
static lv_chart_series_t *ser_co2;
static lv_obj_t* create_chart(lv_obj_t *screen, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	lv_obj_t *chart = lv_chart_create(screen);
	lv_obj_set_size(chart, w, h);
	lv_obj_align(chart, align, x_ofs, y_ofs);
	lv_chart_set_div_line_count(chart, 6, 9);
	lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, MIN_VALUE_CO2,
	MAX_VALUE_CO2);
	//lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_Y, 5, 3, 12,2,true, 40);
	ser_co2 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BROWN), LV_CHART_AXIS_PRIMARY_Y);

	return chart;
}
void print_wday(uint8_t wday) {
	switch (wday) {
	case 1:
		lv_label_set_text(lv_object[TIME_WDAY], "mo");
		break;
	case 2:
		lv_label_set_text(lv_object[TIME_WDAY], "tu");
		break;
	case 3:
		lv_label_set_text(lv_object[TIME_WDAY], "we");
		break;
	case 4:
		lv_label_set_text(lv_object[TIME_WDAY], "th");
		break;
	case 5:
		lv_label_set_text(lv_object[TIME_WDAY], "fr");
		break;
	case 6:
		lv_label_set_text(lv_object[TIME_WDAY], "sa");
		break;
	case 7:
		lv_label_set_text(lv_object[TIME_WDAY], "su");
		break;
	}
}
void print_time(uint8_t val1, uint8_t val2) {
	if (val1 < 10 && val2 < 10) {
		sprintf(string_buffer, "0%d:0%d", (int) val1, (int) val2);
	} else if (val1 > 9 && val2 < 10) {
		sprintf(string_buffer, "%d:0%d", (int) val1, (int) val2);
	} else if (val1 < 10 && val2 > 9) {
		sprintf(string_buffer, "0%d:%d", (int) val1, (int) val2);
	} else {
		sprintf(string_buffer, "%d:%d", (int) val1, (int) val2);
	}
	lv_label_set_text(lv_object[TIME_HOUR_MINUTE], string_buffer);
}
void print_mday(uint8_t val1, uint8_t val2) {
	if (val1 < 10 && val2 < 10) {
		sprintf(string_buffer, "0%d.0%d", (int) val1, (int) val2);
	} else if (val1 > 9 && val2 < 10) {
		sprintf(string_buffer, "%d.0%d", (int) val1, (int) val2);
	} else if (val1 < 10 && val2 > 9) {
		sprintf(string_buffer, "0%d.%d", (int) val1, (int) val2);
	} else {
		sprintf(string_buffer, "%d.%d", (int) val1, (int) val2);

	}
	lv_label_set_text(lv_object[TIME_MDAY_MONTH], string_buffer);
}

static lv_obj_t* create_button_symbol(lv_obj_t *bg, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	lv_obj_t *cont = lv_btn_create(bg);
	lv_obj_set_size(cont, w, h);
	//lv_obj_set_style_bg_img_src(cont, symbol, 0);
	lv_obj_align(cont, align, x_ofs, y_ofs);
	return cont;
}
static lv_obj_t* create_background(lv_obj_t *bg, lv_coord_t w, lv_coord_t h, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	lv_obj_t *cont = lv_obj_create(bg);
	lv_obj_set_size(cont, w, h);
	lv_obj_align(cont, align, x_ofs, y_ofs);
	return cont;
}
static void set_angle(void *img, int32_t v) {
	lv_img_set_angle(img, v);
}
static void set_zoom(void *img, int32_t v) {
	lv_img_set_zoom(img, v);
}
static lv_obj_t* create_anim_image_snow_zoom(lv_obj_t *bg, const uint8_t zoom_size, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	LV_IMG_DECLARE(img_snow);

	/*Now create the actual image*/
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_snow);
	lv_obj_align(img, align, x_ofs, y_ofs);
	//lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

	lv_anim_t a;
	lv_anim_init(&a);

	const uint16_t anim_speed_time_s = 60 * 1000; // in sec
	const uint16_t anim_zoom_min_proc = 256;
	const uint16_t anim_zoom_max_proc = 512;

	uint16_t temp = map_val(zoom_size, 0, 100, anim_zoom_min_proc, anim_zoom_max_proc);
	if (temp < 256)
		temp = 256;
	if (temp > 512)
		temp = 512;

	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, anim_zoom_min_proc, temp);
	lv_anim_set_time(&a, anim_speed_time_s);
	lv_anim_set_playback_time(&a, anim_speed_time_s);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);
	return img;
}
static lv_obj_t* create_anim_image_rain_zoom(lv_obj_t *bg, const uint8_t zoom_size, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	LV_IMG_DECLARE(img_rain);

	/*Now create the actual image*/
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_rain);
	lv_obj_align(img, align, x_ofs, y_ofs);
	//lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

	lv_anim_t a;
	lv_anim_init(&a);

	const uint16_t anim_speed_time_s = 60 * 1000; // in sec
	const uint16_t anim_zoom_min_proc = 256;
	const uint16_t anim_zoom_max_proc = 512;

	uint16_t temp = map_val(zoom_size, 0, 100, anim_zoom_min_proc, anim_zoom_max_proc);
	if (temp < 256)
		temp = 256;
	if (temp > 512)
		temp = 512;

	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, anim_zoom_min_proc, temp);
	lv_anim_set_time(&a, anim_speed_time_s);
	lv_anim_set_playback_time(&a, anim_speed_time_s);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);
	return img;
}
static lv_obj_t* create_anim_image_cloud_zoom(lv_obj_t *bg, const uint8_t zoom_size, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	LV_IMG_DECLARE(img_cloud);

	/*Now create the actual image*/
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_cloud);
	lv_obj_align(img, align, x_ofs, y_ofs);
	//lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

	lv_anim_t a;
	lv_anim_init(&a);

	const uint16_t anim_speed_time_s = 60 * 1000; // in sec
	const uint16_t anim_zoom_min_proc = 256;
	const uint16_t anim_zoom_max_proc = 512;

	uint16_t temp = map_val(zoom_size, 0, 100, anim_zoom_min_proc, anim_zoom_max_proc);
	if (temp < 256)
		temp = 256;
	if (temp > 512)
		temp = 512;

	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, anim_zoom_min_proc, temp);
	lv_anim_set_time(&a, anim_speed_time_s);
	lv_anim_set_playback_time(&a, anim_speed_time_s);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);
	return img;
}
static lv_obj_t* create_anim_image_wind_zoom(lv_obj_t *bg, const uint8_t zoom_size, lv_align_t align, lv_coord_t x_ofs,
		lv_coord_t y_ofs) {
	LV_IMG_DECLARE(img_wind);

	/*Now create the actual image*/
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_wind);
	lv_obj_align(img, align, x_ofs, y_ofs);
	//lv_img_set_pivot(img, 0, 0);    /*Rotate around the top left corner*/

	lv_anim_t a;
	lv_anim_init(&a);

	const uint16_t anim_speed_time_s = 60 * 1000; // in sec
	const uint16_t anim_zoom_min_proc = 256;
	const uint16_t anim_zoom_max_proc = 512;

	uint16_t temp = map_val(zoom_size, 0, 100, anim_zoom_min_proc, anim_zoom_max_proc);
	if (temp < 256)
		temp = 256;
	if (temp > 512)
		temp = 512;

	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_zoom);
	lv_anim_set_values(&a, anim_zoom_min_proc, temp);
	lv_anim_set_time(&a, anim_speed_time_s);
	lv_anim_set_playback_time(&a, anim_speed_time_s);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);
	return img;
}
static lv_obj_t* create_anim_image_sun(lv_obj_t *bg, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs) {

	LV_IMG_DECLARE(img_sun);
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_sun);
	lv_obj_align(img, align, x_ofs, y_ofs);

	const uint16_t anim_speed_time_s = 60 * 1000;
	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_var(&a, img);
	lv_anim_set_exec_cb(&a, set_angle);
	lv_anim_set_values(&a, 0, 3600);
	lv_anim_set_time(&a, anim_speed_time_s);
	lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
	lv_anim_start(&a);

	return img;
}
static lv_obj_t* create_image_moon(lv_obj_t *bg, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs) {

	LV_IMG_DECLARE(img_moon);
	lv_obj_t *img = lv_img_create(bg);
	lv_img_set_src(img, &img_moon);
	lv_obj_align(img, align, x_ofs, y_ofs);

	return img;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int16_t x_start_left_block = 30;
static void create_block_top_left() {
	/*STYLES*/
	static lv_style_t style_bg_top_left;
	lv_style_init(&style_bg_top_left);
	lv_style_set_bg_color(&style_bg_top_left, lv_palette_lighten(LV_PALETTE_GREEN, 1));
	/*BLOCK TOP LEFT*/
	para_t bg_top_left = { .width = 150, .height = 130, .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block - 20,
			.y_ofs = 30 };

	create_text("inside", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, bg_top_left.align, bg_top_left.x_ofs + 45,
			bg_top_left.y_ofs - 20);

	lv_object[BACKGROUND_INSIDE_VALUES] = create_background(lv_object[SCREEN_MAIN_MENU], bg_top_left.width,
			bg_top_left.height, bg_top_left.align, bg_top_left.x_ofs, bg_top_left.y_ofs);
	lv_obj_add_style(lv_object[BACKGROUND_INSIDE_VALUES], &style_bg_top_left, 0);

	para_t symbol_inside = { .width = 20, .height = 20, .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block - 15,
			.y_ofs = 20 };
	lv_object[SYMBOL_TEMPERATURE_INSIDE] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_inside.width,
			symbol_inside.height, symbol_inside.align, symbol_inside.x_ofs, symbol_inside.y_ofs + symbol_inside.height);
	lv_object[SYMBOL_HUMIDITY_INSIDE] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_inside.width,
			symbol_inside.height, symbol_inside.align, symbol_inside.x_ofs,
			symbol_inside.y_ofs + symbol_inside.height * 2 + 10);
	lv_object[SYMBOL_TVOC] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_inside.width,
			symbol_inside.height, symbol_inside.align, symbol_inside.x_ofs,
			symbol_inside.y_ofs + symbol_inside.height * 3 + 20);
	lv_object[SYMBOL_BRIGHTNESS] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_inside.width,
			symbol_inside.height, symbol_inside.align, symbol_inside.x_ofs,
			symbol_inside.y_ofs + symbol_inside.height * 4 + 30);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_TEMPERATURE_INSIDE],
	LV_SYMBOL_NEW_LINE, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_HUMIDITY_INSIDE],
	LV_SYMBOL_TINT, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_TVOC], LV_SYMBOL_EDIT, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BRIGHTNESS], LV_SYMBOL_TRASH, 0);

	const int16_t y_offset_inside = 29;
	para_t values_inside = { .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block + 15, .y_ofs = 40 };
	lv_object[VALUE_TEMPERATURE_INSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0", values_inside.align,
			values_inside.x_ofs, values_inside.y_ofs);
	lv_obj_add_style(lv_object[VALUE_TEMPERATURE_INSIDE], &style[STYLE_TEXT_LARGE], 0);
	create_text("c*", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, values_inside.align, values_inside.x_ofs + 90,
			values_inside.y_ofs);
	lv_object[VALUE_HUMIDITY_INSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 %*", values_inside.align,
			values_inside.x_ofs, values_inside.y_ofs + y_offset_inside + 4);
	lv_object[VALUE_TVOC_INSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 ppm", values_inside.align,
			values_inside.x_ofs, values_inside.y_ofs + y_offset_inside * 2 + 4);
	lv_object[VALUE_BRIGHTNESS_INSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 lux", values_inside.align,
			values_inside.x_ofs, values_inside.y_ofs + y_offset_inside * 3 + 4);

	/*BLOCK TOP LEFT*/
}
static void create_block_top_middle() {
	/*BLOCK TOP MID*/
	para_t meter_co2 = { .width = 150, .height = 150, .align = LV_ALIGN_TOP_MID, .x_ofs = 0, .y_ofs = 15 };
	para_t co2_value = { .align = LV_ALIGN_TOP_MID, .x_ofs = 0, .y_ofs = 120 };
	lv_object[METER_CO2_MAIN_MENU] = create_meter(lv_object[SCREEN_MAIN_MENU], meter_co2.width, meter_co2.height,
			meter_co2.align, meter_co2.x_ofs, meter_co2.y_ofs);
	lv_meter_set_indicator_value(lv_object[METER_CO2_MAIN_MENU], indic_co2, 0);

	create_text("ppm", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, meter_co2.align, meter_co2.x_ofs,
			meter_co2.y_ofs + 45);

	lv_object[VALUE_CO2_INSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0", co2_value.align, co2_value.x_ofs,
			co2_value.y_ofs);
	lv_obj_add_style(lv_object[VALUE_CO2_INSIDE], &style[STYLE_TEXT_LARGE], 0);
	/*BLOCK TOP MID*/
}
static void create_block_top_right() {
	/*STYLES*/
	static lv_style_t style_bg_top_right;
	lv_style_init(&style_bg_top_right);
	lv_style_set_bg_color(&style_bg_top_right, lv_palette_lighten(LV_PALETTE_GREEN, 1));
	/*BLOCK TOP RIGHT*/
	const int16_t time_offset_y = 53;
	para_t bg_top_right = { .width = 150, .height = 130, .align = LV_ALIGN_TOP_LEFT, .x_ofs = 320, .y_ofs = 30 };
	para_t time_ = { .align = LV_ALIGN_TOP_LEFT, .x_ofs = 316, .y_ofs = 36 };

	lv_object[BACKGROUND_CLOCK_VALUES] = create_background(lv_object[SCREEN_MAIN_MENU], bg_top_right.width,
			bg_top_right.height, bg_top_right.align, bg_top_right.x_ofs, bg_top_right.y_ofs);
	lv_obj_add_style(lv_object[BACKGROUND_CLOCK_VALUES], &style_bg_top_right, 0);

	create_text("time", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, bg_top_right.align, bg_top_right.x_ofs + 55,
			bg_top_right.y_ofs - 20);

	lv_object[TIME_HOUR_MINUTE] = create_label(lv_object[SCREEN_MAIN_MENU], "00:00", time_.align, time_.x_ofs,
			time_.y_ofs);
	lv_obj_add_style(lv_object[TIME_HOUR_MINUTE], &style[STYLE_TEXT_VERY_LARGE], 0);

	lv_object[TIME_MDAY_MONTH] = create_label(lv_object[SCREEN_MAIN_MENU], "00.00", time_.align, time_.x_ofs,
			time_.y_ofs + time_offset_y);
	lv_obj_add_style(lv_object[TIME_MDAY_MONTH], &style[STYLE_TEXT_VERY_LARGE], 0);

	lv_object[TIME_WDAY] = create_label(lv_object[SCREEN_MAIN_MENU], "load...", time_.align, time_.x_ofs + 65,
			time_.y_ofs + time_offset_y * 2 - 5);
	/*BLOCK TOP RIGHT*/
}
static void create_block_bot_left() {
	/*STYLES*/
	static lv_style_t style_bg_bot_left;
	lv_style_init(&style_bg_bot_left);
	lv_style_set_bg_color(&style_bg_bot_left, lv_palette_lighten(LV_PALETTE_ORANGE, 1));
	/*BLOCK BOT LEFT*/
	const int16_t y_offset_outside = 29;
	para_t bg_outside = { .width = 150, .height = 130, .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block - 20,
			.y_ofs = 180 };
	create_text("outside", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, bg_outside.align, bg_outside.x_ofs + 45,
			bg_outside.y_ofs - 20);

	lv_object[BACKGROUND_OUTSIDE_VALUES] = create_background(lv_object[SCREEN_MAIN_MENU], bg_outside.width,
			bg_outside.height, bg_outside.align, bg_outside.x_ofs, bg_outside.y_ofs);
	lv_obj_add_style(lv_object[BACKGROUND_OUTSIDE_VALUES], &style_bg_bot_left, 0);

	para_t symbol_outside = { .width = 20, .height = 20, .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block - 15,
			.y_ofs = 170 };
	lv_object[SYMBOL_TEMPERATURE_OUTSIDE] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_outside.width,
			symbol_outside.height, symbol_outside.align, symbol_outside.x_ofs,
			symbol_outside.y_ofs + symbol_outside.height);
	lv_object[SYMBOL_HUMIDITY_OUTSIDE] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_outside.width,
			symbol_outside.height, symbol_outside.align, symbol_outside.x_ofs,
			symbol_outside.y_ofs + symbol_outside.height * 2 + 10);
	lv_object[SYMBOL_WIND] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_outside.width,
			symbol_outside.height, symbol_outside.align, symbol_outside.x_ofs,
			symbol_outside.y_ofs + symbol_outside.height * 3 + 20);
	lv_object[SYMBOL_PRESS] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_outside.width,
			symbol_outside.height, symbol_outside.align, symbol_outside.x_ofs,
			symbol_outside.y_ofs + symbol_outside.height * 4 + 30);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_TEMPERATURE_OUTSIDE],
	LV_SYMBOL_NEW_LINE, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_HUMIDITY_OUTSIDE],
	LV_SYMBOL_TINT, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_WIND], LV_SYMBOL_SD_CARD, 0);
	lv_obj_set_style_bg_img_src(lv_object[SYMBOL_PRESS], LV_SYMBOL_BACKSPACE, 0);

	para_t values_outside = { .align = LV_ALIGN_TOP_LEFT, .x_ofs = x_start_left_block + 15, .y_ofs = 190 };
	lv_object[VALUE_TEMPERATURE_OUTSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 c*", values_outside.align,
			values_outside.x_ofs, values_outside.y_ofs);
	lv_obj_add_style(lv_object[VALUE_TEMPERATURE_OUTSIDE], &style[STYLE_TEXT_LARGE], 0);
	create_text("c*", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, values_outside.align, values_outside.x_ofs + 90,
			values_outside.y_ofs);
	lv_object[VALUE_HUMIDITY_OUTSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 %", values_outside.align,
			values_outside.x_ofs, values_outside.y_ofs + y_offset_outside + 4);
	lv_object[VALUE_WIND_OUTSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 m/s", values_outside.align,
			values_outside.x_ofs, values_outside.y_ofs + y_offset_outside * 2 + 4);
	lv_object[VALUE_PRESS_OUTSIDE] = create_label(lv_object[SCREEN_MAIN_MENU], "0 hPa", values_outside.align,
			values_outside.x_ofs, values_outside.y_ofs + y_offset_outside * 3 + 4);
	/*BLOCK BOT LEFT*/
}
static void create_block_bot_middle() {
	/*STYLES*/
	static lv_style_t style_chart_co2;
	lv_style_init(&style_chart_co2);
	lv_style_set_bg_opa(&style_chart_co2, LV_OPA_COVER);
	lv_style_set_bg_color(&style_chart_co2, lv_palette_main(LV_PALETTE_RED));
	lv_style_set_bg_grad_color(&style_chart_co2, lv_palette_lighten(LV_PALETTE_GREEN, 1));
	lv_style_set_bg_grad_dir(&style_chart_co2, LV_GRAD_DIR_VER);
	lv_style_set_bg_main_stop(&style_chart_co2, 128);
	lv_style_set_bg_grad_stop(&style_chart_co2, 192);
	/*BLOCK BOT MID*/
	para_t chart_co2 = { .width = 150, .height = 70, .align = LV_ALIGN_TOP_MID, .x_ofs = 0, .y_ofs = 180 };

	create_text("co2           24h", lv_object[SCREEN_MAIN_MENU], STYLE_TEXT_SMALL, chart_co2.align, chart_co2.x_ofs,
			chart_co2.y_ofs - 20);

	lv_object[CHART_CO2_MAIN_MENU] = create_chart(lv_object[SCREEN_MAIN_MENU], chart_co2.width, chart_co2.height,
			chart_co2.align, chart_co2.x_ofs, chart_co2.y_ofs);
	lv_obj_add_style(lv_object[CHART_CO2_MAIN_MENU], &style_chart_co2, 0);

	para_t symbol_notification = { .width = 30, .height = 30, .align = LV_ALIGN_TOP_LEFT, .x_ofs = 170, .y_ofs = 275 };
	lv_object[SYMBOL_EYE] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_notification.width,
			symbol_notification.height, symbol_notification.align, symbol_notification.x_ofs,
			symbol_notification.y_ofs);
	lv_object[SYMBOL_BUZZER] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_notification.width,
			symbol_notification.height, symbol_notification.align,
			symbol_notification.x_ofs + symbol_notification.width + 4, symbol_notification.y_ofs);
	lv_object[SYMBOL_WIFI] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_notification.width,
			symbol_notification.height, symbol_notification.align,
			symbol_notification.x_ofs + symbol_notification.width * 2 + 8, symbol_notification.y_ofs);
	lv_object[SYMBOL_BATTERY] = create_button_symbol(lv_object[SCREEN_MAIN_MENU], symbol_notification.width,
			symbol_notification.height, symbol_notification.align,
			symbol_notification.x_ofs + symbol_notification.width * 3 + 16, symbol_notification.y_ofs);
	para_t bar_distance = { .width = 150, .height = 10, .align = LV_ALIGN_TOP_LEFT, .x_ofs = 165, .y_ofs = 259 };
	lv_object[BAR_DISTANCE] = lv_bar_create(lv_object[SCREEN_MAIN_MENU]);
	//lv_obj_add_event_cb(BAR_DISTANCE, event_cb, LV_EVENT_DRAW_PART_END, NULL);
	lv_obj_align(lv_object[BAR_DISTANCE], bar_distance.align, bar_distance.x_ofs, bar_distance.y_ofs);
	lv_obj_set_size(lv_object[BAR_DISTANCE], bar_distance.width, bar_distance.height);
	lv_bar_set_range(lv_object[BAR_DISTANCE], 0, TIME_STANDBY);
	/*BLOCK BOT MID*/
}
static void create_block_bot_right() {
	/*BLOCK BOT RIGHT*/
	para_t symbol_weather = { .align = LV_ALIGN_TOP_LEFT, .x_ofs = 335, .y_ofs = 170 };

	lv_object[IMAGE_SUN] = create_anim_image_sun(lv_object[SCREEN_MAIN_MENU], symbol_weather.align,
			symbol_weather.x_ofs + 70, symbol_weather.y_ofs + 5);
	lv_object[IMAGE_MOON] = create_image_moon(lv_object[SCREEN_MAIN_MENU], symbol_weather.align,
			symbol_weather.x_ofs + 70, symbol_weather.y_ofs + 5);
	lv_object[IMAGE_CLOUD] = create_anim_image_cloud_zoom(lv_object[SCREEN_MAIN_MENU], 30, symbol_weather.align,
			symbol_weather.x_ofs, symbol_weather.y_ofs + 10);
	lv_object[IMAGE_CLOUD_1] = create_anim_image_cloud_zoom(lv_object[SCREEN_MAIN_MENU], 50, symbol_weather.align,
			symbol_weather.x_ofs + 20, symbol_weather.y_ofs + 60);
	lv_object[IMAGE_WIND] = create_anim_image_wind_zoom(lv_object[SCREEN_MAIN_MENU], 30, symbol_weather.align,
			symbol_weather.x_ofs + 10, symbol_weather.y_ofs + 80);
	lv_object[IMAGE_RAIN] = create_anim_image_rain_zoom(lv_object[SCREEN_MAIN_MENU], 30, symbol_weather.align,
			symbol_weather.x_ofs, symbol_weather.y_ofs + 40);
	lv_object[IMAGE_RAIN_1] = create_anim_image_rain_zoom(lv_object[SCREEN_MAIN_MENU], 50, symbol_weather.align,
			symbol_weather.x_ofs + 60, symbol_weather.y_ofs + 80);
	lv_object[IMAGE_SNOW] = create_anim_image_snow_zoom(lv_object[SCREEN_MAIN_MENU], 10, symbol_weather.align,
			symbol_weather.x_ofs + 40, symbol_weather.y_ofs + 40);
	lv_object[IMAGE_SNOW_1] = create_anim_image_snow_zoom(lv_object[SCREEN_MAIN_MENU], 50, symbol_weather.align,
			symbol_weather.x_ofs + 60, symbol_weather.y_ofs + 80);

//	lv_obj_add_flag(lv_object[IMAGE_MOON], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_SUN], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_CLOUD], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_CLOUD_1], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_WIND], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_RAIN], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_RAIN_1], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_SNOW], LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(lv_object[IMAGE_SNOW_1], LV_OBJ_FLAG_HIDDEN);
	/*BLOCK BOT RIGHT*/
}
static void create_menu() {
	lv_object[SCREEN_MAIN_MENU] = lv_obj_create(NULL);
	lv_object[BACKGROUND_MAIN_MENU] = lv_obj_create(lv_object[SCREEN_MAIN_MENU]);
	lv_obj_set_size(lv_object[BACKGROUND_MAIN_MENU], MY_DISP_HOR_RES,
	MY_DISP_VER_RES);
	/*STYLES*/
	create_block_top_left();
	create_block_bot_left();
	create_block_top_middle();
	create_block_bot_middle();
	create_block_top_right();
	create_block_bot_right();
}
void draw_menu_main() {
	lv_scr_load(lv_object[SCREEN_MAIN_MENU]);
}
void set_flag(lv_obj_t *obj, bool f) {
	switch (f) {
	case 0:
		lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN); // off
		break;
	case 1:
		lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN); // on
		break;
	}
}
void draw_weather_sun_moon() {
	if (read_time_hour() > TIME_DAY_START && read_time_hour() < TIME_DAY_END) {
		set_flag(lv_object[IMAGE_SUN], true);
		set_flag(lv_object[IMAGE_MOON], false);
	} else {
		set_flag(lv_object[IMAGE_SUN], false);
		set_flag(lv_object[IMAGE_MOON], true);
	}
}
void draw_weather_clouds() {
	uint8_t current_clouds = read_weather_clouds();
	if (current_clouds < 50) {
		set_flag(lv_object[IMAGE_CLOUD], false);
		set_flag(lv_object[IMAGE_CLOUD_1], false);
	} else {
		set_flag(lv_object[IMAGE_CLOUD], true);
		set_flag(lv_object[IMAGE_CLOUD_1], true);
	}
}
void draw_weather_wind() {
	uint8_t current_wind = read_weather_wind();
	if (current_wind < 5) {
		set_flag(lv_object[IMAGE_WIND], false);
	} else {
		set_flag(lv_object[IMAGE_WIND], true);
	}
}
void draw_weather_rain() {
	uint8_t current_rain = read_weather_rain();
	if (current_rain > 1) {
		set_flag(lv_object[IMAGE_RAIN], true);
		set_flag(lv_object[IMAGE_RAIN_1], true);
	} else {
		set_flag(lv_object[IMAGE_RAIN], false);
		set_flag(lv_object[IMAGE_RAIN_1], false);
	}
}
void draw_weather_snow() {
	uint8_t current_snow = read_weather_snow();
	if (current_snow > 1) {
		set_flag(lv_object[IMAGE_SNOW], true);
		set_flag(lv_object[IMAGE_SNOW_1], true);
	} else {
		set_flag(lv_object[IMAGE_SNOW], false);
		set_flag(lv_object[IMAGE_SNOW_1], false);
	}
}
void draw_weather() {
	draw_weather_sun_moon();
	draw_weather_clouds();
	draw_weather_wind();
	draw_weather_rain();
	draw_weather_snow();
}
void draw_symbol_battery() {
	static uint8_t status_battery_old = 254;
	if (read_battery_status() != status_battery_old) {
		switch (read_battery_status()) {
		case 1:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_EMPTY, 0);
			break;
		case 2:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_1, 0);
			break;
		case 3:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_2, 0);
			break;
		case 4:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_3, 0);
			break;
		case 5:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_FULL, 0);
			break;
		default:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BATTERY],
			LV_SYMBOL_BATTERY_EMPTY, 0);
			break;
		}
		status_battery_old = read_battery_status();
	}
}
void draw_symbol_wifi() {
	static uint8_t status_wifi_old = 254;
	if (read_wifi() != status_wifi_old) {
		switch (read_wifi()) {
		case WIFI_CONNECTING:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_WIFI],
			LV_SYMBOL_REFRESH, 0);
			break;
		case WIFI_CONNECTED:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_WIFI], LV_SYMBOL_WIFI, 0);
			break;
		case WIFI_DISCONNECTED:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_WIFI],
			LV_SYMBOL_WARNING, 0);
			break;
		default:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_WIFI],
			LV_SYMBOL_WARNING, 0);
			break;
		}
		status_wifi_old = read_wifi();
	}
}
void draw_symbol_volume() {
	static uint8_t read_volume_old = 254;
	if (read_volume_dfplayer() != read_volume_old) {
		switch (read_volume_dfplayer()) {
		case 1:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BUZZER],
			LV_SYMBOL_MUTE, 0);
			break;
		case 2:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BUZZER],
			LV_SYMBOL_VOLUME_MID, 0);
			break;
		case 3:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BUZZER],
			LV_SYMBOL_VOLUME_MAX, 0);
			break;
		default:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_BUZZER],
			LV_SYMBOL_MUTE, 0);
			break;
		}
		read_volume_old = read_volume_dfplayer();
	}
	DFPlayer_setVolume(read_potentiometer());
}

void draw_symbol_distance() {
	static uint8_t range_old = 254;
	if (range_read() != range_old) {
		switch (range_read()) {
		case RANGE_0:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_EYE],
			LV_SYMBOL_EYE_CLOSE, 0);
			break;
		case RANGE_1:
			lv_obj_set_style_bg_img_src(lv_object[SYMBOL_EYE],
			LV_SYMBOL_EYE_OPEN, 0);
			break;
			range_old = range_read();
		}
	}
}
static void timer_500(lv_timer_t *timer) {
	LV_UNUSED(timer);
	range_handler();
}
static void timer_50(lv_timer_t *timer) {
	LV_UNUSED(timer);
	esp_read();
}
void update_block_top_left() {
	aht10_read();
	sgp30_read();
	print_value("%.1f", read_temperature_aht10(), lv_object[VALUE_TEMPERATURE_INSIDE]);
	print_value("%.f %%", read_humidity_aht10(), lv_object[VALUE_HUMIDITY_INSIDE]);
	print_value("%.f ppm", read_tvoc_sgp30(), lv_object[VALUE_TVOC_INSIDE]);
	print_value("%.f lux", temt6000_read(), lv_object[VALUE_BRIGHTNESS_INSIDE]);
}
void update_block_top_middle() {
	print_value("%.f", read_co2_sgp30(), lv_object[VALUE_CO2_INSIDE]);
	lv_meter_set_indicator_value(lv_object[METER_CO2_MAIN_MENU], indic_co2, read_co2_sgp30());
}
void update_block_top_right() {
	static uint8_t cnt_time_delay = 10;
	cnt_time_delay--;
	if (cnt_time_delay == 0) {
		print_time(read_time_hour(), read_time_minute());
		print_mday(read_time_mday(), read_time_month());
		print_wday(read_time_wday());
		cnt_time_delay = 1;
	}
}
void update_block_bot_left() {
	print_value("%.1f", read_weather_temperature(), lv_object[VALUE_TEMPERATURE_OUTSIDE]);
	print_value("%.f %%", read_weather_humidity(), lv_object[VALUE_HUMIDITY_OUTSIDE]);
	print_value("%.1f m/s", read_weather_wind(), lv_object[VALUE_WIND_OUTSIDE]);
	print_value("%.f hPa", read_weather_press(), lv_object[VALUE_PRESS_OUTSIDE]);
}
void update_block_bot_middle() {
	static uint16_t cnt_chart_co2 = 0;
	cnt_chart_co2++; // 1 tick == 1 sec
	if (cnt_chart_co2 > 3600) { // equal 1 hour
		uint16_t temp_co2_chart = read_co2_sgp30();
		if (temp_co2_chart > MAX_VALUE_CO2)
			temp_co2_chart = MAX_VALUE_CO2;
		lv_chart_set_next_value(lv_object[CHART_CO2_MAIN_MENU], ser_co2, temp_co2_chart);
		cnt_chart_co2 = 0;
	}
	draw_symbol_battery();
	draw_symbol_wifi();
	draw_symbol_volume();
	draw_symbol_distance();
	lv_bar_set_value(lv_object[BAR_DISTANCE], read_standby_time(), LV_ANIM_OFF);
}
void update_block_bot_right() {
	//static uint16_t cnt_weather = 0;
	//cnt_weather++;
	//if (cnt_weather > 120) { /////////////////////////////////////////////////////////////////////// equal 4 min
	draw_weather();
	//	cnt_weather = 0;
	//}
}
static void timer_1000(lv_timer_t *timer) {
	LV_UNUSED(timer);
	update_block_top_left();
	update_block_top_middle();
	update_block_top_right();
	update_block_bot_left();
	update_block_bot_middle();
	update_block_bot_right();
}

static void init_fonts() {
	lv_style_init(&style[STYLE_TEXT_SMALL]);
	lv_style_set_text_font(&style[STYLE_TEXT_SMALL], &lv_font_montserrat_18);
	//lv_style_init(&style[STYLE_TEXT_MEDIUM]);
	//lv_style_set_text_font(&style[STYLE_TEXT_MEDIUM], &lv_font_montserrat_26);
	lv_style_init(&style[STYLE_TEXT_LARGE]);
	lv_style_set_text_font(&style[STYLE_TEXT_LARGE], &lv_font_montserrat_36);
	lv_style_init(&style[STYLE_TEXT_VERY_LARGE]);
	lv_style_set_text_font(&style[STYLE_TEXT_VERY_LARGE], &lv_font_montserrat_48);
}
void init_lv_objects() {
	init_fonts();
	create_menu();
	draw_menu_main();
	lv_timer_create(timer_1000, 1000, NULL);
	lv_timer_create(timer_500, 500, NULL);
	lv_timer_create(timer_50, 50, NULL);
	HAL_Delay(500);
}

