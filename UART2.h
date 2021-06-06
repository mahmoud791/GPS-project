#ifndef UART2PROTO
#define UART2PROTO


#include <typedef.h>



void UART2_Init (void);
void PORTD_UART_Init (void);
void UART2_SendData (sint8);
void UART2_SendStr (sint8*);
uint8 UART2_ReceiveData (void);
void UART2_ReceiveStr_len (uint8, sint8*);
void UART2_ReceiveStr_SpecialChar (uint8, sint8*);

#endif
