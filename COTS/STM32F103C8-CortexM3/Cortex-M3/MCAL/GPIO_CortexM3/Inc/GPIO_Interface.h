/*
 * GPIO_Interface.h
 *
 *  Created on: May 5, 2023
 *      Author: AhmedMaher
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_




typedef enum
{
	PORTA ,
	PORTB ,
	PORTC ,
	PORTD ,
	PORTE ,
	PORTF ,
	PORTG ,
	PORTH ,
	INVALIED_PORT
}GPIO_PORT_E;

typedef enum
{
	PIN0  ,
	PIN1  ,
	PIN2 ,
	PIN3  ,
	PIN4  ,
	PIN5  ,
	PIN6  ,
	PIN7  ,
	PIN8  ,
	PIN9  ,
	PIN10  ,
	PIN11  ,
	PIN12  ,
	PIN13  ,
	PIN14  ,
	PIN15  ,
	INVALIED_PIN
}GPIO_PIN_E;

typedef enum
{
	/*For MODE Reg */
	GPIO_INPUT ,
	GPIO_OUTPUT_LOWSPEED,
	GPIO_OUTPUT_MEDUIM_SPEED,
	GPIO_OUTPUT_MAX_SPEED,

}GPIO_MODE_E;

typedef enum
{
	GPIO_ANALOG ,
	GPIO_FLOATING,
	GPIO_PUPD,
	INVALIED
}GPIO_INPUT_E;

typedef enum
{
	GPIO_PUSHPULL ,
	GPIO_OPENDRAIN,
	GPIO_AF_PP,
	GPIO_AF_OD
}GPIO_OUTPUT_E;

//typedef enum
//{
//	GPIO_NOPULL ,
//	GPIO_PULLUP,
//	GPIO_PULLDOWN
//}GPIO_PULLUPDOWN_E;

typedef enum
{
	GPIO_AF0  ,
	GPIO_AF1  ,
	GPIO_AF2 ,
	GPIO_AF3  ,
	GPIO_AF4  ,
	GPIO_AF5  ,
	GPIO_AF6  ,
	GPIO_AF7  ,
	GPIO_AF8  ,
	GPIO_AF9  ,
	GPIO_AF10  ,
	GPIO_AF11  ,
	GPIO_AF12  ,
	GPIO_AF13  ,
	GPIO_AF14  ,
	GPIO_AF15  ,
}GPIO_AF_E;

typedef enum
{
	GPIO_PINLOW,
	GPIO_PINHIGH
}PinVal_E;

typedef struct
{
	GPIO_PORT_E        PortNum ;
	GPIO_PIN_E         PinNumber;
	GPIO_MODE_E        Mode;
	GPIO_INPUT_E       InputType;
	GPIO_OUTPUT_E      OutPutType;
	GPIO_AF_E          AF;

}GPIO_PinConfig_S;


uint8_t GPIO_u8PinInit(const GPIO_PinConfig_S* PinConfig);


uint8_t GPIO_u8SetPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E VAL );

uint8_t GPIO_u8TogglePinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN );

uint8_t GPIO_u8ReadPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E* VAL );

uint8_t GPIO_voidSetPortValue(GPIO_PORT_E PORT, uint16_t Val);




#endif /* GPIO_INTERFACE_H_ */
