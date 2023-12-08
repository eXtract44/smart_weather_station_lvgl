#include "../lvgl/lvgl.h"

/*
 *https://lvgl.io/tools/imageconverter -> CF_TRUE_COLOR_ALPHA
 *
 *take this format
 *#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped
 * */

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_IMG_RAIN
#define LV_ATTRIBUTE_IMG_IMG_RAIN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_IMG_RAIN uint8_t img_rain_map[] = {

		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x05, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd7, 0x5d, 0x4c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3d, 0x14, 0x7b, 0xff, 0xff, 0xfa, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x71, 0x0b, 0x9e, 0x79, 0xfe, 0xff, 0xff, 0x31, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x10, 0xfe, 0xef, 0xbf, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0xea, 0x55, 0x35, 0xfe, 0xff, 0xff, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0xb2, 0x04, 0x10, 0xfe, 0xa6, 0x9a, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x69, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xef, 0xbe, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x51, 0x31, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x3c, 0xd3, 0xfe, 0xff, 0xff, 0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x04, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x85, 0xf8, 0xfe, 0xff, 0xff, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0xd3, 0x05, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xcf, 0x3c, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x04, 0x4d, 0x35, 0xfe, 0x14, 0x51, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x1c, 0x51, 0xfe, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0xb2, 0x0e, 0xa6, 0x9a, 0xfe, 0xe7, 0x9e, 0xfe, 0x7d, 0xd7, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x5d, 0x55, 0xfe, 0xff, 0xff, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xd3, 0x11, 0xa6, 0x9a, 0xfe, 0xdf, 0x7d, 0xfe, 0xdf, 0x5d, 0xfe, 0x34, 0xd3, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x8e, 0x39, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x72, 0x2a, 0xa6, 0x9a, 0xfe, 0xcf, 0x3d, 0xfe, 0xcf, 0x3d, 0xfe, 0x86, 0x18, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xc7, 0x1c, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x71, 0x69, 0xa6, 0x9a, 0xfe, 0xc7, 0x1c, 0xfe, 0xc7, 0x1c, 0xfe, 0xbe, 0xfb, 0xfe, 0x1c, 0x71, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x0c, 0x10, 0xfe, 0xff, 0xdf, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x92, 0x9c, 0xa6, 0x9a, 0xfe, 0xbe, 0xfb, 0xfe, 0xbe, 0xdb, 0xfe, 0xb6, 0xdb, 0xfe, 0x65, 0x76, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x34, 0xd3, 0xfe, 0xff, 0xff, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0xd3, 0xdc, 0xa6, 0x9a, 0xfe, 0xae, 0xbb, 0xfe, 0xae, 0xbb, 0xfe, 0xae, 0xba, 0xfe, 0x96, 0x59, 0xfe, 0x0c, 0x30, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x6d, 0xb6, 0xfe, 0xff, 0xff, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x01, 0x4d, 0x34, 0xfb, 0xa6, 0x9a, 0xfe, 0xa6, 0x9a, 0xfe, 0xa6, 0x9a, 0xfe, 0xa6, 0x9a, 0xfe, 0xa6, 0x7a, 0xfe, 0x34, 0xd3, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x96, 0x59, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x71, 0x16, 0x65, 0x96, 0xfe, 0x9e, 0x79, 0xfe, 0x9e, 0x79, 0xfe, 0x9e, 0x59, 0xfe, 0x96, 0x59, 0xfe, 0x96, 0x59, 0xfe, 0x6d, 0x96, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xbe, 0xfb, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x71, 0x48, 0x75, 0xd7, 0xfe, 0x96, 0x39, 0xfe, 0x8e, 0x39, 0xfe, 0x8e, 0x39, 0xfe, 0x8e, 0x38, 0xfe, 0x8e, 0x38, 0xfe, 0x86, 0x18, 0xfe, 0x14, 0x51, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xe7, 0x9e, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x72, 0xb8, 0x7d, 0xd7, 0xfe, 0x86, 0x18, 0xfe, 0x86, 0x18, 0xfe, 0x86, 0x18, 0xfe, 0x86, 0x18, 0xfe, 0x85, 0xf8, 0xfe, 0x7d, 0xf8, 0xfe, 0x34, 0xb3, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x0c, 0x31, 0xfe, 0xff, 0xff, 0xdd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0xb3, 0xf6, 0x7d, 0xd7, 0xfe, 0x7d, 0xf7, 0xfe, 0x7d, 0xf7, 0xfe, 0x7d, 0xd7, 0xfe, 0x75, 0xd7, 0xfe, 0x75, 0xd7, 0xfe, 0x75, 0xd7, 0xfe, 0x55, 0x35, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x34, 0xd3, 0xfe, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0xd3, 0xfd, 0x75, 0xb7, 0xfe, 0x75, 0xb7, 0xfe, 0x6d, 0xb7, 0xfe, 0x6d, 0xb7, 0xfe, 0x6d, 0xb6, 0xfe, 0x6d, 0xb6, 0xfe, 0x6d, 0xb6, 0xfe, 0x65, 0x76, 0xfe, 0x0c, 0x30, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x55, 0x35, 0xfe, 0xff, 0xff, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x92, 0xfa, 0x65, 0x96, 0xfe, 0x65, 0x96, 0xfe, 0x65, 0x96, 0xfe, 0x65, 0x96, 0xfe, 0x65, 0x96, 0xfe, 0x65, 0x76, 0xfe, 0x5d, 0x76, 0xfe, 0x5d, 0x75, 0xfe, 0x1c, 0x71, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x6d, 0xb6, 0xfe, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x14, 0x51, 0x79, 0x5d, 0x55, 0xfe, 0x5d, 0x75, 0xfe, 0x5d, 0x75, 0xfe, 0x5d, 0x55, 0xfe, 0x55, 0x55, 0xfe, 0x55, 0x55, 0xfe, 0x55, 0x55, 0xfe, 0x55, 0x55, 0xfe, 0x2c, 0xb2, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x8e, 0x38, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x8d, 0xd7, 0x0b, 0x2c, 0xb2, 0xfd, 0x55, 0x35, 0xfe, 0x4d, 0x35, 0xfe, 0x4d, 0x35, 0xfe, 0x4d, 0x34, 0xfe, 0x4d, 0x34, 0xfe, 0x4d, 0x14, 0xfe, 0x4d, 0x14, 0xfe, 0x34, 0xd3, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xf0, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0xef, 0xfe, 0x04, 0x10, 0xfe, 0xa6, 0x9a, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x55, 0x35, 0xfe, 0x34, 0xd3, 0xfe, 0x45, 0x14, 0xfe, 0x45, 0x14, 0xfe, 0x44, 0xf4, 0xfe, 0x44, 0xf4, 0xfe, 0x3c, 0xf4, 0xfe, 0x3c, 0xf3, 0xfe, 0x34, 0xd3, 0xfe, 0x0c, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0xaf, 0xfe, 0x04, 0x10, 0xfe, 0xc7, 0x1c, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x2c, 0xb2, 0xfe, 0x34, 0xd3, 0xfe, 0x3c, 0xd3, 0xfe, 0x34, 0xd3, 0xfe, 0x34, 0xd3, 0xfe, 0x34, 0xd3, 0xfe, 0x34, 0xd3, 0xfe, 0x2c, 0xb2, 0xfe, 0x0c, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xcf, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0xaf, 0xfe, 0x04, 0x10, 0xfe, 0xdf, 0x7e, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x24, 0x92, 0xfe, 0x2c, 0xb2, 0xfe, 0x2c, 0xb2, 0xfe, 0x2c, 0xb2, 0xfe, 0x2c, 0x92, 0xfe, 0x24, 0x92, 0xfe, 0x24, 0x92, 0xfe, 0x0c, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xf0, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0xcf, 0xfe, 0x04, 0x10, 0xfe, 0xff, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x34, 0xd3, 0xfe, 0x1c, 0x71, 0xfe, 0x24, 0x72, 0xfe, 0x1c, 0x72, 0xfe, 0x1c, 0x71, 0xfe, 0x14, 0x51, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xae, 0xfe, 0x03, 0x6e, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0xf0, 0xfe, 0x1c, 0x72, 0xfe, 0xff, 0xff, 0xb9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x5d, 0x76, 0xfe, 0x0c, 0x30, 0xfe, 0x14, 0x51, 0xfe, 0x14, 0x31, 0xfe, 0x0c, 0x30, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0x6e, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0x6d, 0xfe, 0x04, 0x10, 0xfe, 0x45, 0x14, 0xfe, 0xff, 0xff, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xa6, 0x9a, 0xf6, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0x6e, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0xcf, 0xfe, 0x04, 0x10, 0xfe, 0x75, 0xd7, 0xfe, 0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0c, 0x31, 0xfb, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0xaf, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0xbe, 0xfc, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x86, 0x18, 0x27, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xcf, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0x6d, 0xfe, 0x03, 0xef, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x2c, 0xb2, 0xfe, 0xff, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0xb3, 0xfc, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x03, 0xaf, 0xfe, 0x03, 0x4d, 0xfe, 0x03, 0x8e, 0xfe, 0x03, 0xcf, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x14, 0x51, 0xfe, 0xd7, 0x5d, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x72, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x24, 0x92, 0xfe, 0xdf, 0x5d, 0xfe, 0xff, 0xff, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x34, 0xfd, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x04, 0x10, 0xfe, 0x14, 0x31, 0xfe, 0x7d, 0xf8, 0xfe, 0xff, 0xdf, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0x1c, 0x5c, 0x65, 0x96, 0xf9, 0x2c, 0xb2, 0xfe, 0x0c, 0x10, 0xfe, 0x14, 0x51, 0xfe, 0x24, 0x92, 0xfe, 0x5d, 0x55, 0xfe, 0x9e, 0x7a, 0xfc, 0xf7, 0xdf, 0xa8, 0xff, 0xff, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

};

const lv_img_dsc_t img_rain = {

			.data = img_rain_map,
		 .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
		  .header.always_zero = 0,
		  .header.reserved = 0,
		.header.w = 27,
  .header.h = 39,
  .data_size = 1053 * LV_IMG_PX_SIZE_ALPHA_BYTE,
};
