/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

int main(void)
{
	uint32_t *clock_control_enable, *gpiod_mode_register, *gpiod_output_data_register;
	clock_control_enable = (uint32_t*)0x40023830;
	gpiod_mode_register = (uint32_t*)0x40020C00;
	gpiod_output_data_register = (uint32_t*)0x40020C14;

	// Enable the clock for the GPIOD peripheral in the AHB1ENR.
	// SETS the 3rd bit position to 1.
	*clock_control_enable |= (0x1<<3);

	// Configure the mode of the IO pin as output.
	// CLEARS the 24th and 25th bit positions.
	*gpiod_mode_register &= ~(0x3<<24);

	// SET the 24th bit position to 1.
	*gpiod_mode_register |= (0x1<<24);

	// SETS the output of the data register for the GPIOD pin to be HIGH.
	*gpiod_output_data_register |= 0x1<<12;

    /* Loop forever */
	for(;;);
}
