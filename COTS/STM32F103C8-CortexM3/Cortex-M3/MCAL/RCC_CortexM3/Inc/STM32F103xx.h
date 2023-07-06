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
#define RCC_BASE_ADDRESS 							 0x40021000UL

#define GPIOA_BASE_ADDRESS							 0x40010800UL
#define GPIOB_BASE_ADDRESS							 0x40010C00UL
#define GPIOC_BASE_ADDRESS							 0x40011000UL

/*Alternative Function Of GPIO*/
#define AFIO_BASE_ADDRESS							0x40010000UL





///////////////////////////////*Registers Of RCC*//////////////////////////////////////////////////
typedef struct {

	union
	{
		volatile	uint32_t Reg ;
		struct
		{
		uint8_t HSION :1;
		uint8_t HSIRDY :1;
		uint8_t Reserved0 :1;
		uint8_t HSITRIM :5;
		uint8_t HSICAL :8;
		uint8_t HSEON :1;
		uint8_t HSERDY :1;
		uint8_t HSEBYP :1;
		uint8_t CSSON :1;
		uint8_t Reserved1 :4;
		uint8_t PLL_ON :1 ;
		uint8_t PLL_RDY:1;
		uint8_t Reserved2 :6;

		}BIT;
	}CR;
	union {
		volatile	uint32_t Reg ;
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
			uint8_t USBPRE: 1 ;
			uint8_t Reseved3: 1 ;
			uint8_t MCO     : 4 ;
		}Bit;

	}CFGR;

	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR;

	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;


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

#define RCC				 ((volatile RCC_REG_S*)(RCC_BASE_ADDRESS))

#define GPIOA 			((volatile  GPIO_REG_S* ) GPIOA_BASE_ADDRESS)
#define GPIOB 			((volatile  GPIO_REG_S* ) GPIOB_BASE_ADDRESS)
#define GPIOC 			((volatile  GPIO_REG_S* ) GPIOC_BASE_ADDRESS)


#define AFIO 			((volatile GPIO_AFIO_REG_S*)AFIO_BASE_ADDRESS)

#define REG				*(volatile uint32_t*)(RCC_BASE_ADDRESS+0x18)

#endif
