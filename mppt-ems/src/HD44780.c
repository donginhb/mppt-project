/*
 * HD44780.c
 * Contains functions to initialize and  control an
 * HD44780 based LCD display in 4 bit mode.
 *
 * Target Processor: ST Microelectronics STM32F4xx series
 * ST Firmware Revision: STM32Cube FW_F4 V1.13.1
 *
 *
 *  Created on: Mar 30, 2017
 *      v 1.0:  Nicholas C ipri
 *
 */
#include "HD44780.h"
#include "stm32f4xx_hal.h"
#include "mppt.h"

#include <string.h>

void HD44780_WriteCommand(uint8_t data) {

	HD44780_CommandMode;
	HD44780_ClearRW;

	if ( (data==0x03) || (data== 0x02) )  { // Used only for initialization

		if ( (data&0x08) == 0x08 )
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

		if ( (data&0x04) == 0x04)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

		if ( (data&0x02) == 0x02)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

		if ( (data&0x01) == 0x01)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		HD44780_SetEnable;
		HAL_Delay(1);
		HD44780_ClearEnable;
	}

	else {

		if ( (data&0x80) == 0x80 )
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

		if ( (data&0x40) == 0x40)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

		if ( (data&0x20) == 0x20)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

		if ( (data&0x10) == 0x10)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		HD44780_SetEnable;
		HAL_Delay(1);
		HD44780_ClearEnable;


		if ( (data&0x08) == 0x08 )
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

		if ( (data&0x04) == 0x04)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

		if ( (data&0x02) == 0x02)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

		if ( (data&0x01) == 0x01)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		HD44780_SetEnable;
		HAL_Delay(1);
		HD44780_ClearEnable;
	}
}

void HD44780_WriteData(uint8_t row, uint8_t col, char *data) {

	uint8_t length;
	uint8_t i;

	HD44780_ClearRW;

	HD44780_CommandMode;
	HD44780_GotoXY(row, col);

	HD44780_DataMode;

	length = strlen(data);
	for(i=0; i<length; i++) {

		if ( (*data & 0x80) == 0x80 )
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

		if ( (*data & 0x40) == 0x40)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

		if ( (*data & 0x20) == 0x20)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

		if ( (*data & 0x10) == 0x10)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		HD44780_SetEnable;
		HAL_Delay(1);
		HD44780_ClearEnable;

		if ( (*data & 0x08) == 0x08 )
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);

		if ( (*data & 0x04) == 0x04)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

		if ( (*data & 0x02) == 0x02)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

		if ( (*data & 0x01) == 0x01)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

		HD44780_SetEnable;
		HAL_Delay(1);
		HD44780_ClearEnable;

		data++;
	}
}

void HD44780_GotoXY(uint8_t row, uint8_t col) {

	uint8_t row_offsets[] = {0x00, 0x40};
	HD44780_WriteCommand(SET_DDRAM_ADDRESS | (col + row_offsets[row]));
}

void HD44780_Init() {

	HD44780_WriteCommand(0x03);
	HAL_Delay(10);
	HD44780_WriteCommand(0x03);
	HAL_Delay(10);
	HD44780_WriteCommand(0x03);
	HAL_Delay(10);
	HD44780_WriteCommand(0x02);
	HAL_Delay(10);

	HD44780_WriteCommand(FUNCTION_SET | SET_2LINE);
	HAL_Delay(10);
	HD44780_WriteCommand(DISPLAY_ON_OFF_CONTROL | SET_DISPLAY_ON | SET_CURSOR_ON);
	HAL_Delay(10);

	HD44780_WriteCommand(CLEAR_DISPLAY);
	HAL_Delay(10);

	HD44780_WriteCommand(ENTRY_MODE_SET | SET_CURSOR_INC);
	HAL_Delay(10);

}




