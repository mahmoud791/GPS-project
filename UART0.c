#include <tm4c123gh6pm_registers.h>
#include <typedef.h>
#include <UART0.h>



void UART0_Init (void)
{
    SYSCTL_RCGCUART_REG |= (1<<0); //TURN UART CLOCK
    while (!(SYSCTL_PRUART_REG & 0X01)); // MAKE SURE UART CLOCK IS STABLE
    UART0_CTL_R &= ~(1<<0); // DISABLE UART
    PORTA_UART_Init(); //INIT PORTA
    UART0_IBRD_R = 104; // BAUD RATE = 9600 -> 16MHZ/16*9600 = 104.166666 SO IBRD = 104
    UART0_FBRD_R = 11;  // FBRD = (0.16666*64)+0.5 = 11
    UART0_LCRH_R = 0X0070; // 8 BIT TRANSFER DATA + 1 STOP BIT
    UART0_CTL_R = 0X0301;  // ENABLE UART, TX & RX
    UART0_CC_R = 0; // USE CLOCK OF SYSTEM
}


static void PORTA_UART_Init (void)
{
    SYSCTL_REGCGC2_REG |= (1<<0); //TURN PORTA CLOCK
    while (!(SYSCTL_PRGPIO_REG & 0X01)); // MAKE SURE PORTA CLOCK IS STABLE
    GPIO_PORTA_AFSEL_REG |=0X03; // ENABLE AF
    GPIO_PORTA_PCTL_REG |= 0X0011; // ENABLE UART
    GPIO_PORTA_DEN_REG |= 0X03; // ENABLE DIGITAL TRANSMISSION
    GPIO_PORTA_AMSEL_REG &= ~(0X03); // DISABLE ANALOG
}



void UART0_SendData (sint8 letter)
{
    while (UART0_FR_R & (1<<5)); // MAKE SURE FIFO IS NOT FULL
    UART0_DR_R = letter; //SEND CHAR
}


uint8 UART0_ReceiveData (void)
{
    while (UART0_FR_R & (1<<4)); // MAKE SURE FIFO IS EMPTY
    return UART0_DR_R;  //RECEIVE CHAR
}


void UART0_SendStr (sint8 *str)
{

    uint8 i=0;
    while (str[i] != '\0')
    {
        UART0_SendData(str[i]);
        i++;
    }
}


void UART0_ReceiveStr_len (uint8 len, sint8 *str)
{

    uint8 i;
    for (i = 0 ; i< len ; i++){
        str[i] = UART0_ReceiveData();
    }

    str[len] = '\0';

}

void UART0_ReceiveStr_SpecialChar (uint8 spec, sint8 *str)
{
    uint8 i=0;
    uint8 checker = UART0_ReceiveData();

    while (checker != spec){
        str[i] = checker;
        checker = UART0_ReceiveData();
        i++;
    }

    str[i] = '\0';



}
