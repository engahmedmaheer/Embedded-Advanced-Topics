#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef enum
{
	HSI,
	HSE,
	PLL,
//	PLL_P,   /*RCC_uint8SetSysClk*/
//	PLL_R,	/*RCC_uint8SetSysClk*/
//	PLLI2S,
//	PLLSAI,
	LSE,
	LSI

}Clktype_E;

typedef enum
{
	NO_CLCK0,
	NO_CLCK1,
	HSE_DIV2,
	HSE_DIV3,
	HSE_DIV4,
	HSE_DIV5,
	HSE_DIV6,
	HSE_DIV7,
	HSE_DIV8,
	HSE_DIV9,
	HSE_DIV10,
	HSE_DIV11,
	HSE_DIV12,
	HSE_DIV13,
	HSE_DIV14,
	HSE_DIV15,
	HSE_DIV16,
	HSE_DIV17,
	HSE_DIV18,
	HSE_DIV19,
	HSE_DIV20,
	HSE_DIV21,
	HSE_DIV22,
	HSE_DIV23,
	HSE_DIV24,
	HSE_DIV25,
	HSE_DIV26,
	HSE_DIV27,
	HSE_DIV28,
	HSE_DIV29,
	HSE_DIV30,
	HSE_DIV31,
}HSE_CONFIG_E;

#define MAX_HSE_CONFIG_E 32
#define MAX_Clktype 4

typedef enum
{
	CLK_OFF,
	CLK_ON
}Status_E;

typedef enum
{
	AHB1,
	AHB2,
	APB1,
	APB2
}BusId_E;



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


/********************* AHB1 _Peripheral **********************/
typedef enum
{
	  GPIOA_ID,
	  GPIOB_ID,
	  GPIOC_ID,
	  GPIOD_ID,
	  GPIOE_ID,
	  GPIOF_ID,
	  GPIOG_ID,
	  GPIOH_ID,
	  CRC_ID = 12,
	  DMA1_ID=21,
	  DMA2_ID ,
	  OTGHS_ID=29
}AHB1_ID_E;

#define MAX_AHB1_ID   30
#define MAX_AHB2_ID   8
#define MAX_AHB3_ID   2

#define MAX_APB1_ID  30
#define MAX_APB2_ID  24
/********************* AHB2 _Peripheral **********************/
typedef enum
{
	DCMI_ID,
	OTGFS_ID=7
}AHB2_ID_E;
/********************* AHB3 _Peripheral **********************/
typedef enum
{
	FMC_ID,
	QSPI_ID
}AHB3_ID_E;

/********************* APB1 _Peripheral **********************/
typedef enum
{
	TIM2_ID,
	TIM3_ID,
	TIM4_ID,
	TIM5_ID,
	TIM6_ID,
	TIM7_ID,
	TIM12_ID,
	TIM13_ID,
	TIM14ID,
	WWDG_ID=11,
	SPI2_ID=14,
	SPI3_ID,
	SPDIF_ID,
	UART2_ID,
	UART3_ID,
	UART4_ID,
	UART5_ID,
	I2C1_ID,
	I2C2_ID,
	I2C3_ID,
	FMPI2C1_ID,
	CAN1_ID,
	CAN2_ID,
	CEC_ID,
	PWR_ID,
	DAC_ID,
}APB1_ID_E;


/********************* APB2 _Peripheral **********************/
typedef enum
{
	TIM1_ID,
	TIM8_ID,
	USART1_ID=4,
	USART6_ID,
	ADC_ID=8,
	SDIO_ID=11,
	SPI1_ID,
	SPI4_ID,
	TIM14_ID,
	SYSCFG_ID=14,
	TIM9_ID=16,
	TIM10_ID,
	TIM11_ID,
	SAI1_ID=22,
	SAI2_ID,
}APB2_ID_E;



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


typedef enum
{
	AHB_NO_DIV,
	AHB_DIV_2,
	AHB_DIV_4,
	AHB_DIV_8,
	AHB_DIV_16,
	AHB_DIV_32,
	AHB_DIV_64,
	AHB_DIV_128,
	AHB_DIV_256,
	AHB_DIV_512

}AHB_PRE_E;

//
///***********AHB1 ENABLE ID  ***********/
//typedef enum
//{
//	GPIOA_EN_ID,
//	GPIOB_EN_ID,
//	GPIOC_EN_ID,
//	GPIOD_EN_ID,
//	GPIOE_EN_ID,
//	GPIOF_EN_ID,
//	GPIOG_EN_ID,
//	GPIOH_EN_ID,
//	CRC_EN_IB = 12 ,
//	BKPSRAM_EN_ID=18,
//	DMA1_EN_ID =21 ,
//	DMA2_EN_ID,
//	OTGHS_EN_ID =29,
//	OTGHSULPI_EN_ID
//}AHB1_EN_ID_E;
//
//#define MAX_AHB1_EN_ID  31
//
//
///***********AHB2 ENABLE ID  ***********/
//typedef enum
//{
//	DCMI_EN_ID,
//	OTGFS_EN_ID=7,
//
//}AHB2_EN_ID_E;
//
//#define MAX_AHB2_EN_ID  8
//
///***********AHB3 ENABLE ID  ***********/
//typedef enum
//{
//	FMCE_EN_ID,
//	QSPI_EN_ID,
//
//}AHB2_EN_ID_E;
//
//#define MAX_AHB3_EN_ID  2
//
//
///***********APB1 ENABLE ID  ***********/
//typedef enum
//{
//	TIM2_EN_ID,
//	TIM3_EN_ID,
//	TIM4_EN_ID,
//	TIM5_EN_ID,
//	TIM6_EN_ID,
//	TIM7_EN_ID,
//	TIM12_EN_ID,
//	TIM13_EN_ID,
//	TIM14_EN_ID,
//	WWDG_EN_ID=11,
//	SPI2_EN_ID=14,
//	SPI3_EN_ID,
//	SPDIFRX_EN_ID,
//	USART2_EN_ID,
//	USART3_EN_ID,
//	UART4_EN_ID,
//	UART5_EN_ID,
//	I2C1_EN_ID,
//	I2C2_EN_ID,
//	I2C3_EN_ID,
//	FMPI2C1_EN_ID,
//	CAN1_EN_ID,
//	CAN2_EN_ID,
//	CEC_EN_ID,
//	PWR_EN_ID,
//	DAC_EN_ID,
//}APB1_EN_ID_E;
//
//#define MAX_APB1_EN_ID  30



#define Max_AHB_PRE_E  5
#define Max_AHB   10
#define AHB_MASK 0b1111

#define MAXTIMEOUT_VALUE 5000
#define SW_MASK   0b11 //System clock Switch
#define PLL_MASK 0b1111
#define HSE_Mask 0b11
#define PPRE2_Mask 0b111
#define ZERO_FLAG  0



//#define RCC_TEST_CFGR		*((volatile uint32_t*)(RCC_BASE_ADDRESS+0x08))






#endif
