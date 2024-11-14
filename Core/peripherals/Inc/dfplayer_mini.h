/*
 * DFPLAYER_MINI.h
 *
 *  Created on: May 16, 2020
 *      Author: controllerstech
 */

#ifndef INC_DFPLAYER_MINI_H_
#define INC_DFPLAYER_MINI_H_


void Send_cmd (uint8_t cmd, uint8_t Parameter1, uint8_t Parameter2);
void DF_PlayFromStart(void);
void DF_PlayStartSound();
void DF_PlaySound(uint8_t number);
void DF_Init (uint8_t volume);
void DF_Next (void);
void DF_Pause (void);
void DF_Previous (void);
void DF_Playback (void);
void DFPlayer_setVolume(uint8_t volume);
void DFPlayer_playFolder(uint8_t folder, uint8_t track);
void DFPlayer_playFolder_(uint8_t folder, uint8_t track);
void say_time_now(uint8_t minutes, uint8_t hours);
#define DFPLAYER_UART_FRAME_SIZE      0x0A //total number of bytes in UART packet, same for cmd & feedback
#define DFPLAYER_UART_START_BYTE      0x7E //start byte
#define DFPLAYER_UART_VERSION         0xFF //protocol version
#define DFPLAYER_UART_DATA_LEN        0x06 //number of data bytes, except start byte, checksum & end byte
#define DFPLAYER_UART_END_BYTE        0xEF //end byte

/* command controls */
#define DFPLAYER_PLAY_NEXT            0x01 //play next uploaded file
#define DFPLAYER_PLAY_PREV            0x02 //play prev uploaded file
#define DFPLAYER_PLAY_TRACK           0x03 //play tracks in chronological order, by upload time
#define DFPLAYER_SET_VOL_UP           0x04 //increment volume by 1
#define DFPLAYER_SET_VOL_DOWN         0x05 //decrement volume by 1
#define DFPLAYER_SET_VOL              0x06 //set volume, range 0..30
#define DFPLAYER_SET_EQ               0x07 //0=Off, 1=Pop, 2=Rock, 3=Jazz, 4=Classic, 5=Bass (may not be supported by some modules)
#define DFPLAYER_LOOP_TRACK           0x08 //playing & looping track number 0001..9999
#define DFPLAYER_SET_PLAY_SRC         0x09 //1=USB-Disk, 2=TF-Card, 3=Aux, 4=sleep(YX5200)/NOR-Flash(GD3200), 5=NOR-Flash, 6=Sleep (3..6 may not be supported by some modules)
#define DFPLAYER_SET_STANDBY_MODE     0x0A //put player in standby mode, not the same as sleep mode
#define DFPLAYER_SET_NORMAL_MODE      0x0B //pull player out of standby mode (may not be supported by some modules)
#define DFPLAYER_RESET                0x0C //reset module, set all settings to factory default
#define DFPLAYER_RESUME_PLAYBACK      0x0D //resume playing current track
#define DFPLAYER_PAUSE                0x0E //pause playing current track
#define DFPLAYER_PLAY_FOLDER          0x0F //play track number 1..255 from folder number 1..99
#define DFPLAYER_SET_DAC_GAIN         0x10 //set DAC output gain/output voltage swing (may not be supported by some modules)
#define DFPLAYER_REPEAT_ALL           0x11 //repeat playback all files in chronological order
#define DFPLAYER_PLAY_MP3_FOLDER      0x12 //play track number 0001..9999 from "mp3" folder
#define DFPLAYER_PLAY_ADVERT_FOLDER   0x13 //interrupt current track & play track number 0001..9999 from "advert" folder, than resume current track
#define DFPLAYER_PLAY_3000_FOLDER     0x14 //play track number 0001..3000 from folder that supports 3000 tracks (may not be supported by some modules)
#define DFPLAYER_STOP_ADVERT_FOLDER   0x15 //stop interrupting current track while playing track from "advert" folder
#define DFPLAYER_STOP_PLAYBACK        0x16 //stop playing current track
#define DFPLAYER_REPEAT_FOLDER        0x17 //repeat playback folder number 01..99
#define DFPLAYER_RANDOM_ALL_FILES     0x18 //play all tracks in random order
#define DFPLAYER_LOOP_CURRENT_TRACK   0x19 //loop currently played track
#define DFPLAYER_SET_DAC              0x1A //enable/disable DAC (mute/unmute), 0=enable, 1=disable
#define DFPLAYER_PLAY_ADVERT_FOLDER_N 0x25 //interrupt current track & play track number 001..255 from "advert1".."advert9" folder, than resume current track (may not be supported by some modules)

/* request command controls */
#define DFPLAYER_GET_STATUS           0x42 //get current stutus, see NOTE
#define DFPLAYER_GET_VOL              0x43 //get current volume, range 0..30
#define DFPLAYER_GET_EQ               0x44 //get current EQ, 0=Off, 1=Pop, 2=Rock, 3=Jazz, 4=Classic, 5=Bass (may not be supported by some modules)
#define DFPLAYER_GET_PLAY_MODE        0x45 //get current loop mode, 0=loop all, 1=loop folder, 2=loop track, 3=random, 4=disable (may not be supported by some modules)
#define DFPLAYER_GET_VERSION          0x46 //get software version
#define DFPLAYER_GET_QNT_USB_FILES    0x47 //get total number of tracks on USB-Disk
#define DFPLAYER_GET_QNT_TF_FILES     0x48 //get total number of tracks on TF-card
#define DFPLAYER_GET_QNT_FLASH_FILES  0x49 //get total number of tracks on NOR-Flash (may not be supported by some modules)
#define DFPLAYER_GET_USB_TRACK        0x4B //get currently playing track number on USB-Disk
#define DFPLAYER_GET_TF_TRACK         0x4C //get currently playing track number on TF-card
#define DFPLAYER_GET_FLASH_TRACK      0x4D //get currently playing track number on NOR-Flash (may not be supported by some modules)
#define DFPLAYER_GET_QNT_FOLDER_FILES 0x4E //get total number of tracks in folder
#define DFPLAYER_GET_QNT_FOLDERS      0x4F //get total number of folders in current source (may not be supported by some modules)

/* module returned codes at the end of any playback operation or if any command error, located in 4-th RX byte */
#define DFPLAYER_RETURN_CODE_OK_ACK   0x41 //OK, command is accepted (returned only if ACK/feedback byte is set to 0x01)
#define DFPLAYER_RETURN_ERROR         0x40 //error, module return this status automatically if command is not accepted (details located in 7-th RX byte)
#define DFPLAYER_RETURN_CODE_DONE     0x3D //track playback is is completed, module return this status automatically after the track has been played
#define DFPLAYER_RETURN_CODE_READY    0x3F //ready after boot or reset, module return this status automatically after boot or reset

/* misc */
#define DFPLAYER_BOOT_DELAY           3000 //average player boot time 1500sec..3000msec, depends on SD-card size
#endif /* INC_DFPLAYER_MINI_H_ */
