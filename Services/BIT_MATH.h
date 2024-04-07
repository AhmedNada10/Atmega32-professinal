#ifndef BIT_MATH_H
#define BIT_MATH_H_

#define set_bit(Reg, Bit_Num) (Reg |= (1 << Bit_Num))
#define clr_bit(Reg, Bit_Num) (Reg &= ~(1 << Bit_Num))
#define get_bit(Reg, Bit_Num) ((Reg >> Bit_Num) & 1)
#define Tog_Bit(Reg, Bit_Num) (Reg ^= (1 << Bit_Num))

#endif
