/*
 * DIO_registers.h
 *
 *  Created on: 4/4/2024
 *      Author: Ahmed Nada
 */

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

/**
    *                         Data Direction Registers                                      *
**/

#define DDRA_Reg   *((volatile u8 *) 0x3A)
#define DDRB_Reg   *((volatile u8 *) 0x37)
#define DDRC_Reg   *((volatile u8 *) 0x34)
#define DDRD_Reg   *((volatile u8 *) 0x31)

/********************************************************************************************/


/**
    *                                   Port Registers                                      *
**/

#define PORTA_Reg   *((volatile u8 *) 0x3B)
#define PORTB_Reg   *((volatile u8 *) 0x38)
#define PORTC_Reg   *((volatile u8 *) 0x35)
#define PORTD_Reg   *((volatile u8 *) 0x32)

/********************************************************************************************/

/**
    *                                     Pin Registers                                      *
**/

#define PINA_Reg   *((volatile u8 *) 0x39)
#define PINB_Reg   *((volatile u8 *) 0x36)
#define PINC_Reg   *((volatile u8 *) 0x33)
#define PIND_Reg   *((volatile u8 *) 0x30)

/********************************************************************************************/



#endif /* DIO_REGISTERS_H_ */
