/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     GPIO				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/



#include <stdint.h>
#include "ERR_TYPE.h"
#include "BIT_MATH.h"

#include "STM32F446xx.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


					/*For peripheral Only*/
static GPIO_REG_S* GPIOPORT[GPIO_PERIPHERAL_NUM] ={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};

/******************************************************************************
 * @func :  GPIO_u8PinInit
 *
 * Description:	the function initialize the required pin configuration  options
 *
 * Parameters:
 * @par[in]: 1- PinConfig: const pointer to GPIO_PinConfig_S structure which holds the configurations
 *
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_S* PinConfig)
{
	uint8_t LocalErrorStatue=OK ;
	if (PinConfig != NULL)
	{
		if (PinConfig->PortNum < INVALIED_PORT && PinConfig->PinNumber < INVALIED_PIN )
		{
			/*SELECT GPIO MODE GPIO_INPUT,GPIO_OUTPUT,GPIO_AF,GPIO_ANALOG*/
			(GPIOPORT[PinConfig->PortNum]->MODER.Reg) &=~((MODER_MASK)<<( PinConfig->PinNumber * MODER_PIN_ACESS_BITS));
			(GPIOPORT[PinConfig->PortNum]->MODER.Reg) |= ((PinConfig->Mode)<<( PinConfig->PinNumber* MODER_PIN_ACESS_BITS)) ;

			/*Select GPIO Pull State Pull UP , DOWN , NO PULL  */
			(GPIOPORT[PinConfig->PortNum]->PUPDR.Reg) &=~((PUPDR_MASK)<<( PinConfig->PinNumber * PUPDR_PIN_ACESS_BITS));
			(GPIOPORT[PinConfig->PortNum]->PUPDR.Reg) |= ((PinConfig->PULLType)<<( PinConfig->PinNumber * PUPDR_PIN_ACESS_BITS)) ;

			/*Select GPIO OSPEED & OTYPE  In case Pin Output or AF  */
			if (PinConfig->Mode == GPIO_OUTPUT || PinConfig->Mode == GPIO_AF )
			{
				/*Select OutPut Type -> PUSHPULL | OPENDRAIN*/
				(GPIOPORT[PinConfig->PortNum]->OTYPER.Reg) &=~((OTYPER_MASK)<<( PinConfig->PinNumber * OTYPER_MASK));
				(GPIOPORT[PinConfig->PortNum]->OTYPER.Reg) |= ((PinConfig->OPType)<<(PinConfig->PinNumber) );

				/*Select OutPut Speed Low Medium Fast High*/
				(GPIOPORT[PinConfig->PortNum]->OSPEEDR.Reg) &=~((OSPEEDR_MASK)<<(PinConfig->PinNumber * OSPEEDR_MASK));
				(GPIOPORT[PinConfig->PortNum]->OSPEEDR.Reg) |= ((PinConfig->Speed)<<(PinConfig->PinNumber * OSPEEDR_PIN_ACESS_BITS));
				if(PinConfig->Mode == GPIO_AF)
				{
					/*Setting AF*/
					uint8_t Local_u8RegNum = (PinConfig->PinNumber)/8U ;
					uint8_t Local_u8PinNum = (PinConfig->PinNumber)%8U ;


					(GPIOPORT[PinConfig->PortNum]->AFR[Local_u8RegNum]) &=~((AFR_MASK)<<Local_u8PinNum* AFR_PIN_ACESS_BITS  );
					(GPIOPORT[PinConfig->PortNum]->AFR[Local_u8RegNum]) |= ((PinConfig->AF) << Local_u8PinNum* AFR_PIN_ACESS_BITS);

				}
			}
		}
		else
		{
			LocalErrorStatue = NOK;
		}

	}
	else
	{
		LocalErrorStatue = NULL_POINTER ;
	}
	return LocalErrorStatue ;
}

/******************************************************************************
 * @func :  GPIO_u8SetPinValue
 *
 * Description:	the function is Set Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,...)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS (PIN0,PIN1,......)
 * 			   3- PinVal_E	 : it's Enum For Switch Value(GPIO_PINHIGH,GPIO_PINLOW)
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/


uint8_t GPIO_u8SetPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E VAL )
{
	uint8_t LocalErrorStatue = OK ;
	if (PORT < INVALIED_PORT && PIN < INVALIED_PIN )
	{
		switch (VAL)
		{
		/*SET & RESER VAL BY BSRR BIT SET REST REGISTERS  */
		case GPIO_PINHIGH : SET_BIT(  GPIOPORT[PORT]->BSRR.Reg  , PIN ); break ;
		case GPIO_PINLOW  : SET_BIT(  GPIOPORT[PORT]->BSRR.Reg  , (PIN +BSSR_PIN_ACCESS_BITS)); break ;
		default :LocalErrorStatue = NOK 							 ; break ;
		}

	}
	else
	{
		LocalErrorStatue = NOK ;
	}



	return LocalErrorStatue ;
}

/******************************************************************************
 * @func :  GPIO_u8TogglePinValue
 *
 * Description:	the function is Toggle Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,...)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:	   ErrorState , Type:uint8_t
 *
 ******************************************************/
uint8_t GPIO_u8TogglePinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN )
{
	uint8_t LocalErrorStatue=OK ;
	if (PORT <= INVALIED_PORT && PIN <= INVALIED_PIN )
	{
		TOG_BIT((GPIOPORT[PORT]->ODR.Reg),PIN);

	}
	else
	{
		LocalErrorStatue = NOK ;
	}
	return LocalErrorStatue ;

}
/******************************************************************************
 * @func :  GPIO_u8ReadPinValue
 *
 * Description:	the function is Read Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8ReadPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E* VAL )
{

	uint8_t LocalErrorStatue=OK ;
	if (PORT <= INVALIED_PORT && PIN <= INVALIED_PIN )
	{

		*VAL = GET_BIT(GPIOPORT[PORT]->IDR.Reg,PIN);

	}
	else
	{
		LocalErrorStatue = NOK ;
	}

	return LocalErrorStatue ;

}
uint8_t GPIO_voidSetPortValue(GPIO_PORT_E PORT, uint16_t Val)
{
	uint8_t LocalErrorStatue=OK ;

	if(PORT < INVALIED_PORT)
	{
		GPIOPORT[PORT]->ODR.Reg=Val;
	}
	else
	{
		LocalErrorStatue = NOK;
	}
	return LocalErrorStatue;
}




