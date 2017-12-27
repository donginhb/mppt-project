/*
 * HD44780.h
 *
 *  Created on: Mar 30, 2017
 *      Author: Dell User
 */

#ifndef HD44780_H_
#define HD44780_H_

#include "stm32f4xx_hal.h"

#define HD44780_CommandMode		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
#define HD44780_DataMode		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
#define HD44780_SetEnable		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
#define HD44780_ClearEnable		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
#define HD44780_SetRW			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
#define HD44780_ClearRW			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);


//HD44890 Basic Commands and Mask Bits
#define CLEAR_DISPLAY				0x01

#define CURSOR_HOME					0x02

#define ENTRY_MODE_SET				0x04
#define SET_CURSOR_INC				0x02
#define SET_CURSOR_DEC				0x00
#define SET_DISPLAY_BLINK			0x01
#define SET_DISPLAY_NOBLINK			0x00

#define DISPLAY_ON_OFF_CONTROL		0x08
#define SET_DISPLAY_ON				0x04
#define SET_DISPLAY_OFF				0x00
#define SET_CURSOR_ON				0x02
#define SET_CURSOR_OFF				0x00
#define SET_CURSOR_BLINK			0x01
#define SET_CURSOR_NOBLINK			0x00

#define CURSOR_DISPLAY_SHIFT		0x10
#define SET_DISPLAY_SHIFT			0x08
#define SET_CURSOR_SHIFT			0x00
#define SET_SHIFT_DIRECTION_RIGHT	0x04
#define SET_SHIFT_DIRECTION_LEFT	0x00

#define FUNCTION_SET				0x20
#define SET_DATA_LENGTH_8			0x10
#define SET_DATA_LENGTH_4			0x00
#define SET_2LINE					0x08
#define SET_1LINE					0x00
#define	SET_DISPLAY_FONT_5_10		0x04
#define	SET_DISPLAY_FONT_5_8		0x00

#define SET_CGRAM_ADDRESS			0x40

#define SET_DDRAM_ADDRESS			0x80

#endif /* HD44780_H_ */
