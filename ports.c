#include "ports.h"
#include "hashs.h"


void Ports_clk_init (void)
{
    SYSCTL_REGCGC2_REG = PORTS_CLKS;   //    0000 1011
    while (!(SYSCTL_PRGPIO_REG & PORTS_CLKS));

}


void PortsUart_clk_init (void)
        {
    SYSCTL_RCGCUART_REG = UART_CLKS; //0000 1001
    while (!(SYSCTL_PRUART_REG & UART_CLKS));
        }





void system_init (void){
    PortsUart_clk_init();
    Ports_clk_init();
    Led_port_init();
    systick_init();
    UART2_Init();
    UART0_Init();
    LCD_init();
}
