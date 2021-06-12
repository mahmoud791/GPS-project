#ifndef COMMON_MACROS
#define COMMON_MACROS

//MACROS definition used in project


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))                //Macro to set bit in register

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))                //Macro to clear bit in register

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))                //Macro to toggle bit in register

#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )                           //Macro to rotate right in register

#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )                           //Macro to rotate left in register

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )              //Macro to check if bit is set

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )              //Macro to check if bit is cleared

#endif
