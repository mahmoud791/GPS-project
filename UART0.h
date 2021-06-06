#ifndef UART0PROTO
#define UART0PROTO


#include <typedef.h>



void UART0_Init (void);
static void PORTA_UART_Init (void);
void UART0_SendData (sint8);
void UART0_SendStr (sint8*);
uint8 UART0_ReceiveData (void);
void UART0_ReceiveStr_len (uint8, sint8*);
void UART0_ReceiveStr_SpecialChar (uint8, sint8*);

#endif
