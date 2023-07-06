/*******************************************************************************/
/*******************************************************************************/
/*************************	Author: AhmedMaher	********************************/
/*************************  Date: 14/4/2023		********************************/
/*************************  Layer: MCAL			********************************/
/*************************  Version: 1.00		********************************/
/*************************  Target :STM32F103XX	********************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef STM32F103XX_H_
#define STM32F103XX_H_

/////////////////////////////*Registers Base Address*//////////////////////////////////////////////
#define RCC_BASE_ADDRESS 							 0x40021000

#define GPIOA_BASE_ADDRESS							 0x40010800
#define GPIOB_BASE_ADDRESS							 0x40010C00
#define GPIOC_BASE_ADDRESS							 0x40011000

/*Alternative Function Of GPIO*/
#define AFIO_BASE_ADDRESS							0x40010000





///////////////////////////////*Registers Of RCC*//////////////////////////////////////////////////
typedef struct {

	union {
		uint32_t Reg ;
		struct {
			uint32_t HSION      : 1;
			uint32_t HSIRDY     : 1;
			uint32_t Reserved0  : 1;
			uint32_t HSITRIM    : 5;
			uint32_t HSICAL     : 8;
			uint32_t HSEON      : 1;
			uint32_t HSERDY     : 1;
			uint32_t HSEBYP     : 1;
			uint32_t CSSON      : 1;
			uint32_t Reserved1  : 4;
			uint32_t PLLON      : 1;
			uint32_t PLLRDY		: 1;
			uint32_t PLL2ON		: 1;
			uint32_t PLL2_RDY	: 1;
			uint32_t PLL3_ON	: 1;
			uint32_t PLL3_RDY	: 1;
			uint32_t Reseved2   : 2;
		}Bit;

	}CR;

	union {
		uint32_t Reg ;
		struct{
			uint8_t SW      : 2 ;
			uint8_t SWS     : 2 ;
			uint8_t HPRE    : 4 ;
			uint8_t PPRE1   : 3 ;
			uint8_t PPRE2   : 3 ;
			uint8_t ADCPRE  : 2 ;
			uint8_t PLLSRC  : 1 ;
			uint8_t PLLXTPRE: 1 ;
			uint8_t PLLMUL  : 4 ;
			uint8_t OTGFSPRE: 1 ;
			uint8_t Reseved3: 1 ;
			uint8_t MCO     : 4 ;
			uint8_t Reseved50: 4 ;
		}Bit;

	}CFGR;

	union {
		uint32_t Reg ;
		struct
		{
			uint8_t  LSIRDYF:1 ;
			uint8_t  LSERDYF:1 ;
			uint8_t  HSIRDYF:1 ;
			uint8_t  HSERDYF:1 ;
			uint8_t  PLLRDYF:1 ;
			uint8_t  Reseved4:2 ;
			uint8_t  CSSF     :1;
			uint8_t  LSIRDYIE: 1;
			uint8_t  LSERDYIE: 1;
			uint8_t  HSIRDYIE: 1;
			uint8_t  HSERDYIE: 1;
			uint8_t  PLLRDYIE: 1;
			uint8_t  Reseved5: 3;
			uint8_t  LSIRDYC: 1 ;
			uint8_t  LSERDYC: 1;
			uint8_t  HSIRDYC: 1;
			uint8_t  HSERDYC: 1;
			uint8_t  PLLRDYC: 1;
			uint8_t  Reseved6:2;
			uint8_t  CSSE:1 ;
			uint8_t  Reseved7:8 ;
		}BIT;
	}CIR;

	union{
		uint32_t Reg ;
		struct
		{
			uint8_t 	AFIORST     :1;
			uint8_t 	Reserved8   :1;
			uint8_t 	IOPARST     :1;
			uint8_t     IOPBRST     :1;
			uint8_t     IOPCRST     :1;
			uint8_t 	IOPDRST     :1;
			uint8_t 	IOPERST     :1;
			uint8_t     Reserved9   :2;
			uint8_t 	ADC1RST     :1;
			uint8_t     ADC2RST     :1;
			uint8_t     TIM1RST     :1;
			uint8_t     SPI1RST     :1;
			uint8_t     Reserved10  :1;
			uint8_t 	USART1RST   :1;
			uint32_t 	Reseved11   :17;
		}BIT;
	}APB2RSTR;

	union{
		uint32_t Reg ;
		struct
		{
			uint8_t 	TIM2RST     :1;
			uint8_t 	TIM3RST     :1;
			uint8_t 	TIM4RST     :1;
			uint8_t     TM5RST      :1;
			uint8_t     TM6RST      :1;
			uint8_t 	TM7RST      :1;
			uint8_t     Reserved12  :5;
			uint8_t     WWDGRST     :1;
			uint8_t     Reserved40  :2;
			uint8_t     SPI2RST     :1;
			uint8_t     SPI3RST     :1;
			uint8_t     Reseved13   :1;
			uint8_t     USART2RST   :1;
			uint8_t     USART3RST   :1;
			uint8_t     UART4RST    :1;
			uint8_t     UART5RST    :1;
			uint8_t     I2C1RST     :1;
			uint8_t     I2C2RST     :1;
			uint8_t     Reseved14   :2;
			uint8_t     CAN1RST     :1;
			uint8_t     CAN2RST     :1;
			uint8_t     BKPRST      :1;
			uint8_t     PWRRST      :1;
			uint8_t     DACRST      :1;
			uint8_t     Reserved15  :2;
		}BIT;
	}APB1RSTR;
	union
	{
		uint32_t Reg;
		struct
		{
			uint8_t DM1AEN      :1 ;
			uint8_t DM2AEN      :1 ;
			uint8_t SRAMEN      :1 ;
			uint8_t Reserved16  :1 ;
			uint8_t FLITFEN     :1 ;
			uint8_t Reserved17  :1 ;
			uint8_t CRCEN       :1 ;
			uint8_t Reserved18  :2 ;
			uint8_t OTGFSEN     :1 ;
			uint8_t Reserved20  :5 ;
			uint8_t ETHMACEN    :1 ;
			uint8_t ETHMACRXEN  :1 ;
			uint16_t Reserved19 :15;

		}BIT;
	}AHBENR;

	union
	{
		uint32_t Reg;
		struct
		{
			uint8_t AFIOEN      :1 ;
			uint8_t Reserved    :1 ;
			uint8_t IOPAEN      :1 ;
			uint8_t IOPBEN      :1 ;
			uint8_t IOPCEN      :1 ;
			uint8_t IOPDEN      :1 ;
			uint8_t IOPEEN      :1 ;
			uint8_t Reserved21  :2 ;
			uint8_t ADC1EN      :1 ;
			uint8_t ADC2EN      :1 ;
			uint8_t TIM1EN      :1 ;
			uint8_t SPI1EN      :1 ;
			uint8_t Reserved22  :1 ;
			uint8_t USART1EN    :1 ;
			uint32_t Reserved23 :17;
		}BIT;
	}APB2ENR;


	union
	{
		uint32_t Reg;
		struct
		{
			uint8_t TIM2EN      :1 ;
			uint8_t TIM3EN      :1 ;
			uint8_t TIM4EN      :1 ;
			uint8_t TIM5EN      :1 ;
			uint8_t TIM6EN      :1 ;
			uint8_t TIM7EN      :1 ;
			uint8_t Reserved24  :5 ;
			uint8_t WWDGEN      :1 ;
			uint8_t Reserved25  :2 ;
			uint8_t SPI2EN      :1 ;
			uint8_t SPI3EN      :1 ;
			uint8_t Reserved26  :1 ;
			uint8_t USART2EN    :1 ;
			uint8_t USART3EN    :1 ;
			uint8_t UART4EN     :1 ;
			uint8_t UART5EN     :1 ;
			uint8_t I2C1EN      :1 ;
			uint8_t I2C2EN      :1 ;
			uint8_t Reserved27  :2 ;
			uint8_t CAN1EN      :1 ;
			uint8_t CAN2EN      :1 ;
			uint8_t BKPEN       :1 ;
			uint8_t PWREN       :1 ;
			uint8_t DACEN       :1 ;
			uint8_t Reserved28  :2 ;

		}BIT;
	}APB1ENR;


	union
	{
		uint32_t Reg;
		struct
		{
			uint8_t LSEON       :1 ;
			uint8_t LSERDY      :1 ;
			uint8_t LSEBYP      :1 ;
			uint8_t Reserved29  :5 ;
			uint8_t RTCSEL      :2 ;
			uint8_t Reserved30  :5 ;
			uint8_t CRCEN       :1 ;
			uint8_t RTCEN       :1 ;
			uint8_t OTGFSEN     :1 ;
			uint8_t BDRST       :1 ;
			uint32_t Reserved31 :15;
		}BIT;
	}BDCR;


	union
	{
		uint32_t Reg;
		struct
		{
			uint8_t LSION       :1 ;
			uint8_t LSIRDY      :1 ;
			uint8_t Reserved32  :1 ;
			uint8_t RMVF        :1 ;
			uint32_t Reserved33 :22;
			uint8_t PINRSTF     :1 ;
			uint8_t PORRSTF     :1 ;
			uint8_t SFTRSTF     :2 ;
			uint8_t IWDGRSTF    :1 ;
			uint8_t WWDGRSTF    :5 ;
			uint8_t LPWRSTF     :1 ;

		}BIT;
	}CSR;

	union
	{
		uint32_t Reg;
		struct
		{
			uint16_t Reserved34       :11 ;
			uint8_t OTGFSRST          :1 ;
			uint8_t Reserved35        :1 ;
			uint8_t ETHMACRST         :1 ;
			uint32_t Reserved36       :18 ;

		}BIT;
	}AHBSTR;

}RCC_REG_S;





typedef struct
{
	union
	{
		volatile uint32_t Reg;
		struct
		{
			uint8_t MODE:2;
			uint8_t CNF:2;

		}BIT;
	}CRL;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			uint8_t MODE:2;
					uint8_t CNF:2;

		}BIT;
	}CRH;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}IDR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}ODR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}BSRR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}BRR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}LCKR;


}GPIO_REG_S;

typedef struct
{
	union
	{
		volatile uint32_t Reg;
		struct
		{
			uint32_t PIN :3 ;
			uint32_t PORT: 3;
			uint32_t EVOE:1 ;
			uint32_t Reserved0: 25;

		}BIT;
	}EVCR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}MAPR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR1;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR2;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR3;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR4;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}MAPR2;


}GPIO_AFIO_REG_S;
/////////////////////////////////*Peripheral *//////////////////////////////////////////////

#define RCC ((volatile RCC_REG_S*)RCC_BASE_ADDRESS)

#define GPIOA (( GPIO_REG_S* ) GPIOA_BASE_ADDRESS)
#define GPIOB (( GPIO_REG_S* ) GPIOB_BASE_ADDRESS)
#define GPIOC (( GPIO_REG_S* ) GPIOC_BASE_ADDRESS)


#define AFIO ((volatile GPIO_AFIO_REG_S*)AFIO_BASE_ADDRESS)



#endif
