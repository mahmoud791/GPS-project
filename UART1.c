#include <tm4c123gh6pm_registers.h>
#include <typedef.h>
#include <UART1.h>



void UART1_Init (void)
{
    SYSCTL_RCGCUART_REG |= (1<<1); //TURN UART CLOCK
    while (!(SYSCTL_PRUART_REG & 0X02)); // MAKE SURE UART CLOCK IS STABLE
    UART1_CTL_R &= ~(1<<0); // DISABLE UART
    PORTB_UART_Init(); //INIT PORTA
    UART1_IBRD_R = 104; // BAUD RATE = 9600 -> 16MHZ/16*9600 = 104.166666 SO IBRD = 104
    UART1_FBRD_R = 11;  // FBRD = (0.16666*64)+0.5 = 11
    UART1_LCRH_R = 0X0070; // 8 BIT TRANSFER DATA + 1 STOP BIT
    UART1_CTL_R = 0X0301;  // ENABLE UART, TX & RX
    UART1_CC_R = 0; // USE CLOCK OF SYSTEM
}


void PORTB_UART_Init (void)
{
    SYSCTL_REGCGC2_REG |= (1<<1); //TURN PORTB CLOCK
    while (!(SYSCTL_PRGPIO_REG & 0X02)); // MAKE SURE PORTA CLOCK IS STABLE
    GPIO_PORTB_AFSEL_REG |=0X03; // ENABLE AF
    GPIO_PORTB_PCTL_REG = 0X0011; // ENABLE UART
    GPIO_PORTB_DEN_REG |= 0X03; // ENABLE DIGITAL TRANSMISSION
    GPIO_PORTB_AMSEL_REG &= ~(0X03); // DISABLE ANALOG
}



void UART1_SendData (sint8 letter)
{
    while (UART1_FR_R & (1<<5)); // MAKE SURE FIFO IS NOT FULL
    UART1_DR_R = letter; //SEND CHAR
}


uint8 UART1_ReceiveData (void)
{
    while (UART1_FR_R & (1<<4)); // MAKE SURE FIFO IS EMPTY
    return UART1_DR_R;  //RECEIVE CHAR
}


void UART1_SendStr (sint8 *str)
{

    uint8 i=0;
    while (str[i] != '\0')
    {
        UART1_SendData(str[i]);
        i++;
    }
}


void UART1_ReceiveStr_len (uint8 len, sint8 *str)
{

    uint8 i;
    for (i = 0 ; i< len ; i++){
        str[i] = UART1_ReceiveData();
    }

    str[len] = '\0';

}

void UART1_ReceiveStr_SpecialChar (uint8 spec, sint8 *str)
{
    uint8 i=0;
    uint8 checker = UART1_ReceiveData();

    while (checker != spec){
        str[i] = checker;
        checker = UART1_ReceiveData();
        i++;
    }

    str[i] = '\0';

}
