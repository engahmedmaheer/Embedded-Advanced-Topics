/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     NVIC				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "NVIC_Private.h"
#include "STM32F446xx.h"
#include "NVIC_Interface.h"



/**
 * @brief  : Function used For Enable IRQ Peripheral
 * @post
 * @param  : IQR Number
 * @return : LocalErrorStatus
 */
uint8_t NVICEnable (IRQNUM_E IQR )
{
	uint8_t LocalErrorState = OK;
	if(IQR<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ISER[IQR/32],IQR%32);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;

}
/**
 * @brief  : Function used For Disable IRQ Peripheral
 * @post
 * @param  : IQR Number
 * @return : LocalErrorStatus
 */
uint8_t NVICDisable (IRQNUM_E IQR )
{
	uint8_t LocalErrorState = OK;

	if(IQR<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ICER[IQR/32],IQR%32);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;

}
/**
 * @brief  : Function used For Set Pending Flag For Peripheral
 * @post
 * @param  : IQR Number
 * @return : LocalErrorStatus
 */
uint8_t NVIC_SetPendingFlag(IRQNUM_E IQR)
{
	uint8_t LocalErrorState = OK;
	if(IQR<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ISPR[IQR/32],IQR%32);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;


}
/**
 * @brief  : Function used For Clear Pending Flag For Peripheral
 * @post
 * @param  : IQR Number
 * @return : LocalErrorStatus
 */
uint8_t NVIC_ClearPendingFlag(IRQNUM_E IQR)
{
	uint8_t LocalErrorState = OK;

	if(IQR<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ICPR[IQR/32],IQR%32);
	}
	else
	{
		LocalErrorState =NOK;
	}


	return LocalErrorState;
}
/**
 * @brief  : Function used For Get Status Pending Flag For Peripheral
 * @post
 * @param  : IQR Number
 * @param  : Pointer to Active Flag Value
 * @return : LocalErrorStatus | Value Of Flag
 */
uint8_t NVIC_GetActiveFlag(IRQNUM_E IQR , uint8_t* ActiveVal)
{
	uint8_t LocalErrorState = OK;

	if (IQR< MAX_IRQ && ActiveVal != NULL)
	{
	*ActiveVal=GET_BIT(NVIC->NVIC_IPR[IQR/32],IQR%32);
	}
	else
	{
		LocalErrorState = NOK ;
	}
	return LocalErrorState;

}

