#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


typedef enum
{
	HSI,
	HSE,
	PLL

}Clktype_E;

#define MAX_Clktype 3

typedef enum
{
	CLK_OFF,
	CLK_ON
}Status_E;

typedef enum
{
	AHB ,
	APB1,
	APB2
}BusId_E;


typedef enum
{
	DIV_1 ,
	DIV_2
}HSE_CONFIG_E;

typedef enum
{
	PLLSRC,
	PLLXTPRE,
	PLLMUL
}PLL_CONFIG_E;

typedef enum
{
	UNREADY,
	READY
}READY_STATUES_E;

typedef enum
{
 DMA1EN,
 DMA2EN ,
 SRAMEN ,
 FLITFEN =4 ,
 CRCEN   =6 ,
 FSMCEN  =8 ,
 SDIOEN  =10,
}AHB_ID_E;

/********************* AHB2 _Peripheral **********************/
 typedef enum {
 AFIOEN ,
 IOPAEN = 2,
 IOPBEN  ,
 IOPCEN  ,
 IOPDEN  ,
 IOPEEN  ,
 IOPFEN  ,
 IOPGEN  ,
 ADC1EN  ,
 ADC2EN  ,
 TIM1EN  ,
 SPI1EN  ,
 TIM8EN  ,
 USART1EN,
 ADC3EN  ,
 TIM9EN   =19,
 TIM10EN ,
 TIM11EN
 }APB2_ID_E;

 /********************* AHB1 _Peripheral **********************/
 typedef enum
 {
  TIM2EN  ,
  TIM3EN ,
  TIM4EN ,
  TIM5EN ,
  TIM6EN ,
  TIM7EN ,
  TIM12EN,
  TIM13EN,
  TIM14EN,
  WWDGEN  = 11 ,
  SPI2EN  = 14 ,
  SPI3EN     ,
  USART2EN =17 ,
  USART3EN   ,
  UART4EN    ,
  UART5EN    ,
  I2C1EN     ,
  I2C2EN     ,
  USBEN      ,
  CANEN    =25 ,
  BKPEN    =27 ,
  PWREN      ,
  DACEN
 }AHB1_ID_E;



 /***PLL*********/
 /***************PLL input clock options******************/

 typedef enum
 {
  PLL_X2  ,
  PLL_X3  ,
  PLL_X4  ,
  PLL_X5  ,
  PLL_X6  ,
  PLL_X7  ,
  PLL_X8  ,
  PLL_X9  ,
  PLL_X10 ,
  PLL_X11 ,
  PLL_X12 ,
  PLL_X13 ,
  PLL_X14 ,
  PLL_X15 ,
  PLL_X16 ,
 }PLL_X_E;



uint8_t RCC_VoidSetClkStatues(Clktype_E clocktype , Status_E Status);

uint8_t RCC_VoidSetSysClk(Clktype_E clocktype);

uint8_t RCC_VoidHSEConfig(HSE_CONFIG_E HSEConfig);

uint8_t RCC_VoidPLLConfig(PLL_CONFIG_E PLLConfig);

uint8_t RCC_voidEnablePeripheralBus(BusId_E BusId,uint8_t Uint8Peripheral_ID);

uint8_t RCC_voidDisablePeripheralBus(BusId_E BusId,uint8_t Uint8Peripheral_ID);


#endif
