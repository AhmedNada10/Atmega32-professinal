/*
 *	File Name: 		EXTI_config.h
 *
 *	Creation Date: 	Apr 8, 2024
 *
 *   Author: 		Ahmed Nada
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*
 *
 *                                   Interrupt Sense Control                                             *
 *
 */

/*Choices:
            1: EXTI_LowLevel  , 2:EXTI_AnyLogicalChange     (1 and 2 Can be used only with Interrupt 0 and Interrupt 1)
            3:EXTI_FallingEdge , 4:EXTI_RisingEdge  , 5: EXTI_Disable
 */

/*External Interrupt 0*/
#define EXTI0_SenseControl EXTI_FallingEdge

/*External Interrupt 1*/
#define EXTI1_SenseControl EXTI_FallingEdge

/*External Interrupt 2*/
#define EXTI2_SenseControl EXTI_FallingEdge

/********************************************************************************************************/

/*
 *
 *                                   GICR                                            *
 *
 */

/*Choices:
            1: EXTI_Enable  2:EXTI_Disable
 */

/*External Interrupt 0*/
#define EXTI0_PIE EXTI_Enable

/*External Interrupt 1*/
#define EXTI1_PIE EXTI_Enable

/*External Interrupt 2*/
#define EXTI2_PIE EXTI_Enable

/********************************************************************************************************/

#endif /* EXTI_CONFIG_H_ */
