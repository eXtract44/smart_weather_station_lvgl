#include "../Core/peripherals/Inc/ili9486.h"

#include "../Core/lvgl/lvgl.h"
#include "../Core/peripherals/Inc/adc.h"


static uint8_t rotationNum = 1;


//-------------------------------------------------------------------
void ILI9486_SendCommand(uint8_t com) {
	*(__IO uint8_t*) (0x60000000) = com;
}
//-------------------------------------------------------------------
void ILI9486_SendData(uint8_t data) {
	*(__IO uint8_t*) (0x60040000) = data;
}
//-------------------------------------------------------------------
void ILI9486_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2,
		uint16_t y2) {

	ILI9486_SendCommand(ILI9486_COLUMN_ADDR);
	ILI9486_SendData(x1 >> 8);
	ILI9486_SendData(x1 & 0xFF);
	ILI9486_SendData(x2 >> 8);
	ILI9486_SendData(x2 & 0xFF);

	ILI9486_SendCommand(ILI9486_PAGE_ADDR);
	ILI9486_SendData(y1 >> 8);
	ILI9486_SendData(y1 & 0xFF);
	ILI9486_SendData(y2 >> 8);
	ILI9486_SendData(y2 & 0xFF);
	ILI9486_SendCommand(ILI9486_GRAM);
}
void pushColors(uint16_t *data, int16_t len, bool first)
{
  uint16_t color;
  uint8_t  hi, lo;
  if(first == true)
  { // Issue GRAM write command only on first call
	  ILI9486_SendCommand(0x2C);
  }
  while(len--)
  {
    color = *data++;

    hi    = color >> 8; // Don't simplify or merge these
    lo    = color;      // lines, there's macro shenanigans
    ILI9486_SendData(lo);
    ILI9486_SendData(hi);
  }
}

//-------------------------------------------------------------------
void ILI9486_Init(void) {

	RESET_ACTIVE;
	HAL_Delay(10);
	RESET_IDLE;
	HAL_Delay(100);

	//  Interface Mode Control
	ILI9486_SendCommand(ILI9486_RGB_INTERFACE);
	ILI9486_SendData(0x00);

	// Interface Pixel Format, 16 bits / pixel
	ILI9486_SendCommand(ILI9486_PIXEL_FORMAT);
	ILI9486_SendData(0x55); // 5D

	// PGAMCTRL(Positive Gamma Control)
	ILI9486_SendCommand(ILI9486_PGAMMA);
	ILI9486_SendData(0x0F);
	ILI9486_SendData(0x1F);
	ILI9486_SendData(0x1C);
	ILI9486_SendData(0x0C);
	ILI9486_SendData(0x0F);
	ILI9486_SendData(0x08);
	ILI9486_SendData(0x48);
	ILI9486_SendData(0x98);
	ILI9486_SendData(0x37);
	ILI9486_SendData(0x0A);
	ILI9486_SendData(0x13);
	ILI9486_SendData(0x04);
	ILI9486_SendData(0x11);
	ILI9486_SendData(0x0D);
	ILI9486_SendData(0x00);
	// NGAMCTRL (Negative Gamma Correction)
	ILI9486_SendCommand(ILI9486_NGAMMA);
	ILI9486_SendData(0x0F);
	ILI9486_SendData(0x32);
	ILI9486_SendData(0x2E);
	ILI9486_SendData(0x0B);
	ILI9486_SendData(0x0D);
	ILI9486_SendData(0x05);
	ILI9486_SendData(0x47);
	ILI9486_SendData(0x75);
	ILI9486_SendData(0x37);
	ILI9486_SendData(0x06);
	ILI9486_SendData(0x10);
	ILI9486_SendData(0x03);
	ILI9486_SendData(0x24);
	ILI9486_SendData(0x20);
	ILI9486_SendData(0x00);
	// Digital Gamma Control 1
	ILI9486_SendCommand(0xE2);
	ILI9486_SendData(0x0F);
	ILI9486_SendData(0x32);
	ILI9486_SendData(0x2E);
	ILI9486_SendData(0x0B);
	ILI9486_SendData(0x0D);
	ILI9486_SendData(0x05);
	ILI9486_SendData(0x47);
	ILI9486_SendData(0x75);
	ILI9486_SendData(0x37);
	ILI9486_SendData(0x06);
	ILI9486_SendData(0x10);
	ILI9486_SendData(0x03);
	ILI9486_SendData(0x24);
	ILI9486_SendData(0x20);
	ILI9486_SendData(0x00);
	ILI9486_setRotation(0);
	// Idle mode control + Power +  Frame rate ctrl
	ILI9486_SendCommand(0x38);
	// frame rate ctrl
	ILI9486_SendCommand(0xB1);
	// Frame rate(Hz) (default: 70kHz) /-/ Division Ratio (default: fosc)
	ILI9486_SendData(0xB0);
	// Clock per Line (default: 17 clk cycles)
	ILI9486_SendData(0x11);
	// Power Control 3 (For Normal Mode)
	ILI9486_SendCommand(0xC2);
	ILI9486_SendData(0x55); // 44
	// Display Inversion Control
	ILI9486_SendCommand(0xB4);
	ILI9486_SendData(0x02); // 2 dot invercion /-/ disabled | 0x12 to enable
	// Display Function Control
	ILI9486_SendCommand(ILI9486_DFC); //0xB6

	ILI9486_SendData(0x02); //1 para
	ILI9486_SendData(0x02); //2 para old x22
	ILI9486_SendData(0x3B); //3 para

	//ILI9486_SendData(0x0a); //1 para
	// ILI9486_SendData(0x82); //2 para
	//ILI9486_SendData(0x27); //3 para

	//ILI9486_SendData(0x00); //4 para&

	ILI9486_SendCommand(ILI9486_COLUMN_ADDR);
	ILI9486_SendData(0x00);
	ILI9486_SendData(0x00);
	ILI9486_SendData(0x00);
	ILI9486_SendData(0xEF);

	ILI9486_SendCommand(ILI9486_PAGE_ADDR);
	ILI9486_SendData(0x00);
	ILI9486_SendData(0x00);
	ILI9486_SendData(0x01);
	ILI9486_SendData(0x3F);
	ILI9486_SendCommand(ILI9486_GRAM);
	//HAL_Delay(150);
	// # Sleep OUT
	ILI9486_SendCommand(0x11);
	// Display ON
	ILI9486_SendCommand(0x29);
	//HAL_Delay(200);
	ILI9486_setRotation(2);
	ILI9486_fill(COLOR_BLACK);
}
//-------------------------------------------------------------------
void ILI9486_drawPixel(uint16_t x, uint16_t y, uint16_t color) {
	ILI9486_SetCursorPosition(x, y, x, y);
	ILI9486_SendData(color >> 8);
	ILI9486_SendData(color & 0xFF);
}

//-------------------------------------------------------------------
void ILI9486_setRotation(uint8_t rotate) {
	switch (rotate) {
	case 1:
		rotationNum = 1;
		ILI9486_SendCommand(ILI9486_MEMCONTROL);
		ILI9486_SendData(ILI9486_MADCTL_MY | ILI9486_MADCTL_BGR);
		break;
	case 2:
		rotationNum = 2;
		ILI9486_SendCommand(ILI9486_MEMCONTROL);
		ILI9486_SendData(ILI9486_MADCTL_MV | ILI9486_MADCTL_BGR);
		break;
	case 3:
		rotationNum = 3;
		ILI9486_SendCommand(ILI9486_MEMCONTROL);
		ILI9486_SendData(ILI9486_MADCTL_MX | ILI9486_MADCTL_BGR);
		break;
	case 4:
		rotationNum = 4;
		ILI9486_SendCommand(ILI9486_MEMCONTROL);
		ILI9486_SendData(
				ILI9486_MADCTL_MX | ILI9486_MADCTL_MY | ILI9486_MADCTL_MV
						| ILI9486_MADCTL_BGR);
		break;
	default:
		rotationNum = 1;
		ILI9486_SendCommand(ILI9486_MEMCONTROL);
		ILI9486_SendData(ILI9486_MADCTL_MY | ILI9486_MADCTL_BGR);
		break;
	}
}
void ILI9486_fill(uint16_t color) {
	uint32_t n = ILI9486_PIXEL_COUNT;

	if (rotationNum == 1 || rotationNum == 3) {
		ILI9486_SetCursorPosition(0, 0, ILI9486_WIDTH - 1, ILI9486_HEIGHT - 1);
	} else if (rotationNum == 2 || rotationNum == 4) {
		ILI9486_SetCursorPosition(0, 0, ILI9486_HEIGHT - 1, ILI9486_WIDTH - 1);
	}

	while (n) {
		n--;
		ILI9486_SendData(color >> 8);
		ILI9486_SendData(color & 0xff);
	}
}
