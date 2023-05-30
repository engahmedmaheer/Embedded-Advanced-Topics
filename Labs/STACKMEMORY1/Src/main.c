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

/*************************HOW TO ACCESS SP WITH PSP*************************************/


#include <stdint.h>
/*Test Code */
int ADD(int a , int b , int c , int d);
/* DEFINE LOCATIONS OF SATCK*/

#define RAM_START      	(0x20000000U)
#define RAM_SIZE		   (128*1024)
#define RAM_END			   (RAM_START+RAM_SIZE)
#define STACK_START		   RAM_END

#define STACK_MSP_START	   (RAMEND -1024)
#define STACK_MSP_END      (STACK_MSP_START +512)
#define STACK_PSP_START		STACK_MSP_END
#define STACK_PSP_END		RAM_END

void GenerateException()
{

}
void SVC_Handler()
{
	/*in Handler*/
	/*Break Point*/
}
void Changepsp (void);

int main(void)
{

	Changepsp();
	int Result ;
	Result=ADD(1,2,3,4);

	GenerateException();

    /* Loop forever */
	for(;;);
}

int ADD(int a , int b , int c , int d)
{
	return a+b+c+d ;
}
__attribute__((naked)) void Changepsp (void)
{

//	uint32_t SPVal = 0x02 ;

		__asm volatile (".equ RAM_END , (0x20000000U + (128*1024) )");
		__asm volatile (".equ PSP_END , (RAM_END - 512 )");
		/*1.INITILAZE PSP With valid stack pointer value */
		__asm volatile ("LDR R0 , =PSP_END");
		__asm volatile ("MSR PSP , R0");
		/*2. Link SP with PSP*/
		__asm volatile ("LDR R0, =#2");
		__asm volatile ("MSR CONTROL , R0") ;

		__asm volatile ("bx LR");

}