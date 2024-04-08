/*
 *	File Name: 		EXTI_private.h
 *
 *	Creation Date: 	Apr 8, 2024
 *
 *   Author: 		Ahmed Nada
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*
 *
 *													Registers Bits									*
 *
 */

/* MCUCR BitS */

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

/* MCUCSR Bits */
#define ISC2 6

/* GICR Bits */
#define INT0 6
#define INT1 7
#define INT2 5

/* GIFR Bits */
#define INTF0 6
#define INTF1 7
#define INTF2 5
/****************************************************************************************************/

/*
 *
 *                                           Configuration Choices                                    *
 *
 */

#define EXTI_Disable 120

/*Interrupt Sense Control*/
#define EXTI_LowLevel 10
#define EXTI_AnyLogicalChange 11
#define EXTI_FallingEdge 12
#define EXTI_RisingEdge 13

/*GIC */
#define EXTI_Enable 121
/****************************************************************************************************/
#endif /* EXTI_PRIVATE_H_ */
