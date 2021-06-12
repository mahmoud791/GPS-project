#ifndef COMMON_MACROS
#define COMMON_MACROS

//MACROS definition used in project


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif
