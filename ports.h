#ifndef CLKS

#define CLKS

#include "tm4c123gh6pm_registers.h"



#define UART_CLKS   0X05  //0000 0101
#define PORTS_CLKS  0X2B  //0010 1011

void Ports_clk_init (void);
void PortsUart_clk_init (void);
void system_init(void);

#endif
