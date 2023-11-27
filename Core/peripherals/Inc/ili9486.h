/*
 Library:					TFT 3.2" LCD - ILI9486
 Written by:					Alex Onop
 Date written:				27/12/2020
 Description:				This library makes use of the FSMC interface of the STM32 board to control a TFT LCD.
 */

//List of includes
#include <stdbool.h>
#include "stm32f4xx_hal.h"

//------------------------------------------------
#define RESET_ACTIVE HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET)
#define RESET_IDLE HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET)

//LCD dimensions defines
#define ILI9486_WIDTH       320
#define ILI9486_HEIGHT      480
#define ILI9486_PIXEL_COUNT	ILI9486_WIDTH * ILI9486_HEIGHT
//ILI9486 LCD commands
#define ILI9486_RESET			 		    0x01
#define ILI9486_SLEEPIN            			0x10
#define ILI9486_SLEEP_OUT		  			0x11
#define ILI9486_GAMMA			    		0x26
#define ILI9486_DISPLAY_OFF					0x28
#define ILI9486_DISPLAY_ON					0x29
#define ILI9486_COLUMN_ADDR					0x2A
#define ILI9486_PAGE_ADDR			  		0x2B
#define ILI9486_GRAM				    	0x2C
#define ILI9486_TEARING_OFF					0x34
#define ILI9486_TEARING_ON					0x35
#define ILI9486_DISPLAY_INVERSION		    0xb4
#define ILI9486_MAC			        		0x36
#define ILI9486_PIXEL_FORMAT    		    0x3A
#define ILI9486_WDB			    	  		0x51
#define ILI9486_WCD				      		0x53
#define ILI9486_RGB_INTERFACE   		    0xB0
#define ILI9486_FRC					    	0xB1
#define ILI9486_BPC					    	0xB5
#define ILI9486_DFC				 	    	0xB6
#define ILI9486_Entry_Mode_Set		        0xB7
#define ILI9486_POWER1						0xC0
#define ILI9486_POWER2						0xC1
#define ILI9486_VCOM1						0xC5
#define ILI9486_VCOM2						0xC7
#define ILI9486_POWERA						0xCB
#define ILI9486_POWERB						0xCF
#define ILI9486_PGAMMA						0xE0
#define ILI9486_NGAMMA						0xE1
#define ILI9486_DTCA						0xE8
#define ILI9486_DTCB						0xEA
#define ILI9486_POWER_SEQ					0xED
#define ILI9486_3GAMMA_EN					0xF2
#define ILI9486_INTERFACE					0xF6
#define ILI9486_PRC				   	  	    0xF7
#define ILI9486_VERTICAL_SCROLL 	        0x33
#define ILI9486_VERTICAL_SCROLL_ADDR 	    0x37
#define ILI9486_NORMAL_MODE 	            0x13

#define ILI9486_MEMCONTROL 0x36
#define ILI9486_MADCTL_MY  0x80
#define ILI9486_MADCTL_MX  0x40
#define ILI9486_MADCTL_MV  0x20
#define ILI9486_MADCTL_ML  0x10
#define ILI9486_MADCTL_RGB 0x00
#define ILI9486_MADCTL_BGR 0x08
#define ILI9486_MADCTL_MH  0x04

//List of colors
#define COLOR_BLACK           0x0000  
#define COLOR_NAVY            0x000F      
#define COLOR_DGREEN          0x03E0     
#define COLOR_DCYAN           0x03EF  
#define COLOR_MAROON          0x7800 
#define COLOR_PURPLE          0x780F
#define COLOR_OLIVE           0x7BE0     
#define COLOR_LGRAY           0xC618      
#define COLOR_DGRAY           0x7BEF    
#define COLOR_BLUE            0x001F    
#define COLOR_BLUE2			  0x051D
#define COLOR_GREEN           0x07E0      
#define COLOR_GREEN2		  0xB723
#define COLOR_GREEN3		  0x8000
#define COLOR_CYAN            0x07FF   
#define COLOR_RED             0xF800    
#define COLOR_MAGENTA         0xF81F    
#define COLOR_YELLOW          0xFFE0   
#define COLOR_WHITE           0xFFFF     
#define COLOR_ORANGE          0xFD20     
#define COLOR_GREENYELLOW     0xAFE5     
#define COLOR_BROWN 		  0XBC40


//Functions defines Macros
#define swap(a, b) { int16_t t = a; a = b; b = t; }
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#define min(a,b) (((a)<(b))?(a):(b))


//3.1 delays
void pushColors(uint16_t *data, int16_t len, bool first);
void ILI9486_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2,
		uint16_t y2);
void ILI9486_setRotation(uint8_t rotate);
void ILI9486_fill(uint16_t color);
void ILI9486_Init(void);
void ILI9486_SetBrightness_Auto();
void ILI9486_SetBrightness(uint8_t brightness);
//4. Initialise function

