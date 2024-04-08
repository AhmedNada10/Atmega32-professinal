/*
 *	File Name: 		EXTI_program.c
 *
 *	Creation Date: 	Apr 8, 2024
 *
 *   Author: 		Ahmed Nada
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_registers.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*************************************************************************************************/

/*
 *
 *                                       Helper Functions                                        *
 *
 */

/* Set Interrupt Sense Control*/
static void EXTI0_voidSetSenseControl(void)
{
    switch (EXTI0_SenseControl)
    {
    case EXTI_LowLevel:
        /* code */
        clr_bit(MCUCR_EXTI_Reg, ISC01);
        clr_bit(MCUCR_EXTI_Reg, ISC00);
        break;
    case EXTI_AnyLogicalChange:
        /* code */
        clr_bit(MCUCR_EXTI_Reg, ISC01);
        set_bit(MCUCR_EXTI_Reg, ISC00);
        break;
    case EXTI_FallingEdge:
        /* code */
        set_bit(MCUCR_EXTI_Reg, ISC01);
        clr_bit(MCUCR_EXTI_Reg, ISC00);
        break;
    case EXTI_RisingEdge:
        /* code */
        set_bit(MCUCR_EXTI_Reg, ISC01);
        set_bit(MCUCR_EXTI_Reg, ISC00);
        break;

    default:
        break;
    }
}

static void EXTI1_voidSetSenseControl(void)
{
    switch (EXTI1_SenseControl)
    {
    case EXTI_LowLevel:
        /* code */
        clr_bit(MCUCR_EXTI_Reg, ISC11);
        clr_bit(MCUCR_EXTI_Reg, ISC10);
        break;
    case EXTI_AnyLogicalChange:
        /* code */
        clr_bit(MCUCR_EXTI_Reg, ISC11);
        set_bit(MCUCR_EXTI_Reg, ISC10);
        break;
    case EXTI_FallingEdge:
        /* code */
        set_bit(MCUCR_EXTI_Reg, ISC11);
        clr_bit(MCUCR_EXTI_Reg, ISC10);
        break;
    case EXTI_RisingEdge:
        /* code */
        set_bit(MCUCR_EXTI_Reg, ISC11);
        set_bit(MCUCR_EXTI_Reg, ISC10);
        break;

    default:
        break;
    }
}

static void EXTI2_voidSetSenseControl(void)
{
    /*EXTI2*/
    switch (EXTI2_SenseControl)
    {
    case EXTI_FallingEdge:
        clr_bit(MCUCSR_EXTI_Reg, ISC2);
        break;
    case EXTI_RisingEdge:
        set_bit(MCUCSR_EXTI_Reg, ISC2);
        break;
    default:
        break;
    }
}

/* enable GLobal Interrupt Enable */
static void EXTI_voidSREG(void)
{
    set_bit(SREG_EXTI_Reg, 7);
}

/* PIE  */
static void EXTI0_voidSetGICR(void)
{
    switch (EXTI0_PIE)
    {
    case EXTI_Disable:
        clr_bit(GICR_EXTI_Reg, INT0);
        break;

    case EXTI_Enable:
        set_bit(GICR_EXTI_Reg, INT0);
        break;

    default:
        break;
    }
}

static void EXTI1_voidSetGICR(void)
{

    switch (EXTI1_PIE)
    {
    case EXTI_Disable:
        clr_bit(GICR_EXTI_Reg, INT1);
        break;

    case EXTI_Enable:
        set_bit(GICR_EXTI_Reg, INT1);
        break;

    default:
        break;
    }
}

static void EXTI2_voidSetGICR(void)
{
    switch (EXTI2_PIE)
    {
    case EXTI_Disable:
        clr_bit(GICR_EXTI_Reg, INT2);
        break;

    case EXTI_Enable:
        set_bit(GICR_EXTI_Reg, INT2);
        break;

    default:
        break;
    }
}

/************************************************************************************************/

/*
 *
 *                                       Pointer To function of ISR                             *
 *
 */

static void (*PointerToISRFunction[3])(void) = {NULL};

/***********************************************************************************************/

/*
 *
 *                   Main Function Implementation                                                  *
 *
 */

EXTIStatus EXTI_EXTIStatusClearFlag(u8 Copy_u8InterruptId)
{
    EXTIStatus Local_ReturnStatus = EXTI_Nok;
    switch (Copy_u8InterruptId)
    {
    case EXTI0:
        set_bit(GIFR_EXTI_Reg, INTF0);
        Local_ReturnStatus = EXTI_Ok;
        break;
    case EXTI1:
        set_bit(GIFR_EXTI_Reg, INTF1);
        Local_ReturnStatus = EXTI_Ok;
        break;
    case EXTI2:
        set_bit(GIFR_EXTI_Reg, INTF2);
        Local_ReturnStatus = EXTI_Ok;
        break;

    default:
        break;
    }
    return Local_ReturnStatus;
}

EXTIStatus EXTI_EXTIStatusInit(u8 Copy_u8InterruptId)
{

    EXTIStatus Local_ReturnStatus = EXTI_Nok;
    /*Enable GIE*/
    EXTI_voidSREG();

    switch (Copy_u8InterruptId)
    {
    case EXTI0:
        /*Set Interrupt Sense Control */
        EXTI0_voidSetSenseControl();
        /*Enable PIE*/
        EXTI0_voidSetGICR();
        /*Clear the Flag*/
        EXTI_EXTIStatusClearFlag(EXTI0);
        Local_ReturnStatus = EXTI_Ok;
        break;
    case EXTI1:
        /*Set Interrupt Sense Control */
        EXTI1_voidSetSenseControl();
        /*Enable PIE*/
        EXTI1_voidSetGICR();
        /*Clear the Flag*/
        EXTI_EXTIStatusClearFlag(EXTI1);
        Local_ReturnStatus = EXTI_Ok;
        break;
    case EXTI2:
        /*Set Interrupt Sense Control */
        EXTI2_voidSetSenseControl();
        /*Enable PIE*/
        EXTI2_voidSetGICR();
        /*Clear the Flag*/
        EXTI_EXTIStatusClearFlag(EXTI2);
        Local_ReturnStatus = EXTI_Ok;
        break;

    default:
        break;
    }

    return Local_ReturnStatus;
}

/*User passes Function to be the ISR */
EXTIStatus EXTI_EXTIStatusSetISR(void (*Copy_u8Ptr2Func)(void), u8 Copy_u8InterruptId)
{

    EXTIStatus Local_ReturnValue = EXTI_Nok;
    if (Copy_u8Ptr2Func != NULL)
    {
        switch (Copy_u8InterruptId)
        {
        case EXTI0:
            PointerToISRFunction[0] = Copy_u8Ptr2Func;
            Local_ReturnValue = EXTI_Ok;
            break;
        case EXTI1:
            PointerToISRFunction[1] = Copy_u8Ptr2Func;
            Local_ReturnValue = EXTI_Ok;
            break;
        case EXTI2:
            PointerToISRFunction[2] = Copy_u8Ptr2Func;
            Local_ReturnValue = EXTI_Ok;
            break;

        default:
            break;
        }
    }
    return Local_ReturnValue;
}

/* ISR Implementation */

void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
    if (PointerToISRFunction[0] != NULL)
    {
        PointerToISRFunction[0]();
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (PointerToISRFunction[1] != NULL)
    {
        PointerToISRFunction[1]();
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (PointerToISRFunction[2] != NULL)
    {
        PointerToISRFunction[2]();
    }
}
