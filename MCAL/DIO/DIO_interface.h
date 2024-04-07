/*
 * DIO_interface.h
 *
 *  Created on: 4/4/2024
 *      Author: Ahmed Nada
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**
    *                            Macros                                  *
**/

/*  Ports Id  */
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3


/*  Pins Id  */
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7


/* Ports Direction */
#define DIO_INPUT   0
#define DIO_OUTPUT  1

/*Pins Values*/
#define DIO_LOW 0
#define DIO_HIGH 1

/********************************************************************/

typedef enum DIO_Status 
{
    DIO_NOK , 
    DIO_OK
}DIOStatus;




/** Set the Pin Direction **/
DIOStatus DIO_DIOStatus_SetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Direction);

/** Set the Pin Value **/
DIOStatus DIO_DIOStatus_SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId  , u8 Copy_u8Value);

/** Get Pin Value **/

DIOStatus DIO_DIOStatus_GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 * Copy_u8ptr2value);


/** Set the Port Direction **/
DIOStatus DIO_DIOStatus_SetPortDirection(u8 Copy_u8PortId , u8 Copy_u8Direction);

/** Set the Port Value **/
DIOStatus DIO_DIOStatus_SetPortValue(u8 Copy_u8PortId ,  u8 Copy_u8Value);

/** Get Port Value **/

DIOStatus DIO_DIOStatus_GetPortValue(u8 Copy_u8PortId ,  u8 * Copy_u8ptr2value);



#endif /* DIO_INTERFACE_H_ */
