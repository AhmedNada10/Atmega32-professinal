/*
 * Program.c
 *
 *  Created on: 4/4/2024
 *      Author: Ahmed Nada
 */

/*
 *                                   Libraries                                          *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_registers.h"
#include "DIO_private.h"
#include "DIO_config.h"
/********************************************************************************************/

/*
 *                               Functions Implementations                                  *
 */

/** Set the Pin Direction **/
DIOStatus DIO_DIOStatus_SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{

    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on Port Id*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        /*Check on direction*/
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            clr_bit(DDRA_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(DDRA_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTB:
        /*Check on direction*/
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            clr_bit(DDRB_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(DDRB_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTC:
        /*Check on direction*/
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            clr_bit(DDRC_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(DDRC_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTD:
        /*Check on direction*/
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            clr_bit(DDRD_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(DDRD_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
    return Local_StateIndecator;
}

/** Set the Pin Value **/
DIOStatus DIO_DIOStatus_SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on Port Id*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        /*Check on Value*/
        switch (Copy_u8Value)
        {
        case DIO_INPUT:
            clr_bit(PORTA_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(PORTA_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTB:
        /*Check on Value*/
        switch (Copy_u8Value)
        {
        case DIO_INPUT:
            clr_bit(PORTB_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(PORTB_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTC:
        /*Check on Value*/
        switch (Copy_u8Value)
        {
        case DIO_INPUT:
            clr_bit(PORTC_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            set_bit(PORTC_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTD:
        /*Check on Value*/
        switch (Copy_u8Value)
        {
        case DIO_LOW:
            clr_bit(PORTD_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_HIGH:
            set_bit(PORTD_Reg, Copy_u8PinId);
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
    return Local_StateIndecator;
}

/** Get Pin Value **/

DIOStatus DIO_DIOStatus_GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_u8ptr2value)
{
    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on The Port Id and then get the pin value*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        *Copy_u8ptr2value = get_bit(PINA_Reg, Copy_u8PinId);
        Local_StateIndecator = DIO_OK;
        break;
    case PORTB:
        *Copy_u8ptr2value = get_bit(PINB_Reg, Copy_u8PinId);
        Local_StateIndecator = DIO_OK;
        break;
    case PORTC:
        *Copy_u8ptr2value = get_bit(PINC_Reg, Copy_u8PinId);
        Local_StateIndecator = DIO_OK;
        break;
    case PORTD:
        *Copy_u8ptr2value = get_bit(PIND_Reg, Copy_u8PinId);
        Local_StateIndecator = DIO_OK;
        break;

    default:
        break;
    }
    return Local_StateIndecator;
}

/** Set the Port Direction **/
DIOStatus DIO_DIOStatus_SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on Port Id*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        /*Check on direction */
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            DDRA_Reg = 0x00;
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            DDRA_Reg = 0xFF;
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTB:
        /*Check on direction */
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            DDRB_Reg = 0x00;
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            DDRB_Reg = 0xFF;
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTC:
        /*Check on direction */
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            DDRC_Reg = 0x00;
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            DDRC_Reg = 0xFF;
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;
    case PORTD:
        /*Check on direction */
        switch (Copy_u8Direction)
        {
        case DIO_INPUT:
            DDRD_Reg = 0x00;
            Local_StateIndecator = DIO_OK;
            break;
        case DIO_OUTPUT:
            DDRD_Reg = 0xFF;
            Local_StateIndecator = DIO_OK;
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
    return Local_StateIndecator;
}

/** Set the Port Value **/
DIOStatus DIO_DIOStatus_SetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on Port Id*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        PORTA_Reg = Copy_u8Value;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTB:
        PORTB_Reg = Copy_u8Value;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTC:
        PORTC_Reg = Copy_u8Value;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTD:
        PORTD_Reg = Copy_u8Value;
        Local_StateIndecator = DIO_OK;
        break;

    default:
        break;
    }
    return Local_StateIndecator;
}

/** Get Port Value **/

DIOStatus DIO_DIOStatus_GetPortValue(u8 Copy_u8PortId, u8 *Copy_u8ptr2value)
{
    DIOStatus Local_StateIndecator = DIO_NOK;
    /*Check on Port Id*/
    switch (Copy_u8PortId)
    {
    case PORTA:
        *Copy_u8ptr2value = PINA_Reg;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTB:
        *Copy_u8ptr2value = PINB_Reg;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTC:
        *Copy_u8ptr2value = PINC_Reg;
        Local_StateIndecator = DIO_OK;
        break;

    case PORTD:
        *Copy_u8ptr2value = PIND_Reg;
        Local_StateIndecator = DIO_OK;
        break;
    }
    return Local_StateIndecator;
}

/***********************************************************************************************/
