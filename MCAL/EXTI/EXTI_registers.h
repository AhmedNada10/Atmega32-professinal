/*
 *	File Name: 		EXTI_registers.h
 *
 *	Creation Date: 	Apr 8, 2024
 *
 *   Author: 		Ahmed Nada
 */

#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_

#define SREG_EXTI_Reg *((volatile u8 *)0x5F)
#define MCUCR_EXTI_Reg *((volatile u8 *)0x55)
#define MCUCSR_EXTI_Reg *((volatile u8 *)0x54)
#define GICR_EXTI_Reg *((volatile u8 *)0x5B) // PIE
#define GIFR_EXTI_Reg *((volatile u8 *)0x5A)

#endif /* EXTI_REGISTERS_H_ */
