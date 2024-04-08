/*
 *	File Name: 		EXTI_interface.h
 *
 *	Creation Date: 	Apr 8, 2024
 *
 *   Author: 		Ahmed Nada
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*External Interrupts Names*/
#define EXTI0 10
#define EXTI1 11
#define EXTI2 12

typedef enum EXTI_Status
{
    EXTI_Nok,
    EXTI_Ok
} EXTIStatus;

/*
 *
 *                                       Functions Prototype                              *
 *
 */

/* Clear flag manually */
EXTIStatus EXTI_EXTIStatusClearFlag(u8 Copy_u8InterruptId);

/*Initialize the External interrupt*/
EXTIStatus EXTI_EXTIStatusInit(u8 Copy_u8InterruptId);

/*User passes Function to be the ISR */
EXTIStatus EXTI_EXTIStatusSetISR(void (*Copy_u8Ptr2Func)(void), u8 Copy_u8InterruptId);

/*****************************************************************************************/

#endif /* EXTI_INTERFACE_H_ */
