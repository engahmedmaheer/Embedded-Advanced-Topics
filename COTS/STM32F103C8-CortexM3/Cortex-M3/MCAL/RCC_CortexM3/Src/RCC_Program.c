/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: AhmedMaher	********************************/
/*************************  Date: 14/4/2023		********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*************************  Target :STM32F103XX	********************************/
/*******************************************************************************/
/*******************************************************************************/

#include <stdio.h>
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include <STM32F103xx.h>
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
//#include "DET.h"




uint8_t RCC_VoidSetClkStatues(Clktype_E clocktype , Status_E Status)
{
	uint32_t Local_TimeOut=0;
	uint8_t Localu8ErrorStatus = OK ;
	switch(clocktype)
	{
	case HSE :
		if(Status==CLK_ON)
		{
			/*Enable HSE*/
			RCC->CR.BIT.HSEON=CLK_ON;
			/*Waitting until ready*/
			while((RCC->CR.BIT.HSERDY==0 )&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status==CLK_OFF)
		{
			/*Disable HSE*/
			RCC->CR.BIT.HSEON=CLK_OFF;
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_VoidSetClkStatues,DET_clocktype);
		}

		;break;
	case HSI :
		if(Status==CLK_ON)
		{
			/*Enable HSI*/
			RCC->CR.BIT.HSION=CLK_ON;
			/*Waitting until ready*/
			while((RCC->CR.BIT.HSIRDY==0)&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++ ;
			}
		}
		else if (Status==CLK_OFF)
		{
			/*Disable HSI*/
			RCC->CR.BIT.HSION=CLK_OFF;
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_VoidSetClkStatues,DET_clocktype);
		}
		;break;
	case PLL :
		if(Status==CLK_ON)
		{
			/*Enable PLL*/
			RCC->CR.BIT.PLL_ON=CLK_ON;
			/*Waitting until ready*/
			while((RCC->CR.BIT.PLL_RDY==0)&& (Local_TimeOut< MAXTIMEOUT_VALUE))
			{
				Local_TimeOut++;
			}
		}
		else if (Status==CLK_OFF)
		{
			/*Disable PLL*/
			RCC->CR.BIT.PLL_ON=CLK_OFF;
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_VoidSetClkStatues,DET_clocktype);
		}
		;break;
	default:
		Localu8ErrorStatus=NOK;
		//DET_ReportError(DET_RCCModuleID,DET_RCC_VoidSetClkStatues,DET_clocktype);
		break;
	}
	return Localu8ErrorStatus ;

}

uint8_t RCC_VoidSetSysClk(Clktype_E clocktype)
{
	uint8_t Localu8ErrorStatus = OK ;
	if(clocktype < MAX_Clktype)
	{
		/*CLEAR BITS*/
		RCC->CFGR.Bit.SW &=~(SW_MASK);
		RCC->CFGR.Bit.SW |= clocktype;
	}
	else
	{
		Localu8ErrorStatus=NOK;
//		DET_ReportError(DET_RCCModuleID,DET_RCC_VoidSetSysClk,DET_clocktype);
	}
	return Localu8ErrorStatus ;

}

uint8_t RCC_VoidHSEConfig(HSE_CONFIG_E HSEConfig)
{
	uint8_t Localu8ErrorStatus=OK;
	/*Disable HSE*/
	RCC_VoidSetSysClk(HSI);
	RCC->CR.BIT.HSEON=0;

	/*HSE divider for PLL entry */
	RCC->CFGR.Bit.PLLXTPRE &=~(PLL_MASK);
	RCC->CFGR.Bit.PLLXTPRE |=HSEConfig;

	return Localu8ErrorStatus ;
}


uint8_t RCC_voidEnablePeripheralBus(BusId_E uint8_BusId,uint8_t Uint8_Peripheral_ID)
{
	uint8_t Localu8ErrorStatus=OK;
	switch(uint8_BusId)
	{
	case AHB :
		if (uint8_BusId <= MAX_AHB_ID)
		{
			SET_BIT(RCC->AHBENR,Uint8_Peripheral_ID);
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_AHB_ID);
		}
		break;

	case APB1 :
		if (uint8_BusId <= MAX_APB1_ID)
		{
			SET_BIT(RCC->APB1ENR,Uint8_Peripheral_ID);
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_APB1_ID);
		}
		break;

	case APB2 :
		if (uint8_BusId <= MAX_APB2_ID)
		{
			SET_BIT(RCC->APB2ENR,Uint8_Peripheral_ID);

		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_APB2_ID);
		}
		break;

	}
	return Localu8ErrorStatus ;

}

uint8_t RCC_voidDisablePeripheralBus(BusId_E uint8_BusId,uint8_t Uint8_Peripheral_ID)
{
	uint8_t Localu8ErrorStatus = OK;
	switch(uint8_BusId)
	{
	case AHB :
		if (uint8_BusId <= MAX_AHB_ID)
		{
			CLR_BIT(RCC->AHBENR, Uint8_Peripheral_ID);
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_AHB_ID);
		}
		break;

	case APB1 :
		if (uint8_BusId <= MAX_APB1_ID)
		{
			CLR_BIT(RCC->APB1ENR,Uint8_Peripheral_ID);
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_APB1_ID);
		}
		break;

	case APB2 :
		if (uint8_BusId <= MAX_APB2_ID)
		{
			CLR_BIT(RCC->APB2ENR,Uint8_Peripheral_ID);
		}
		else
		{
			Localu8ErrorStatus=NOK;
//			DET_ReportError(DET_RCCModuleID,DET_RCC_voidEnablePeripheralBus,DET_MAX_APB2_ID);
		}
		break;

	}
	return Localu8ErrorStatus ;

}

uint8_t RCC_VoidPLLConfig(PLL_CONFIG_E PLLConfig)
{
	uint8_t  Localu8ErrorStatus = OK ;


	return Localu8ErrorStatus ;
}
