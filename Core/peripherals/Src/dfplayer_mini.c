/**************************************************************************/
/*
 playMP3Folder()

 Play specific track number from "mp3" folder

 NOTE:
 - folder name must be "mp3" or "MP3"
 - up to 0001..9999 songs in each folder

 - files in folder must start with 4 decimal digits with leading zeros
 - example: SD_ROOT/mp3/0001 - My favorite song.mp3
 - module speed will decrease as the folder gets bigger, place no more
 than 3000 tracks to keep the speed
 */
/**************************************************************************/
#include "stm32f4xx_hal.h"
#include "../Inc/dfplayer_mini.h"


#define DF_UART &huart3
#define DF_UART_HAL huart3


extern UART_HandleTypeDef DF_UART_HAL;


#define Source      0x02  // TF CARD

/*************************************** NO CHANGES AFTER THIS *************************************************/
/*
 SOUND FILES
 1-3 wind    10 - battery_charge 13 - modem    16 - standby
 4-6 rain    11 - bip            14 - welcome
 7 snow      12 - warning        15 - disp on
 pesenki 50-59
 */

//SOUND FILES
# define Start_Byte 0x7E
# define End_Byte   0xEF
# define Version    0xFF
# define Cmd_Len    0x06
# define Feedback   0x00    //If need for Feedback: 0x01,  No Feedback: 0
# define Standby    0x0A


void Send_cmd(uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2) {
	uint16_t Checksum = Version + Cmd_Len + cmd + Feedback + Parameter1
			+ Parameter2;
	Checksum = 0 - Checksum;

	uint8_t CmdSequence[10] = { Start_Byte, Version, Cmd_Len, cmd, Feedback,
			Parameter1, Parameter2, (Checksum >> 8) & 0x00ff,
			(Checksum & 0x00ff), End_Byte };

	HAL_UART_Transmit(DF_UART, (uint8_t*) CmdSequence, 10, HAL_MAX_DELAY);
	HAL_Delay(200);
}

void DF_Standby(void) {
	//Send_cmd(Standby, 0x00);

}
void DF_PlayFromStart(void) {
	Send_cmd(0x03, 0x00, 0x01);

}

void DF_PlayStartSound() {
	Send_cmd(0x03, 0x00, 0x06);

}

void DF_Init(uint8_t volume) {
	Send_cmd(0x3F, 0x00, Source);
	Send_cmd(0x06, 0x00, volume);
	HAL_Delay(500);
	//ILI9486_string(10, 10, "initialisation dfplayer", COLOR_WHITE,
	//COLOR_BLACK);
}

void DF_Next(void) {
	Send_cmd(0x01, 0x00, 0x00);
}

void DF_Pause(void) {
	Send_cmd(0x0E, 0, 0);
}

void DF_Previous(void) {
	Send_cmd(0x02, 0, 0);
}

void DF_Playback(void) {
	Send_cmd(0x0D, 0, 0);
}

/**************************************************************************/
/*
 playFolder()

 Play specific track from specific folder

 NOTE:
 - folder name must be 01..99
 - up to 001..255 songs in each folder

 - files in folder must start with 3 decimal digits with leading zeros
 - example: SD_ROOT/01/001 - My favorite song.mp3
 */
/**************************************************************************/
void DFPlayer_playFolder_(uint8_t folder, uint8_t track) {
		Send_cmd(DFPLAYER_PLAY_FOLDER, folder, track);
}
void DFPlayer_playFolder(uint8_t folder, uint8_t track) {
	 //folder limit 1..99
	//track  limit 1..255
	Send_cmd(DFPLAYER_PLAY_FOLDER, folder, track);

}
void say_time_now(uint8_t minutes, uint8_t hours) {

	uint8_t ten_min, one_min, ten_hour, one_hour;  //34 min //12 hour
	one_min = minutes % 10; // 4 min
	ten_min = minutes / 10; // 3 min

	one_hour = hours % 10; // 1 hour
	ten_hour = hours / 10; // 2 hour
	DFPlayer_playFolder_(2, 5); //time is
	HAL_Delay(800);
	if (hours < 10) {
		DFPlayer_playFolder_(3, one_hour);
	} else if (hours == 10) {
		DFPlayer_playFolder_(3, 10);
	} else if (hours > 10 && hours < 20) {
		DFPlayer_playFolder_(3, 10 + one_hour);
	} else if (hours == 20) {
		DFPlayer_playFolder_(3, 20);
	} else if (hours > 20) {
		DFPlayer_playFolder_(3, ten_hour * 10);
		HAL_Delay(1200);
		DFPlayer_playFolder_(3, one_hour);
	}
	HAL_Delay(1000);
	DFPlayer_playFolder_(2, 19); //hours
	HAL_Delay(1000);
	if (minutes < 10) {
		DFPlayer_playFolder_(3, one_min);
	} else if (minutes == 10) {
		DFPlayer_playFolder_(3, 10);
	} else if (minutes > 10 && minutes < 20) {
		DFPlayer_playFolder_(3, 10+one_min);

	} else if (minutes == 20) {
		DFPlayer_playFolder_(3, 20);
	} else if (minutes > 20) {
		if (minutes == 30 || minutes == 40 || minutes == 50) {
			DFPlayer_playFolder_(3, ten_min * 10);
		} else {
			DFPlayer_playFolder_(3, ten_min * 10);
			HAL_Delay(1200);
			DFPlayer_playFolder_(3, one_min);
		}
	}
	HAL_Delay(1000);
	DFPlayer_playFolder_(2, 18); //minuts
	HAL_Delay(2000);

}
void DFPlayer_setVolume(uint8_t volume)
{
  //volume = constrain(volume, 0, 30); //volume limit 0..30

  Send_cmd(DFPLAYER_SET_VOL, 0, volume);
}
void DFPlayer_volumeUp()
{
	Send_cmd(DFPLAYER_SET_VOL_UP, 0, 0);
}


/************************************************************************************/
/*
    volumeDown()

    Decrement volume by 1
*/
/************************************************************************************/
void DFPlayer_volumeDown()
{
	Send_cmd(DFPLAYER_SET_VOL_DOWN, 0, 0);
}
void DFPlayer_reset()
{
	Send_cmd(DFPLAYER_RESET, 0, 0);

  HAL_Delay(DFPLAYER_BOOT_DELAY); //wait for player to boot
}
