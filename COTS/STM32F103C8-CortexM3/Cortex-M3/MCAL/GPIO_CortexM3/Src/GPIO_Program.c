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


#include "STM32F103xx.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"


/*For peripheral Only*/
static GPIO_REG_S* GPIOPORT[GPIO_PERIPHERAL_NUM] ={GPIOA,GPIOB,GPIOC};

/******************************************************************************
 * @func :  GPIO_u8PinInit
 *
 * Description:	the function initialize the required pin configuration  options
 *
 * Parameters:
 * @par[in]  : 1- PinConfig: const pointer to GPIO_PinConfig_S structure which holds the configurations
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
			if (PinConfig->PinNumber <= LOW_PINS)
			{
				/*Set Mode  For Low Pins in CTRL Reg */
				(GPIOPORT[PinConfig->Mode] ->CRL.Reg)&=~(CRL_MASK)<<(PinConfig->PinNumber*CR_PIN_ACCESS_BITS) ;
				(GPIOPORT[PinConfig->Mode])->CRL.Reg |= ((PinConfig->Mode)<<(PinConfig->PinNumber*CR_PIN_ACCESS_BITS)) ;

				/*Select CNF Pins */
				if (PinConfig->Mode == GPIO_INPUT)
				{
					(GPIOPORT[PinConfig->Mode] ->CRL.BIT.CNF)&=~(CNF_MASK) ;
					(GPIOPORT[PinConfig->Mode] ->CRL.BIT.CNF) |= PinConfig->InputType ;

				}
				else if (PinConfig->Mode != GPIO_INPUT)
				{
					(GPIOPORT[PinConfig->Mode] ->CRL.BIT.CNF)&=~(CNF_MASK) ;
					(GPIOPORT[PinConfig->Mode] ->CRL.BIT.CNF) |= PinConfig->OutPutType ;

				}
				else
				{
					LocalErrorStatue = NOK ;
				}


			}
			else if (PinConfig->PinNumber <= HIGH_PINS)
			{
				/*Set Mode For Low Pins */
				(GPIOPORT[PinConfig->Mode]->CRH.Reg) &=~(CRL_MASK)<<(PinConfig->PinNumber*CR_PIN_ACCESS_BITS) ;
				(GPIOPORT[PinConfig->Mode])->CRH.Reg |= ((PinConfig->Mode)<<(PinConfig->PinNumber*CR_PIN_ACCESS_BITS)) ;

				/*Select CNF Pins */
				if (PinConfig->Mode == GPIO_INPUT)
				{
					(GPIOPORT[PinConfig->Mode] ->CRH.BIT.CNF)&=~(CNF_MASK) ;
					(GPIOPORT[PinConfig->Mode] ->CRH.BIT.CNF) |= PinConfig->InputType ;

				}
				else if (PinConfig->Mode != GPIO_INPUT)
				{
					(GPIOPORT[PinConfig->Mode] ->CRH.BIT.CNF)&=~(CNF_MASK) ;
					(GPIOPORT[PinConfig->Mode] ->CRH.BIT.CNF) |= PinConfig->OutPutType ;

				}
				else
				{
					LocalErrorStatue = NOK ;
				}
			}
			else
			{
				//Error
				LocalErrorStatue = NOK ;

			}
			return LocalErrorStatue ;
		}
	}
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
	if (PORT <= INVALIED_PORT && PIN < INVALIED_PIN )
	{
		switch (VAL)
		{
		/*SET & RESER VAL BY BSRR BIT SET REST REGISTERS  */
		case GPIO_PINHIGH : SET_BIT(  GPIOPORT[PORT]->BSRR.Reg  , PIN ); break ;
		case GPIO_PINLOW  : SET_BIT(  GPIOPORT[PORT]->BSRR.Reg  ,( PIN +BSSR_PIN_ACCESS_BITS)); break ;
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
	if (PORT <= INVALIED_PORT && PIN < INVALIED_PIN )
	{
		SET_BIT((GPIOPORT[PORT]->BRR.Reg),PIN);

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
	if ( VAL != NULL)
	{
		if (PORT < INVALIED_PORT && PIN < INVALIED_PIN )
		{

			*VAL = GET_BIT(GPIOPORT[PORT]->IDR.Reg,PIN);

		}
		else
		{
			LocalErrorStatue = NOK ;
		}
	}
	else
	{
		LocalErrorStatue = NULL_POINTER ;

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



