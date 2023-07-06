/*
 * GPIO_Private.h
 *
 *  Created on: May 5, 2023
 *      Author: AhmedMaher
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_





#define GPIO_PERIPHERAL_NUM	8U




#define	MODER_MASK					 	 	   0b11
#define	OTYPER_MASK					 	 	   0b1
#define	OSPEEDR_MASK						   0b11
#define	PUPDR_MASK							   0b11
#define	AFR_MASK							   0b1111

#define MODER_PIN_ACESS_BITS               	    2
#define OSPEEDR_PIN_ACESS_BITS               	2
#define PUPDR_PIN_ACESS_BITS               	    2
#define AFR_PIN_ACESS_BITS               	    4


#define BSSR_PIN_ACCESS_BITS					16
#endif /* GPIO_PRIVATE_H_ */
