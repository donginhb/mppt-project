                                                                                                                                                                                                                    /** mppt.c
 * Top level header file for MPPT EMS (STI assembly number 781-124-033 rev. 0)
 *
 * (c) 2018 Solar Technology Inc.
 * 7620 Cetronia Road
 * Allentown PA, 18106
 * 610-391-8600
 *
 * This code is for the exclusive use of Solar Technology Inc.
 * and cannot be used in its present or any other modified form
 * without prior written authorization.
 *
 * HOST PROCESSOR: STM32F410RBT6
 * Developed using STM32CubeF4 HAL and API version 1.18.0
 *
 *
 *
 * REVISION HISTORY
 *
 * 1.0: 12/27/2017	Created By Nicholas C. Ipri (NCI) nipri@solartechnology.com
 *
 */
#ifndef MPPT_H_
#define MPPT_H_

// voltage related constants
// The ones that are commented out are not used in rev 4.3
#define HALF_VOLT      		0x4d	// 77 counts corresponding to 0.5 V
#define TWO_VOLT       		0x135	// 232 counts corresponding to 2.0 Volts
//#define ONE_AND_HALF_VOLT 	0xe8	// 369 counts corresponding to 1.5 Volts
#define LOW_BATTERY2   		0x695	// 1685 counts corresponding to 10.9 Volts
//#define LOW_BATTERY1   		0x6a5	// 1701 counts corresponding to 11.0 Volts
#define V_MIN_LOAD_ON       0x740	// 1856 counts corresponding to 12 Volts
#define V_MAX_LOAD_ON       0x93e	// 2366 counts corresponding to 15.3 Volts
#define V_MIN_LOAD_OFF 		0x677	// 1655 counts corresponding to 10.7 Volts
#define V_MAX_LOAD_OFF 		0x95d	// 2397 counts corresponding to 15.5 Volts
#define MAX_START_VOLT 		0x7da	// 2010 counts corresponding to 13.0 Volts

// Threshold voltage calculations
#define TV_0        		0xe30	// 3632 thresh. volt count at  0C (14.75V)
#define TV_40      			0xcd7	// 3287 thresh. volt count at 40C (13.35V)

//the two rates given below are in counts, and are 10 times larger than actual.
#define RATE1       		434		// TV rate between 0C and 40C (-35 mV/degree)
#define RATE2       		124		// TV rate above 40C (-10 mV/degree)

#define TEMP_0      		0xd3c	// 3388 count corrensponding to 0 C
#define TEMP_40	    		0xf2c	// 3884 count corrensponding to 40 C

/* This is the MOSFET temperatures at which the fan is switched on or off. Change as necessary */
#define FAN_ON_TEMP			0xfaa 	// 4010 counts for 50 C / 122 deg F
#define FAN_OFF_TEMP		0xf15	// 3861 counts for 38 C / 100.4 deg F

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void HD44780_Init(void);
//void HD44780_WriteData(uint8_t row, uint8_t col, char *data);
void HD44780_WriteData(uint8_t, uint8_t, char *, uint8_t);
void HD44780_WriteCommand(uint8_t);
void HD44780_GotoXY(uint8_t, uint8_t);

static double vBat, iBat, vSolar, iSolar, loadVoltage, ambientTemp, mosfetTemp, loadCurrent;

char *rx;
uint8_t myChar;
char inBuffer[16];
uint8_t charCount;
uint32_t usCounter;


//double vBat, iBat, vSolar, iSolar, loadVoltage, loadCurrent, ambientTemp, mosfetTemp;

#endif /* MPPT_H_ */
