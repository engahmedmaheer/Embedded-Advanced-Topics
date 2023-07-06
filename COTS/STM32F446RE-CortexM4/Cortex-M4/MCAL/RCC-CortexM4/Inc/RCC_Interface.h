#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "RCC_Private.h"


uint8_t RCC_uint8SetClkStatues(Clktype_E clocktype , Status_E Status);

void RCC_VoidEnableClocksecuritysystem(void);

uint8_t RCC_uint8SetSysClk(Clktype_E clocktype);

uint8_t RCC_uint8HSEConfig(HSE_CONFIG_E HSEConfig);

uint8_t RCC_APB2HighSpeedPrescaler(AHB_PRE_E AHBPRESCELAR);

uint8_t RCC_AHBHighSpeedPrescaler(AHB_PRE_E AHBPRESCELAR);



uint8_t RCC_uint8PLLConfig(PLL_CONFIG_E PLLConfig);



uint8_t RCC_uint8EnablePeripheralBus(BusId_E BusId,uint8_t Uint8Peripheral_ID);

uint8_t RCC_uint8DisablePeripheralBus(BusId_E BusId,uint8_t Uint8Peripheral_ID);

/******************REST FUNC*************************/
//uint8_t RCC_uint8ResetAHB1PeripheralBus(AHB1_REST_ID_E ID);
//uint8_t RCC_uint8ResetAHB2PeripheralBus(AHB2_REST_ID_E ID);
//uint8_t RCC_uint8ResetAHB3PeripheralBus(AHB3_REST_ID_E ID);
//uint8_t RCC_uint8ResetAPB1PeripheralBus(APB1_REST_ID_E ID);
//uint8_t RCC_uint8ResetAPB2PeripheralBus(APB2_REST_ID_E ID);

uint8_t RCC_uint8ResetPreipheralBus (BusId_E BusID , uint8_t PeripheralId);


#endif
