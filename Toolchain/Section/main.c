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

#include "STM32F446xx.h"
#include "ERR_TYPE.h"
#include "BIT_MATH.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void main(void)
{
	ENABLE_GPIO1_CLCK();

	GPIO_PinConfig_S LEDPIN =
	{
			.PortNum=PORTA,
			.PinNumber=PIN5,
			.Mode=GPIO_OUTPUT,
			.OPType=GPIO_PUSHPULL,
			.Speed=GPIO_LOWSPEED,
			.PULLType=GPIO_NOPULL,
	};
	GPIO_u8PinInit(&LEDPIN);

while(1)
{
	GPIO_u8SetPinValue(PORTA, PIN5, GPIO_PINHIGH);

	GPIO_u8SetPinValue(PORTA, PIN5, GPIO_PINLOW);
}
	/* Loop forever */
	for(;;);

}
