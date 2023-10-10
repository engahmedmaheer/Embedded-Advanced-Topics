/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: AhmedMaher	********************************/
/*************************  Date: 14/4/2023		********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*************************  Target :STM32F446XX	********************************/
/*******************************************************************************/
/*******************************************************************************/

#include "BIT_MATH.h"
#include "ERR_TYPE.h"
#include <stdint.h>
#include "STM32F446xx.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"


uint8_t RCC_uint8SetClkStatues(Clktype_E clocktype , Status_E Status)
{
	uint32_t Local_TimeOut=0;
	uint8_t Local_u8ErrorState= OK;
	switch (clocktype)
	{
	case HSI :
		if (Status == CLK_ON)
		{
			/*Enable HSI*/
			RCC->CR.Bit.HSION=CLK_ON;
			while((RCC->CR.Bit.HSIRDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status == CLK_OFF)
		{
			/*Enable HSI*/
			RCC->CR.Bit.HSION=CLK_OFF;
			while((RCC->CR.Bit.HSIRDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

		break;
	case HSE:
		if (Status == CLK_ON)
		{
			/*Enable HSI*/
			RCC->CR.Bit.HSEON=CLK_ON;
			while((RCC->CR.Bit.HSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status == CLK_OFF)
		{
			/*Enable HSI*/
			RCC->CR.Bit.HSION=CLK_OFF;
			while((RCC->CR.Bit.HSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}

		break ;
	case PLL:
		if (Status == CLK_ON)
		{
			/*Enable HSI*/
			RCC->CR.Bit.PLLON=CLK_ON;
			while((RCC->CR.Bit.PLLRDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status == CLK_OFF)
		{
			/*Enable HSI*/
			RCC->CR.Bit.PLLON=CLK_OFF;
			while((RCC->CR.Bit.PLLRDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		break;

	case LSE:
		if (Status == CLK_ON)
		{
			/*Enable HSI*/
			RCC->BDCR.Bit.LSEON=CLK_ON;
			while((RCC->BDCR.Bit.LSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status == CLK_OFF)
		{
			/*Enable HSI*/
			RCC->BDCR.Bit.LSEON=CLK_OFF;
			while((RCC->BDCR.Bit.LSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		break;

	case LSI:
		if (Status == CLK_ON)
		{
			/*Enable HSI*/
			RCC->BDCR.Bit.LSEON=CLK_ON;
			while((RCC->BDCR.Bit.LSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status == CLK_OFF)
		{
			/*Enable HSI*/
			RCC->BDCR.Bit.LSEON=CLK_OFF;
			while((RCC->BDCR.Bit.LSERDY==ZERO_FLAG )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}

		}
		else
		{
			Local_u8ErrorState = NOK ;
		}
		break;


	}



	return Local_u8ErrorState ;
}

void RCC_VoidEnableClocksecuritysystem(void)
{
	RCC->CR.Bit.CSSON=1;

}

uint8_t RCC_uint8SetSysClk(Clktype_E clocktype)
{

	uint8_t Local_u8ErrorState= OK;
	if(clocktype> MAX_Clktype)
	{
		RCC->CFGR.Bit.SW &=~(SW_MASK);
		RCC->CFGR.Bit.SW|=clocktype ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}



	return Local_u8ErrorState ;

}

uint8_t RCC_uint8HSEConfig(HSE_CONFIG_E HSEConfig)
{
	uint8_t Local_u8ErrorState= OK;
	if (HSEConfig < MAX_HSE_CONFIG_E)
	{
		/*Disable HSE*/
		RCC_uint8SetSysClk(HSI);

		RCC->CFGR.Bit.RTCPRE&=~(HSE_Mask);
		RCC->CFGR.Bit.RTCPRE |=HSEConfig ;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}
	return Local_u8ErrorState ;
}





uint8_t RCC_APB2HighSpeedPrescaler(AHB_PRE_E AHBPRESCELAR)
{
	uint8_t Local_u8ErrorState= OK;
	if (AHBPRESCELAR <Max_AHB_PRE_E)
	{
		RCC->CFGR.Bit.PPRE2&=~(PPRE2_Mask);
		RCC->CFGR.Bit.PPRE2 |=AHBPRESCELAR;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState ;
}
uint8_t RCC_APB1HighSpeedPrescaler(AHB_PRE_E AHBPRESCELAR)

{
	uint8_t Local_u8ErrorState= OK;

	if (AHBPRESCELAR < Max_AHB_PRE_E)
	{
		RCC->CFGR.Bit.PPRE1&=~(PPRE2_Mask);
		RCC->CFGR.Bit.PPRE1 |=AHBPRESCELAR;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState ;
}


uint8_t RCC_AHBHighSpeedPrescaler(AHB_PRE_E AHBPRESCELAR)
{

	uint8_t Local_u8ErrorState= OK;

	if (AHBPRESCELAR < Max_AHB)
	{
		RCC->CFGR.Bit.HPRE&=~(AHB_MASK);
		RCC->CFGR.Bit.HPRE |=AHBPRESCELAR;
	}
	else
	{
		Local_u8ErrorState =NOK ;
	}

	return Local_u8ErrorState ;
}


uint8_t RCC_uint8EnablePeripheralBus(BusId_E BusId,uint8_t PeripheralId)
{
	uint8_t Local_u8ErrorState= OK;
		switch (BusId)
		{
		case AHB1 :

			if (PeripheralId < MAX_AHB1_ID)
			{
				/*ENABLE PERIPHERAL ID*/

				SET_BIT(RCC->AHB1ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}
			break;
		case AHB2 :

			if (PeripheralId < MAX_AHB2_ID)
			{
				/*ENABLE PERIPHERAL ID*/
				SET_BIT(RCC->AHB2ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}

			break;
		case APB1 :

			if (PeripheralId < MAX_APB1_ID)
			{
				/*ENABLE PERIPHERAL ID*/
				SET_BIT(RCC->APB1ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}


			break;

		case APB2 :
			if (PeripheralId < MAX_APB2_ID)
			{
				/*ENABLE PERIPHERAL ID*/
				SET_BIT(RCC->APB2ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}

			break;
		}

		return Local_u8ErrorState ;

}

uint8_t RCC_uint8DisablePeripheralBus(BusId_E BusId,uint8_t PeripheralId)
{

	uint8_t Local_u8ErrorState= OK;
		switch (BusId)
		{
		case AHB1 :

			if (PeripheralId < MAX_AHB1_ID)
			{
				/*CLEAR  PERIPHERAL ID*/
				CLR_BIT(RCC->AHB1ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}
			break;
		case AHB2 :

			if (PeripheralId < MAX_AHB2_ID)
			{
				/*CLEAR  PERIPHERAL ID*/
				CLR_BIT(RCC->AHB2ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}

			break;
		case APB1 :

			if (PeripheralId < MAX_APB1_ID)
			{
				/*CLEAR  PERIPHERAL ID*/
				CLR_BIT(RCC->APB1ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}


			break;

		case APB2 :
			if (PeripheralId < MAX_APB2_ID)
			{
				/*CLEAR PERIPHERAL ID*/
				CLR_BIT(RCC->APB2ENR.Reg,PeripheralId);
			}
			else
			{
				/* Error ID */
				Local_u8ErrorState = NOK;
			}

			break;
		}

		return Local_u8ErrorState ;

}
uint8_t RCC_uint8ResetPreipheralBus (BusId_E BusID , uint8_t PeripheralId)
{
	uint8_t Local_u8ErrorState= OK;
	switch (BusID)
	{
	case AHB1 :

		if (PeripheralId < MAX_AHB1_ID)
		{
			/*RESET PERIPHERAL ID*/
			SET_BIT(RCC->AHB1RSTR.Reg,PeripheralId);
		}
		else
		{
			/* Error ID */
			Local_u8ErrorState = NOK;
		}
		break;
	case AHB2 :

		if (PeripheralId < MAX_AHB2_ID)
		{
			/*RESET PERIPHERAL ID*/
			SET_BIT(RCC->AHB2RSTR.Reg,PeripheralId);
		}
		else
		{
			/* Error ID */
			Local_u8ErrorState = NOK;
		}

		break;
	case APB1 :

		if (PeripheralId < MAX_APB1_ID)
		{
			/*RESET PERIPHERAL ID*/
			SET_BIT(RCC->APB1RSTR.Reg,PeripheralId);
		}
		else
		{
			/* Error ID */
			Local_u8ErrorState = NOK;
		}


		break;

	case APB2 :
		if (PeripheralId < MAX_APB2_ID)
		{
			/*RESET PERIPHERAL ID*/
			SET_BIT(RCC->APB1RSTR.Reg,PeripheralId);
		}
		else
		{
			/* Error ID */
			Local_u8ErrorState = NOK;
		}

		break;
	}

	return Local_u8ErrorState ;
}
uint8_t RCC_uint8PLLConfig(PLL_CONFIG_E PLLConfig)
{

	uint8_t Local_u8ErrorState= OK;





	return Local_u8ErrorState ;
}
