#ifndef UART1PROTO
#define UART1PROTO


#include <typedef.h>



void UART1_Init (void);
void PORTB_UART_Init (void);
void UART1_SendData (sint8);
void UART1_SendStr (sint8*);
uint8 UART1_ReceiveData (void);
void UART1_ReceiveStr_len (uint8, sint8*);
void UART1_ReceiveStr_SpecialChar (uint8, sint8*);

#endif
