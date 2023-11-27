/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev.h"
#include "lvgl.h"
#include "stm32f4xx_hal.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

//static void button_init(void);
//static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
//static int8_t button_get_pressed_id(void);
//static bool button_is_pressed(uint8_t id);

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
static uint32_t keypad_get_key(void);
/**********************
 *  STATIC VARIABLES
 **********************/

//lv_indev_t *indev_button;
lv_indev_t *indev_keypad;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


void lv_port_indev_init(void) {
	/**
	 * Here you will find example implementation of input devices supported by LittelvGL:
	 *  - Touchpad
	 *  - Mouse (with cursor support)
	 *  - Keypad (supports GUI usage only with key)
	 *  - Encoder (supports GUI usage only with: left, right, push)
	 *  - Button (external buttons to press points on the screen)
	 *
	 *  The `..._read()` function are only examples.
	 *  You should shape them according to your hardware
	 */

	static lv_indev_drv_t indev_drv;

	/*------------------
	 * Keypad
	 * -----------------*/

	/*Initialize your keypad or keyboard if you have*/
	keypad_init();

	/*Register a keypad input device*/
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_KEYPAD;
	indev_drv.read_cb = keypad_read;
	indev_keypad = lv_indev_drv_register(&indev_drv);

//	lv_group_t * g = lv_group_create();
//	lv_indev_set_group(indev_keypad, g);
//	lv_group_add_obj(g,  roller1);

	/*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
	 *add objects to the group with `lv_group_add_obj(group, obj)`
	 *and assign this input device to group to navigate in it:
	 *`lv_indev_set_group(indev_keypad, group);`*/

	/*------------------
	 * Button
	 * -----------------*/

	/*Initialize your button if you have*/
//	button_init();

	/*Register a button input device*/
//	lv_indev_drv_init(&indev_drv);
//	indev_drv.type = LV_INDEV_TYPE_BUTTON;
//	indev_drv.read_cb = button_read;
//	indev_button = lv_indev_drv_register(&indev_drv);
//
//	/*Assign buttons to points on the screen*/
//	static const lv_point_t btn_points[5] = { { x_nav_btn_up, y_nav_btn_up }, /*Button 1 -> x:10; y:10*/
//	{ x_nav_btn_left, y_nav_btn_left }, /*Button 2 -> x:40; y:100*/
//	{ x_nav_btn_enter, y_nav_btn_enter }, /*Button 3 -> x:10; y:10*/
//	{ x_nav_btn_right, y_nav_btn_right }, /*Button 4 -> x:40; y:100*/
//	{ x_nav_btn_down, y_nav_btn_down }, /*Button 5 -> x:10; y:10*/
//	};
//	lv_indev_set_button_points(indev_button, btn_points);
}

/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
//static void button_init(void) {
//	/*Your code comes here*/
//}
//
///*Will be called by the library to read the button*/
//static void button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
//
//	static uint8_t last_btn = 0;
//
//	/*Get the pressed button's ID*/
//	int8_t btn_act = button_get_pressed_id();
//
//	if (btn_act >= 0) {
//		data->state = LV_INDEV_STATE_PR;
//		last_btn = btn_act;
//	} else {
//		data->state = LV_INDEV_STATE_REL;
//	}
//
//	/*Save the last pressed button's ID*/
//	data->btn_id = last_btn;
//}
//
///*Get ID  (0, 1, 2 ..) of the pressed button*/
//static int8_t button_get_pressed_id(void) {
//	uint8_t i;
//
//	/*Check to buttons see which is being pressed (assume there are 2 buttons)*/
//	for (i = 0; i < 5; i++) {
//		/*Return the pressed button's ID*/
//		if (button_is_pressed(i)) {
//			return i;
//		}
//	}
//
//	/*No button pressed*/
//	return -1;
//}
//
///*Test if `id` button is pressed or not*/
//static bool button_is_pressed(uint8_t id) {
//	uint8_t i;
//
//	switch (id) {
//	case 0:
//		i = !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8); //up
//		break;
//	case 1:
//		i = !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9); //l
//		break;
//	case 2:
//		i = !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10); //m
//		break;
//	case 3:
//		i = !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11); //r
//		break;
//	case 4:
//		i = !HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12); //d
//		break;
//	default:
//		break;
//	}
//
//	if (i == 0) {
//		return true;
//	}
//	/*Your code comes here*/
//
//	return false;
//}

	/*Initialize your keypad*/
	static void keypad_init(void) {
		/*Your code comes here*/
	}

	/*Will be called by the library to read the mouse*/
	static void keypad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
		static uint32_t last_key = 0;

		/*Get the current x and y coordinates*/
		//mouse_get_xy(&data->point.x, &data->point.y);

		/*Get whether the a key is pressed and save the pressed key*/
		uint32_t act_key = keypad_get_key();
		if (act_key != 0) {
			data->state = LV_INDEV_STATE_PR;
			/*Translate the keys to LVGL control characters according to your key definitions*/
			switch (act_key) {
			case 1:
				act_key = LV_KEY_UP;
				//key_up();
				break;
			case 2:
				act_key = LV_KEY_PREV;//LV_KEY_PREV
				//key_left();
				break;
			case 3:
				act_key = LV_KEY_ENTER;
				break;
			case 4:
				act_key = LV_KEY_NEXT;//LV_KEY_PREV
				//key_right();
				break;
			case 5:
				act_key = LV_KEY_DOWN;
				//key_down();
				break;
			}
			last_key = act_key;
		} else {
			data->state = LV_INDEV_STATE_REL;
		}
		data->key = last_key;
	}

	/*Get the currently being pressed key.  0 if no key is pressed*/
	static uint32_t keypad_get_key(void) {
		uint8_t key_val = 0;
		/*Your code comes here*/

		if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_8))
			key_val = 1; //up
		if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9))
			key_val = 2; //l
		if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10))
			key_val = 3; //m
		if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11))
			key_val = 4; //r
		if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12))
			key_val = 5; //d

		return key_val;
	}


#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
