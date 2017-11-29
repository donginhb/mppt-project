/*
 * mppt.h
 *
 *  Created on: Apr 3, 2017
 *      Author: nipri
 */

#ifndef MPPT_H_
#define MPPT_H_

// voltage related constants
#define HALF_VOLT      		0x3e	// counts corresponding to 0.5 V
#define TWO_VOLT       		0xf6	// counts corresponding to 2.0 Volts
#define ONE_AND_HALF_VOLT 	0xb9	// counts corresponding to 1.5 Volts
#define LOW_BATTERY2   		0x53e	// counts corresponding to 10.9 Volts
#define LOW_BATTERY1   		0x54a	// counts corresponding to 11.0 Volts
#define LOAD_ON1       		0x5c5	// counts corresponding to 12 Volts
#define LOAD_ON2       		0x75c	// counts corresponding to 15.3 Volts
#define LOAD_OFF1      		0x525	// counts corresponding to 10.7 Volts
#define LOAD_OFF2      		0x774	// counts corresponding to 15.5 Volts
#define MAX_START_VOLT 		0x640	// counts corresponding to 13.0 Volts

// Threshold voltage calculations
#define TV_0          0x718	// thresh. volt count at  0C (14.75V)
#define TV_40         0x66b	// thresh. volt count at 40C (13.35V)

//the two rates given below are in counts, and are 10 times larger than actual.
#define RATE1            434	// TV rate between 0C and 40C (-35 mV/degree)
#define RATE2            124	// TV rate above 40C (-10 mV/degree)

#define TEMP_0        0xd3d	// count corrensponding to 0 C
#define TEMP_40	      0xf2b	// count corrensponding to 40 C

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void HD44780_Init(void);
void HD44780_WriteData(uint8_t row, uint8_t col, char *data);
void HD44780_WriteCommand(uint8_t);
void HD44780_GotoXY(uint8_t, uint8_t);
static void getADCreadings(uint8_t);

char *rx;
uint8_t myChar;
char inBuffer[16];
uint8_t charCount;

#endif /* MPPT_H_ */
